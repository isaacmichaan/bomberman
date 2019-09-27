#pragma once

#include "GameObject.h"
class Robot;
class Guard;

class StaticObject : public GameObject
{
public:
	//StaticObject(); // constuctor
	StaticObject(const std::string &, const sf::Vector2f &, const sf::Vector2f &); // constuctor
	virtual ~StaticObject() = 0; // destructor
	virtual bool collide(Robot & robot, std::vector<std::unique_ptr <StaticObject> > & so, int i) { return false; } // only because I am not making virtual
	virtual bool collide(Guard & guard) { return false; } // only because I am not making virtual
};

