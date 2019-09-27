#pragma once
#include "MoveObject.h"
class StaticObject;
class Guard;

class Robot : public MoveObject
{
private:
	struct MyStruct
	{
		std::vector <int> m_bombT; // hold bomb time
		std::vector <sf::Vector2f> m_bombP; // hold bomb position
		std::vector <int> m_explosionT; // hold bomb explosion time to disappear
	};
	MyStruct m_bomb; // struct
public:
	//Robot(); // constuctor
	using MoveObject::MoveObject; // using MoveObject() constructor
	~Robot(); // destructor
	virtual void move(std::vector<std::unique_ptr <MoveObject> > &, std::vector<std::unique_ptr <StaticObject> >&); // move Robot
	bool checkColission(std::vector<std::unique_ptr <MoveObject> >&, std::vector<std::unique_ptr <StaticObject> >&,
		float, float); // check Colission with MoveObject && StaticObject
	void handleBomb(std::vector<std::unique_ptr <MoveObject> > &, std::vector<std::unique_ptr <StaticObject> > &); // if B was pressed
	void handleTime(std::vector<std::unique_ptr <MoveObject> > &mo, std::vector<std::unique_ptr <StaticObject> > &so); // time of bomb
	virtual bool collide(Guard &) {RESTART_OBJ = true; return false; }  // colission between ROBOT -> GUARD // idea
	void explodeCollision(Robot & robot, std::unique_ptr<StaticObject> & explosion, std::vector<std::unique_ptr <MoveObject> > & mo,
		std::vector<std::unique_ptr <StaticObject> > &so); // check if an Object was exploded
};

