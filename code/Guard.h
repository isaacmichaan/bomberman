#pragma once
#include "MoveObject.h"
class StaticObject;
class Robot;

class Guard : public MoveObject
{
protected:
	sf::Vector2f m_diraction = { 0,0 };
public:
	//Guard(); // constuctor
	using MoveObject::MoveObject; // using MoveObject() constructor
	~Guard(); // destructor
	virtual void move(std::vector<std::unique_ptr <MoveObject> > &, std::vector<std::unique_ptr <StaticObject> >&); // move Guard
	bool checkColission(std::vector<std::unique_ptr <MoveObject> >&, std::vector<std::unique_ptr <StaticObject> >&,
		float, float); // check Colission with MoveObject && StaticObject
	virtual bool collide(Robot &) { RESTART_OBJ = true; return false; } // colission between GUARD -> ROBOT // idea
};

