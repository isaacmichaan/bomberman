#pragma once
#include "StaticObject.h"
class Robot;

class Door : public StaticObject
{
public:
	//Door(); // constructor
	using StaticObject::StaticObject; // using StaticObject() constructor
	~Door(); // destructor
	virtual void draw(sf::RenderWindow & m_window) { m_window.draw(m_rect); } // SFML windows
	virtual bool collide(Robot &, std::vector<std::unique_ptr <StaticObject> > &, int) {  NEWLEVEL = true; return false;  } // colission between DOOR -> ROBOT
};
