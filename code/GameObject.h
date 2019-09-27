#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Utilities.h"

class GameObject
{
protected:
	sf::RectangleShape m_rect; // hold object rect
	sf::Texture texture; // hold object texture
public:
	GameObject(const std::string &, const sf::Vector2f &, const sf::Vector2f &); // constuctor
	virtual ~GameObject() = 0; // destructor
	sf::RectangleShape getRect() const { return m_rect; } // return rect of object
	void draw(sf::RenderWindow &);// = 0 // draw to SFML windows 
	float manhattanDistance(const sf::Vector2f &other) const;
	sf::Vector2f getPosition() const;
	sf::FloatRect getGlobalBounds() const;
	void setPosition(sf::Vector2f &pos);
	void movement(const sf::Vector2f &movementa);
};