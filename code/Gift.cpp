#include "Gift.h"
#include "Robot.h"


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//Gift::Gift(const std::string & fileName, const sf::Vector2f & size, const sf::Vector2f & pos)
//{
//	if (texture.loadFromFile(fileName, sf::IntRect(0, 0, 0, 0)))
//	{
//		m_rect.setTexture(&texture);
//		m_rect.setSize(size);
//		m_rect.setPosition(pos);
//	}
//}


//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
Gift::~Gift()
{
}


////=========================================
////		Collide							
////=========================================
////@Func. descr.: collision between GIFT -> ROBOT
////@Params: Robot &, std::vector<std::shared_ptr <StaticObject> > &, int.
////@Return: bool.
//bool Gift::collide(Robot & robot, std::vector<std::shared_ptr <StaticObject> > & so, int i)
//{
//}