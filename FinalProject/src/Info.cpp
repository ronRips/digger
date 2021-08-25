#include "Info.h"

//*************************************************
Info::Info(const std::string& label, int val, sf::Vector2f position, const sf::Font& font)
	: m_text(label, font) ,m_label (label) ,  m_val(val)
{
	m_text.setPosition(position);
}

//********************************************************
void Info::draw(sf::RenderWindow& window)
{
	std::string str = m_label;
	m_text.setString(str.append(std::to_string(m_val)));
	m_text.setStyle(52);
	window.draw(m_text);
}

//***********************************************************
void Info::setVal(int value)
{
	m_val = value;
}

