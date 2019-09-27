
#include "SmartGuard.h"
#include "StaticObject.h"
#include<time.h>


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//SmartGuard::SmartGuard()
//{
//}

//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
SmartGuard::~SmartGuard()
{
}






//=========================================
//		Move							
//=========================================
//@Func. descr.: move guard
//@Params: std::vector<std::shared_ptr <MoveObject> > &, std::vector<std::shared_ptr <StaticObject> >&.
//@Return: non.
void SmartGuard::move(std::vector<std::unique_ptr <MoveObject> > & mo, std::vector<std::unique_ptr <StaticObject> > & so)
{
	/*if (m_diraction != sf::Vector2f{ 0,0 } && checkColission(mo, so, m_diraction.x, m_diraction.y))
	{
		this->getRect().move(m_diraction);
		return;
	}*/
	sf::Vector2f p, next = { 0,0 };
	int i = 0;
	float dist, min = ROWS * COLS*ICONSIZE*ICONSIZE;
	do
	{
		if (i==3)
			p = { -5,0 };
		if (i == 2)
			p = { 5,0 };
		if (i == 1)	
			p = { 0,-5 };
		if (i == 0)
			p = { 0,5 };
		dist = mo[0]->manhattanDistance(getPosition() + p);
		if (checkColission(mo, so, p.x, p.y) && (dist  < min))
		{
			min = dist;
			next = p;
		}
		i++;
	} while (i < 4);
	if (next != sf::Vector2f{ 0,0 } && checkColission(mo, so, next.x, next.y))
	{
		m_diraction = next;
		this->movement(next);
	}


	////srand((unsigned int)time(NULL));
	//sf::FloatRect guardPos = getRect().getGlobalBounds();// get guard pos
	//sf::FloatRect robotPos = mo[0]->getRect().getGlobalBounds(); // get robot pos

	//if (guardPos.top > robotPos.top)
	//{
	//	if (guardPos.left > robotPos.left)
	//		m_diraction = { -3.5, -3.5 };//move up & left
	//	else
	//		m_diraction = { 3.5, -3.5 }; //move up & right
	//}
	//else
	//{
	//	if (guardPos.left > robotPos.left)
	//		m_diraction = { -3.5, 3.5 }; //move doun & left
	//	else
	//		m_diraction = { 3.5, 3.5 }; //move doun & right
	//}
	//
	//if(checkColission(mo, so, m_diraction.x, m_diraction.y))
	//	this->m_rect.move(m_diraction);


	
}
