#pragma once
#include <vector>
#include <memory>
#include "InfoBar.h"

class MoveObject;
class StaticObject;

class Board
{
private:	
	sf::Vector2i getRobotPls(const char c = '/') const; 
public:
	Board(); // constructor 
	virtual ~Board(); // destructor
	std::vector<std::string> m_toLevel;
	void setData(std::string);
	void insertBoard(std::vector<std::unique_ptr <MoveObject> > &, std::vector<std::unique_ptr <StaticObject> > &); // insert objects to board
};

