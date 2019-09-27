#include "InfoBar.h"
#include <sstream>

//===========================================
// c-tor . gets position and size
//===========================================
InfoBar::InfoBar(sf::Vector2f pos, sf::Vector2f size)
{
	m_infoBar.setPosition(pos);
	m_infoBar.setSize(size);
	m_infoBar.setFillColor(sf::Color::Yellow);
	m_font.loadFromFile("arial.TTF");
}
//==================================================================
// set new level. 
// gets level, bomb limit, time limit (seconds as int), life to add.
//==================================================================
void InfoBar::setNewLevel(int life)
{
	m_level = LEVEL;
	m_bomb = BOMB_LIM;
	if (TIME_LIM != -1) // if level as time limit
		m_timeLimit = sf::seconds(float(TIME_LIM)); // set time as seconds // fixed adding float
		//m_timed = true;
	m_clock.restart();// restar clock
	
	addLife(life); // case added life (by default = 0)
}

//===========================================
// draw 
//===========================================
void InfoBar::draw(sf::RenderWindow & win)
{
	// just for example of clock
	if (TIME_LIM != -1 && m_clock.getElapsedTime().asSeconds() >= m_timeLimit.asSeconds())
		RESTART = true;

	int tsec = abs(m_timeLimit.asSeconds() - m_clock.getElapsedTime().asSeconds());
	
	int m_minute = tsec / 60;
	int m_sec = tsec % 60;
	std::string minute = (m_minute < 10) ? "0" + std::to_string(m_minute) : std::to_string(m_minute);
	std::string sec = (m_sec < 10) ? "0" + std::to_string(m_sec) : std::to_string(m_sec);
	std::string timePrint = "	Time: " + minute + ": " + sec;
	std::stringstream strToPrint; // create string 
	strToPrint << "Level: " << m_level << timePrint
		<< '\n'<<	"Life: " << m_life << "	Score: " << m_score << "	Bombs: " << BOMB_LIM; // idea
	sf::Text text(strToPrint.str(), m_font, 25); // make string to text
	text.setPosition(m_infoBar.getPosition().x + 25.f, m_infoBar.getPosition().y + 15.f);
	text.setFillColor(sf::Color::Black);
	win.draw(m_infoBar);
	win.draw(text);
}

//===========================================
// d-tor
//===========================================
InfoBar::~InfoBar()
{
}
