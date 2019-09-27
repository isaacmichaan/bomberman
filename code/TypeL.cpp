#include "TypeL.h"



//TypeL::TypeL()
//{
//}


TypeL::~TypeL()
{
}

bool TypeL::collide(Robot &, std::vector<std::unique_ptr<StaticObject>>& so, int i)
{
	if (!DONOTENTER)
	{
		LIFE=1; // idea
		so.erase(so.begin() + i);
		NOS--; // decrease from number of static
	} return false;
}
