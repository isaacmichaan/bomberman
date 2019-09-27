#pragma once
#include "StaticObject.h"
class Robot;
class Guard;

class Bomb : public StaticObject
{
public:
	//Bomb(); // constuctor
	using StaticObject::StaticObject;
	~Bomb(); // destructor
	
	virtual bool collide(Robot &, std::vector<std::unique_ptr <StaticObject> > &, int) {  return true;  } // colission between BOMB -> ROBOT
	virtual bool collide(Guard &) { return true; } // colission between BOMB -> GUARD
};

