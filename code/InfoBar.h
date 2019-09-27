#pragma once

#include "Utilities.h"
#include <SFML/Graphics.hpp>

class InfoBar
{
public:
	InfoBar(sf::Vector2f pos, sf::Vector2f size);// c-tor
	void addLife(int life) { m_life += life; } // add life by default life-- // changed the -1 // idea
	void addScore(int score) { m_score += score; } // idea
	int getLife() const { return m_life; } // idea
	void setNewLevel(int life = 0);
	void draw(sf::RenderWindow& win);
	void setSize(sf::Vector2f size) { m_infoBar.setSize(size); }
	~InfoBar();
private:

	int m_life = 3;
	int m_bomb;
	int m_level;
	int m_score = 0; // idea

	bool m_timed = false; // in case no time limit

	sf::RectangleShape m_infoBar;
	sf::Time m_timeLimit; // timer og the game/level
	sf::Clock m_clock; // clock of the game/level
	sf::Font m_font;

	 
	
};

