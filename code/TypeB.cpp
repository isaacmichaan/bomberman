#include "TypeB.h"



//TypeB::TypeB()
//{
//}


TypeB::~TypeB()
{
}

bool TypeB::collide(Robot &, std::vector<std::unique_ptr<StaticObject>>& so, int i)
{
	if (!DONOTENTER)
	{
		BOMB_LIM++;      //NUMOFBOMBS++; // idea
		so.erase(so.begin() + i);
		NOS--; // decrease from number of static
	} return false;
}
