#pragma once
//#include <SFML/Graphics.hpp>
#include <fstream>
#include "Board.h"
#include "MoveObject.h"
#include "Menu.h"

//#include "StaticObject.h"
//#include<iostream>
class Controller
{
private:
	sf::RenderWindow m_window; // SFML windows
	std::ifstream ifs; // stream to open file
	std::unique_ptr < Board > m_board; // board
	std::unique_ptr<InfoBar> m_info; // מצביע לאינפובר
	std::vector<std::unique_ptr <MoveObject> > m_mo; // vector of Move Objects
	std::vector<std::unique_ptr <StaticObject> > m_so; // vector of Static Objects
	void betweenLevel();
	
	std::vector<std::string> m_levels;

	Menu m_menu;
public:
	Controller(); // constructor
	~Controller(); // destructor
	void runGame(); // run Game
	void startAndEnd(int f);
	void setLevel();
	
	void initiate_NOS() { NOS = m_so.size() - 1;  NUMOFGUARDS = m_mo.size() - 1; } // (global) NOS holds number of Non Static members // idea
	void runWindow(); // run SFML windows
	void pollEvent(); // take care of events
	void moveGuard(); // move guard
	void restart(); // restart
	void restartMoveObj();
	void newLevel(); // new level
	void objectBoard(); // draw Objects to SFML windows
	void infoBar(); // idea
	
	static void timerG() {  MOVEG = 1;  } // timer to run guards
};

