#pragma once
#include "StaticObject.h"
class Robot;

class Rock : public StaticObject
{
public:
	//Rock(); // constuctor
	using StaticObject::StaticObject; // using StaticObject() constructor
	~Rock(); // destructor
	virtual bool collide(Robot &, std::vector<std::unique_ptr <StaticObject> > &, int); // colission between ROCK -> ROBOT
};
