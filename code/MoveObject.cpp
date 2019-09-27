#include "MoveObject.h"


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//MoveObject::MoveObject()
//{
//}


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: const std::string &, const sf::Vector2f &, const sf::Vector2f &.
//@Return: non.
MoveObject::MoveObject(const std::string & fileName, const sf::Vector2f & size, const sf::Vector2f & pos) 
	:GameObject(fileName, size, pos),m_firstPos(pos)
{

}

//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
MoveObject::~MoveObject()
{
}
