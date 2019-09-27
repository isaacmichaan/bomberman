#pragma once
#include "Gift.h"
class Robot;

class TypeK : public Gift
{
public:
	using Gift::Gift; // using Gift() constructor
	~TypeK(); // destructor
	//virtual void draw(sf::RenderWindow & m_window) { m_window.draw(m_rect); } // draw to SFML windows 
	virtual bool collide(Robot &, std::vector<std::unique_ptr <StaticObject> > &, int); // colission between GIFT -> ROBOT
};

