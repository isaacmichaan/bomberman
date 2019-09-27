#include "Robot.h"
#include "StaticObject.h"
//#include <windows.h>
//#include <algorithm>


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//Robot::Robot()
//{
//}


//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
Robot::~Robot()
{
}


//=========================================
//		Move							
//=========================================
//@Func. descr.: move guard
//@Params: std::vector<std::shared_ptr <MoveObject> > &, std::vector<std::shared_ptr <StaticObject> >&.
//@Return: non.
void Robot::move(std::vector<std::unique_ptr <MoveObject> > &mo, std::vector<std::unique_ptr <StaticObject> > &so)
{
	sf::Vector2f m_diraction = { 0,0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_diraction = { -5,0 }; // the numbers are the next position in pixels
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_diraction = { 5,0 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_diraction = { 0,-5 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_diraction = { 0,5 };
	}
	if (m_diraction != sf::Vector2f{ 0,0 })
	{
		if (checkColission(mo, so, m_diraction.x, m_diraction.y))
			this->movement(m_diraction);
	}
	else
		handleBomb(mo, so);
}


//=========================================
//		Check Colission							
//=========================================
//@Func. descr.: Check Colission
//@Params: std::vector<std::shared_ptr <MoveObject> >&, std::vector<std::shared_ptr <StaticObject> >&, float, float.
//@Return: non.
bool Robot::checkColission(std::vector<std::unique_ptr <MoveObject> > &mo,std::vector<std::unique_ptr <StaticObject> > &so, float LR, float UD)
{
	bool blank = true;
	sf::RectangleShape newRect{ getRect() };
	newRect.move(LR, UD);
	for (auto& t_mo : mo)
	{
		if (this == t_mo.get())  continue;
		if (newRect.getGlobalBounds().intersects(t_mo->getGlobalBounds()))
		{
			blank = t_mo->collide(*this);
			break;
		}
	}

	int i = 0;
	for (const auto& t_so : so)
	{
		if (newRect.getGlobalBounds().intersects(t_so->getGlobalBounds()))
		{
			DONOTENTER = false;
			blank = t_so->collide(*this, so, i);
			DONOTENTER = true;
			break;
		}i++;
	}
	return blank;
		
}


//=========================================
//		Handle Bomb							
//=========================================
//@Func. descr.: Handle Bomb
//@Params: std::vector<std::shared_ptr <MoveObject> >&, std::vector<std::shared_ptr <StaticObject> >&.
//@Return: non.
void Robot::handleBomb(std::vector<std::unique_ptr <MoveObject> > &mo, std::vector<std::unique_ptr <StaticObject> > &so)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && (WAITB == 1) && BOMB_LIM!=0)
	{
		so.push_back(std::make_unique < Bomb >("bomb.png", sf::Vector2f(50, 50), mo[0]->getRect().getPosition()));
		m_bomb.m_bombP.push_back(mo[0]->getRect().getPosition()); // bomb position
		m_bomb.m_bombT.push_back(7*7); // timer of bomb
		m_bomb.m_explosionT.push_back(7*8); // timer of explosion to show
		WAITB++;
		BOMB_LIM--;
	} 
	handleTime(mo, so);
	
	if(WAITB != 1)
		WAITB++;
	if(WAITB == 12)
		WAITB = 1;

	if ( RESTART || NEWLEVEL) // clear vectors
	{
		m_bomb.m_bombP.clear();
		m_bomb.m_bombT.clear();
		m_bomb.m_explosionT.clear();
	}
}


