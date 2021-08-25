#include "Board.h"
#include "Item.h"

//**********************************************************
Item::Item(const sf::Texture& image, const sf::Vector2f& position)
	           : m_position (sf::Vector2f (position.x * SIZE + Board::m_firstPoint.x, position.y* SIZE + Board::m_firstPoint.y)),
	             m_sprite(image)
{
	m_sprite.setPosition(getPosition());
}

//*********************************************
void Item::setPosition(sf::Vector2f position)
{
	m_position = position;
}

//****************************************
sf::Vector2f Item::getPosition()const
{
	return m_position;
}

//******************************************
sf::Vector2f Item::getCurPosition()const
{
	return sf::Vector2f{m_sprite.getGlobalBounds().left, m_sprite.getGlobalBounds().top};
}

//******************************************************
void Item::restartPosition()
{
	m_sprite.setPosition(getPosition());
}

//************************************************
bool Item::collision(const Item& other)const
{
	return (m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds()));	
}

//********************************************
bool Item::contain(sf::Vector2f position)const
{
	return m_sprite.getGlobalBounds().contains(position);
}

//*****************************************
void Item::draw(sf::RenderWindow& window)const
{
	window.draw(m_sprite);
}
