#include "GameObject.h"


//=========================================
//		Constructor							
//=========================================
//@Func. descr.: Constructor
//@Params: non.
//@Return: non.
//GameObject::GameObject()
//{
//}


GameObject::GameObject(const std::string & fileName, const sf::Vector2f & size, const sf::Vector2f & pos)
{
	if (texture.loadFromFile(fileName, sf::IntRect(0, 0, 0, 0)))
   {
	   m_rect.setTexture(&texture);
	   m_rect.setSize(size);
	   m_rect.setPosition(pos);
   }
}

//=========================================
//		Destructor							
//=========================================
//@Func. descr.: Destructor
//@Params: non.
//@Return: non.
GameObject::~GameObject()
{
}

//=============================================
//
//==============================================
void GameObject::draw(sf::RenderWindow &win)
{
	win.draw(m_rect);
}

//=============================================
//
//==============================================
float GameObject::manhattanDistance(const sf::Vector2f & other) const
{
	return abs(m_rect.getPosition().x - other.x) + abs(m_rect.getPosition().y - other.y);
}

//=============================================
//
//==============================================
sf::Vector2f GameObject::getPosition() const
{
	return m_rect.getPosition();
}

//=============================================
//
//==============================================
sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_rect.getGlobalBounds();
}

//=============================================
//
//==============================================
void GameObject::setPosition(sf::Vector2f & pos)
{
	m_rect.setPosition(pos);
}

//=============================================
//
//==============================================
void GameObject::movement(const sf::Vector2f & movementa)
{
	m_rect.move(movementa);
}
