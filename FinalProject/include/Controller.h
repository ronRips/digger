//this class manage the game read files and change levels and display menu 

#pragma once

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

class Controller
{
public:
	void run(); //manage the game

private:
	void readRow(); //read from file to send to the board 

	sf::Vector2f m_size;
	std::ifstream m_ifs;
	int m_stones;
	float m_time;
	int m_lives;
	int m_score ;
};
