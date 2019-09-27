#include "Board.h"
#include "Robot.h"
#include "Guard.h"
#include "SmartGuard.h"
#include "Rock.h"
#include "Wall.h"
#include "Door.h"
#include "TypeL.h"
#include "TypeB.h"
#include "TypeK.h"
#include <sstream>
#include <fstream>


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
Board::Board()
{
}

//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
Board::~Board()
{
}

//==================================================
// set Data - 
// gets path to file of level
//==================================================
void Board::setData(std::string levelPath)
{
	LEVEL++;
	std::ifstream str(levelPath);
	std::string line; //הגדרת שורה
	getline(str, line); // gets first line
	std::istringstream iss; // המרה מסטרינג למספר 
	iss.str(line);
	iss >> ROWS >> COLS >> TIME_LIM >> BOMB_LIM; // set information 
	for (int i = 0; i < ROWS; i++) // save board as string
	{
		getline(str, line);
		m_toLevel.push_back(line);
	}
}

//=========================================
// get char (bydefault robot) 
// return the place in matrix 
// return the place in matrix 
//=========================================
sf::Vector2i Board::getRobotPls(const char c) const
{
	for (int i = 0; i < m_toLevel.size(); i++)
		for (int j = 0; j < m_toLevel[i].size(); j++)
			if (m_toLevel[i][j] == c)
				return{ j,i };
	return { ROWS + 1,COLS + 1 };
}

//=========================================
//		Insert Board							
//=========================================
//@Func. descr.: Insert Objects to Board
//@Params: std::vector<std::shared_ptr <MoveObject> >, std::vector<std::shared_ptr <StaticObject> >
//@Return: non.
void Board::insertBoard(std::vector<std::unique_ptr <MoveObject> > & m_mo,
	std::vector<std::unique_ptr <StaticObject> > & m_so)
{
	int num;
	char c; // hold one char of is
	float x = 0, y = 80; //start board in position {50, 80}
	auto rp = getRobotPls();
	m_mo.push_back(std::make_unique < Robot >("robot.png", sf::Vector2f(ICONSIZE, ICONSIZE),
		sf::Vector2f((float)rp.x*ICONSIZE, (float)rp.y*ICONSIZE + 80)));
	for (int i = 0; i < ROWS; i++, x = 0, y += ICONSIZE)
		for (int j = 0; j < COLS; j++, x += ICONSIZE)
		{
			c = m_toLevel[i][j];

			switch (c)
			{
			case '!':
				num = (rand() % 4 );
				if (num == 0)
					m_mo.push_back(std::make_unique < SmartGuard >("smartguard.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
				else
					m_mo.push_back(std::make_unique < Guard >("guard.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
				break;
			case '+':
				num = (rand() % 3);
				if (num == 0)
					m_so.push_back(std::make_unique < TypeB >("Gift.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
				else
					m_so.push_back(std::make_unique < TypeL >("Gift1.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
				break;
			case '@':
				m_so.push_back(std::make_unique < Rock >("rock.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
				break;
			case '#':
				m_so.push_back(std::make_unique < Wall >("wall.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
				break;
			case 'D':
				m_so.push_back(std::make_unique < Door >("door.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
				break;
		//	case 'L':
			//	m_so.push_back(std::make_unique < TypeL >("typel.png", sf::Vector2f(ICONSIZE, ICONSIZE), sf::Vector2f(x, y)));
			//	break;
					default:
				break;
			}
		}
}