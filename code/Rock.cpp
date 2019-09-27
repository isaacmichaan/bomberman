#include "Rock.h"
#include "Robot.h"
#include "TypeL.h"
#include "TypeB.h"
#include "TypeK.h"


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//Rock::Rock()
//{
//}


//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
Rock::~Rock()
{
}


//=========================================
//		Collide							
//=========================================
//@Func. descr.: collision between ROCK -> ROBOT
//@Params: Robot &, std::vector<std::shared_ptr <StaticObject> > &, int.
//@Return: bool.
bool Rock::collide(Robot & robot, std::vector<std::unique_ptr <StaticObject> > & so, int i)
{
	if (DONOTENTER)
	{
		static int rockE = 0; // how many rocks were exploded
		sf::Vector2f pos = so[i]->getRect().getPosition(); // hold position of rock
		so.erase(so.begin() + i);
		if (rockE == 5 - 1) // if exploded five, reward with a hiden present :)
		{
			int num = (rand() % 3) + 1;
			if(num == 1)
				so.insert(so.begin() + i, std::make_unique < TypeL >("typel.png", sf::Vector2f(50, 50), pos));
			if (num == 2)
				so.insert(so.begin() + i, std::make_unique < TypeB >("typeb.png", sf::Vector2f(50, 50), pos));
			if (num == 3)
				so.insert(so.begin() + i, std::make_unique < TypeK >("typed.png", sf::Vector2f(50, 50), pos));
			rockE = 0;
		}
		else
		{
			NOS--;
			rockE++;
		}
	} return false;
}