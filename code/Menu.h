#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:

	Menu();
	bool newGame(sf::RenderWindow &m_window);
private:
	int m_buttNum = 0;
	sf::Texture texture;
	sf::RectangleShape m_rect;
	sf::CircleShape m_buttons[3];
	sf::Vector2f m_windowSize{ 1280 , 720 };
	void showHelp() const;
};

