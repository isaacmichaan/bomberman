#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	//Wall();
	using StaticObject::StaticObject; // using StaticObject() constructor
	~Wall(); // destructor
	//virtual void draw(sf::RenderWindow & m_window) { m_window.draw(m_rect); } // draw to SFML windows 
};