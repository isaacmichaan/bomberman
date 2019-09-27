#include "Controller.h"

#include <windows.h>
#include <time.h>
#include <iostream>
#include <sstream>


void Controller::betweenLevel()
{
	m_info->addScore(NUMOFGUARDS * 20);
}

//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
Controller::Controller()
{
	m_window.create(sf::VideoMode(1280, 720), "Bomberman");
	srand((unsigned int)time(NULL));
}


//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
Controller::~Controller()
{
}

//=========================================
//		Run Game							
//=========================================
//@Func. descr.: start game
//@Params: non.
//@Return: non.
void Controller::runGame()
{
	
	while (m_menu.newGame(m_window))
	{
	
		startAndEnd(0);
		setLevel();
		m_info = std::make_unique<InfoBar>(sf::Vector2f{ 0,0 }, sf::Vector2f{ (float)COLS,80.f });
		//m_board = std::make_unique < Board >(); // create pointer to Board
	

		newLevel();
		runWindow(); // run SFML windows
	}
}
//=========================================
//		New Level							
//=========================================
//@Func. descr.: start new level
//@Params: non.
//@Return: non.
void Controller::newLevel()
{
	
	if (LEVEL >= m_levels.size()) // idea
	{
		T = false; // idea
		startAndEnd(1);
	}

	m_mo.clear();
	m_so.clear(); // clear vectors
	m_board = std::make_unique < Board >();
	
	m_board->setData(m_levels[LEVEL]);
	m_info->setNewLevel();
	
	m_window.create(sf::VideoMode(COLS * ICONSIZE, ROWS * ICONSIZE + 80), "Bomberman");
	m_window.setFramerateLimit(30);
	m_info->setSize(sf::Vector2f{(float) COLS * ICONSIZE,80.f });
	m_board->insertBoard(m_mo, m_so);

	initiate_NOS();
	//ifs.close();
	//NUMOFBOMBS = 10;
	NEWLEVEL = false;
}

//===============================================
//
//===============================================
void Controller::startAndEnd(int f)
{
	sf::RectangleShape rect; // hold object rect
	sf::Texture texture; // hold object texture
	if (f == 0)
	{
		if (texture.loadFromFile("bom4.jpg"))
		{
			rect.setTexture(&texture);
			rect.setSize(sf::Vector2f(1280,720));
			m_window.clear();
			m_window.draw(rect);
			m_window.display();
			Sleep(3);
		}
	}
	if(f == 1)
	{
		if (texture.loadFromFile("end.jpg"))
		{
			rect.setTexture(&texture);
			rect.setSize(sf::Vector2f(1280,720));
			m_window.clear();
			m_window.draw(rect);
			m_window.display();
			Sleep(3000);
		}
	}
	else if(f == -1)
	{
		if (texture.loadFromFile("gameover.jpg"))
		{
			rect.setTexture(&texture);
			rect.setSize(sf::Vector2f(1280, 720));
			
			sf::Clock clock;

			while (int(clock.getElapsedTime().asSeconds()) < 2)
			{
				m_window.clear();
				m_window.draw(rect);
				m_window.display();
			}
		}
	}
}

//===============================================
//
//===============================================
void Controller::setLevel()
{
	T = true;
	SCORE = LEVEL = 0;
	 
	m_levels.clear();
	ifs.open("Levels.txt");
	std::string level;
	while (getline(ifs, level))
	{
		m_levels.push_back(level);
	}
	ifs.close();
}


//=========================================
//		Run Window							
//=========================================
//@Func. descr.: run SFML windows
//@Params: non.
//@Return: non.
void Controller::runWindow()
{
	SetTimer(NULL, 0, 20, (TIMERPROC)&timerG); // timer to move guards
	while (m_window.isOpen() && T)
	{
		pollEvent();
		if (MOVEG)
			moveGuard();
		infoBar(); // idea
		if (RESTART)
			restart();
		if (RESTART_OBJ)
			restartMoveObj();
		if (NEWLEVEL)
		{
			betweenLevel();
			newLevel();
		}
		objectBoard();
	}

}


//=========================================
//		Poll Event							
//=========================================
//@Func. descr.: take care of events
//@Params: non.
//@Return: non.
void Controller::pollEvent()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case  sf::Event::Closed:
			m_window.close();
			break;

		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				RESTART = true;
				break;
			}
			m_mo[0]->move(m_mo, m_so);
			break;
		}
	}
}


//=========================================
//		Move Guard							
//=========================================
//@Func. descr.: move guards
//@Params: non.
//@Return: non.
void Controller::moveGuard()
{
	for (auto& mo : m_mo)
		if (MOVEG)
			mo->move(m_mo, m_so);
	MOVEG = 0;
}


//=========================================
//		Restart						
//=========================================
//@Func. descr.: restart level
//@Params: non.
//@Return: non.
void Controller::restart()
{
	m_mo.clear(); 
	m_so.clear(); // clear vectors
	
	m_board->insertBoard(m_mo, m_so);
	
	m_info->setNewLevel(-1);
	initiate_NOS();
	
	//NUMOFBOMBS = 10;
	RESTART = false;
}

//===============================================
// restart move objects - return first place
//===============================================
void Controller::restartMoveObj()
{
	for (auto& mo : m_mo)mo->firstPlace();
	m_info->addLife(-1);
	RESTART_OBJ = false;
}

//=========================================
//		Object Board							
//=========================================
//@Func. descr.: print to SFML windows
//@Params: non.
//@Return: non.
void Controller::objectBoard()
{
	m_window.clear(sf::Color::Blue);
	m_info->draw(m_window);
	for (auto& so : m_so) so->draw(m_window);
	for (auto& mo : m_mo) mo->draw(m_window);
	m_window.display();
}

//===============================================
//
//===============================================
void Controller::infoBar() // idea
{
	if(LIFE < -1) /////////////////////add
		LIFE = -1; /////////////add
	//m_board->updateInfoBar(LIFE, SCORE); 
	m_info->addLife(LIFE);
	m_info->addScore(NUMOFGUARDS * 5 * SCORE); 
	//if (NEWLEVEL) m_score += 20 * guards;);
	if (m_info->getLife() <= 0)
	{
		T = false;
		startAndEnd(-1);
	}
	LIFE = SCORE = 0;
}
