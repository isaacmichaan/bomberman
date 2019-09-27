#pragma once
#include "StaticObject.h"
class Robot;

class Gift : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual ~Gift() = 0; // destructor
	virtual bool collide(Guard & guard) { return true; }
};