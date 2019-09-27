#include "Menu.h"

Menu::Menu()
{
	
	
	if (texture.loadFromFile("bom4.jpg"))
	{
		m_rect.setTexture(&texture);
		m_rect.setPosition(sf::Vector2f{ 0,0 });
		m_rect.setSize(sf::Vector2f(1280, 720));
	}
	
	for (int index = 0; index < 3; index++)
	{
		//m_buttons[index].setTexture(m_image[index]);
		//m_buttons[index].setScale()
		m_buttons[index].setRadius(70.f);
		m_buttons[index].setOutlineColor(sf::Color::Yellow);
		m_buttons[index].setFillColor(sf::Color::Transparent);
	}

	m_buttons[0].setPosition(sf::Vector2f{ 957,453 });
	m_buttons[1].setPosition(sf::Vector2f{ 653, 452 });
	m_buttons[2].setPosition(sf::Vector2f{ 348,453 });

}

////////////////////////////////////////////////////
//  newGame
/////////////////////////////////////////////////////
bool Menu::newGame(sf::RenderWindow &m_window)
{
	m_window.setFramerateLimit(10);
	m_window.create(sf::VideoMode(1280, 720), "Bomberman");
	//m_window.setSize(sf::Vector2u(unsigned int(m_windowSize.x), unsigned int(m_windowSize.y)));
	while (m_window.isOpen())
	{

		m_window.clear();
		m_window.draw(m_rect);
		for (int buttIndex = 0; buttIndex < 3; buttIndex++)
		{
			if (buttIndex == m_buttNum)
				m_buttons[buttIndex].setOutlineThickness(10);
			else
				m_buttons[buttIndex].setOutlineThickness(0);//::Color(255, 255, 255, 255));

			m_window.draw(m_buttons[buttIndex]);

		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_buttNum < 2)  m_buttNum++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_buttNum > 0)  m_buttNum--;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) //enter pressed
			switch (m_buttNum)
			{
			case 0:
				return true;  //the NEW GAME button  pressed
			case 1:
				showHelp();
				break;
			case 2:
				m_window.close();
				break;

			}

		m_window.display();

	}
	//m_window.setSize(sf::Vector2u{ 1280, 720 });
	//m_window.setFramerateLimit(1000);
	return false;
}

void Menu::showHelp() const
{
}

