#include "StaticObject.h"



//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//StaticObject::StaticObject()
//{
//}


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: const std::string &, const sf::Vector2f &, const sf::Vector2f &.
//@Return: non.
StaticObject::StaticObject(const std::string & fileName, const sf::Vector2f & size, const sf::Vector2f & pos)
	:GameObject(fileName, size, pos)
{
}


//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
StaticObject::~StaticObject()
{
}
