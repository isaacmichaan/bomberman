#pragma once

//include section
#include <string>
#include "GameObject.h"
#include "Bomb.h"
//class MoveObject;
class StaticObject;
class Robot;
class Guard;

class MoveObject : public GameObject
{
public:
	//MoveObject(); // constuctor
	MoveObject(const std::string &, const sf::Vector2f &, const sf::Vector2f &); // constuctor
	virtual ~MoveObject() = 0; // destructor
	virtual void move(std::vector<std::unique_ptr <MoveObject> >&, std::vector<std::unique_ptr <StaticObject> >&) = 0; // virtual move
	
	virtual bool collide(Robot & robot) { return false; } // only because I am not making virtual
	virtual bool collide(Guard & guard) { return false; } // only because I am not making virtual

	void firstPlace() { setPosition(m_firstPos); }
private:
	sf::Vector2f m_firstPos;
};

