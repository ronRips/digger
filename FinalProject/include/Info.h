//class for the information printed on the screen during the run of the game

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Info
{
public:
	Info(const std::string &label, int val,  sf::Vector2f position, const sf::Font& font);
	void draw(sf::RenderWindow& window);
	void setVal(int value);

private:
	sf::Text m_text;
	std::string m_label;
	int  m_val;
};

