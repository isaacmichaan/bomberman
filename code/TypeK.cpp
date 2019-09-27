#include "TypeK.h"



//TypeD::TypeK()
//{
//}


TypeK::~TypeK()
{
}

bool TypeK::collide(Robot &, std::vector<std::unique_ptr<StaticObject>>& so, int i)
{
	if (!DONOTENTER)
	{
		LIFE = 0; // idea
		so.erase(so.begin() + i);
		NOS--; // decrease from number of static
	} return false;
}
