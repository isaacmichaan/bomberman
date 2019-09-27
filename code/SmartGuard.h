#pragma once
#include "MoveObject.h"
#include "Guard.h"
class StaticObject;
class Robot;
//class Guard;


class SmartGuard : public Guard
{
public:
	//SmartGuard(); // constuctor
	using Guard::Guard; // using MoveObject() constructor
	~SmartGuard();  // destructor
	void move(std::vector<std::unique_ptr <MoveObject> > &, std::vector<std::unique_ptr <StaticObject> >&); // move Guard
};