//=========================================
//		Handle Time							
//=========================================
//@Func. descr.: Handle Time
//@Params: std::vector<std::shared_ptr <MoveObject> >&, std::vector<std::shared_ptr <StaticObject> >&.
//@Return: non.
void Robot::handleTime(std::vector<std::unique_ptr <MoveObject> > &mo, std::vector<std::unique_ptr <StaticObject> > &so)
{
	int size = so.size();
	for (auto& time : m_bomb.m_explosionT) // explosion timer
	{
		time--;
		if (time == 0) // when timer gets to 0
		{
			if (!(NOS + 5 >= size))
			{
				so.erase(so.begin() + NOS + 1);
				so.erase(so.begin() + NOS + 1);
				so.erase(so.begin() + NOS + 1);
				so.erase(so.begin() + NOS + 1);
				so.erase(so.begin() + NOS + 1); // erase all explosions
				m_bomb.m_explosionT.erase(m_bomb.m_explosionT.begin()); // clear the timer in m_explosionT[0]
			}
		}
	}
	for (auto& time : m_bomb.m_bombT) // bomb timer
	{
		time--;
		if (time == 0) // when timer gets to 0
		{
			if (!(NOS + 1 >= size))
			{
				so.erase(so.begin() + NOS + 1);
				so.insert(so.begin() + NOS + 1, std::make_unique < Bomb >("explosion.png", sf::Vector2f(50, 50), m_bomb.m_bombP[0]));
				explodeCollision(*this, so[NOS + 1], mo, so);
				so.insert(so.begin() + NOS + 2, std::make_unique < Bomb >("explosion.png", sf::Vector2f(50, 50), sf::Vector2f(m_bomb.m_bombP[0].x - 50, m_bomb.m_bombP[0].y)));
				explodeCollision(*this, so[NOS + 2], mo, so);
				so.insert(so.begin() + NOS + 3, std::make_unique < Bomb >("explosion.png", sf::Vector2f(50, 50), sf::Vector2f(m_bomb.m_bombP[0].x + 50, m_bomb.m_bombP[0].y)));
				explodeCollision(*this, so[NOS + 3], mo, so);
				so.insert(so.begin() + NOS + 4, std::make_unique < Bomb >("explosion.png", sf::Vector2f(50, 50), sf::Vector2f(m_bomb.m_bombP[0].x, m_bomb.m_bombP[0].y - 50)));
				explodeCollision(*this, so[NOS + 4], mo, so);
				so.insert(so.begin() + NOS + 5, std::make_unique < Bomb >("explosion.png", sf::Vector2f(50, 50), sf::Vector2f(m_bomb.m_bombP[0].x, m_bomb.m_bombP[0].y + 50)));
				explodeCollision(*this, so[NOS + 5], mo, so);
				m_bomb.m_bombP.erase(m_bomb.m_bombP.begin()); // clear the position in m_bombP[0]
				m_bomb.m_bombT.erase(m_bomb.m_bombT.begin()); // clear the timer in m_bombT[0]
			}
		}
	}
}


//=========================================
//		Explode Collision							
//=========================================
//@Func. descr.: check if explosion colide with some object
//@Params: Robot & robot, std::shared_ptr<StaticObject> & explosion, std::vector<std::shared_ptr <MoveObject> > & mo,
// std::vector<std::shared_ptr <StaticObject> > &so.
//@Return: non.
void Robot::explodeCollision(Robot & robot, std::unique_ptr<StaticObject> & explode, std::vector<std::unique_ptr <MoveObject> > & mo,
	std::vector<std::unique_ptr <StaticObject> > &so)
{
	int i = 0;
	for (const auto& t_mo : mo)
	{
		if (explode->getRect().getGlobalBounds().intersects(t_mo->getRect().getGlobalBounds())
			&& explode->getRect().getGlobalBounds().intersects(robot.getRect().getGlobalBounds()))
		{
			//LIFE--; // idea
			RESTART_OBJ = true;
		}
		if(explode->getRect().getGlobalBounds().intersects(t_mo->getRect().getGlobalBounds()) 
			&& !explode->getRect().getGlobalBounds().intersects(robot.getRect().getGlobalBounds()))
		{
			SCORE++; // idea
			mo.erase(mo.begin() + i);
			MOVEG = 0;
			break;
		} i++;
	} 
	
	i = 0;
	for (const auto& t_so : so)
	{
		if (i <= NOS && explode->getRect().getGlobalBounds().intersects(t_so->getRect().getGlobalBounds()))
		{
			t_so->collide(*this, so, i);
			break;
		} i++;
	}
}