#include "Guard.h"
#include "StaticObject.h"
#include<time.h>


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//Guard::Guard()
//{
//}


//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
Guard::~Guard()
{
}


//=========================================
//		Move							
//=========================================
//@Func. descr.: move guard
//@Params: std::vector<std::shared_ptr <MoveObject> > &, std::vector<std::shared_ptr <StaticObject> >&.
//@Return: non.
void Guard::move(std::vector<std::unique_ptr <MoveObject> > & mo, std::vector<std::unique_ptr <StaticObject> > & so)
{
	
	int num = (rand() % 13); // מחליף כיוון בממוצע אחת ל 13 פעמים 
	if (m_diraction == sf::Vector2f{ 0,0 } || num == 0) // בפעם הראשונה או כאשר מחליף כיוון 
	{

		
		num = (rand() % 4) + 1; // number between 1 and 4
		if (num == 1)
		{
			m_diraction = { -5,0 }; // קביעת הכיוון 
			//checkColission(mo, so, -5, 0); // the numbers are the next position in pixels
		}
		if (num == 2)
		{
			m_diraction = { 5,0 };//checkColission(mo, so, 5, 0);
		}
		if (num == 3)
		{
			m_diraction = { 0,-5 };// (mo, so, 0, -5);
		}
		if (num == 4)
		{
			m_diraction = { 0,5 }; // (mo, so, 0, 5);
		}
	}
	if (checkColission(mo, so, m_diraction.x, m_diraction.y))
		this->movement(m_diraction);
	else
		m_diraction = { 0,0 };

}


//=========================================
//		Check Colission							
//=========================================
//@Func. descr.: Check Colission
//@Params: std::vector<std::shared_ptr <MoveObject> >&, std::vector<std::shared_ptr <StaticObject> >&, float, float.
//@Return: non.
bool Guard::checkColission(std::vector<std::unique_ptr <MoveObject> > & mo, std::vector<std::unique_ptr <StaticObject> > & so, float LR, float UD)//missing mo collision
{
	bool blank = true;
	sf::RectangleShape newRect{ getRect() }; 
	newRect.move(LR, UD);
	for (auto& t_mo : mo)
	{
		if (this == t_mo.get()) continue;
		if (newRect.getGlobalBounds().intersects(t_mo->getGlobalBounds()))
		{
			blank = t_mo->collide(*this);
			break;
		}
	}
	for (const auto& t_so : so)
	{
		if (newRect.getGlobalBounds().intersects(t_so->getGlobalBounds()))
		{
			blank = t_so->collide(*this);
			break;
		}
	}
	return blank;
}