#pragma once
#include "StaticObject.h"
class MoveObject;
class Robot;
class Guard;

class Blank : public StaticObject
{
public:
	Blank();
	Blank(const sf::Vector2f &, const sf::Vector2f &);
	~Blank();
	virtual void draw(sf::RenderWindow & m_window) { m_window.draw(m_rect); }
	virtual void collide(Robot &);
	virtual void collide(Guard &);
	void setPosition(MoveObject &, sf::Vector2f oPos);
};

