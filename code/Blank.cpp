#include "Blank.h"
#include "MoveObject.h"
#include "Robot.h"
#include "Guard.h"

//Blank::Blank()
//{
//}


//Blank::Blank(const sf::Vector2f & size, const sf::Vector2f & pos)
//{
//	m_rect.setSize(size);
//	m_rect.setPosition(pos);
//	m_rect.setFillColor(sf::Color::Magenta);
//}


Blank::~Blank()
{
}


void Blank::collide(Robot & robot)
{
	setPosition(robot, robot.getRect().getPosition());
}

bool Blank::collide(Guard & guard)
{
	setPosition(guard, guard.getRect().getPosition());
	return true;
}

void Blank::setPosition(MoveObject & mo, sf::Vector2f oPos)
{
	mo.getRect().setPosition(this->m_rect.getPosition());
	this->getRect().setPosition(oPos);
}
