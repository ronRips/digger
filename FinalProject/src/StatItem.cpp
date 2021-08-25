#include "Item.h"
#include "..\include\StatItem.h"

//**************************************************************************
StatItem::StatItem(const sf::Texture& image, const sf::Vector2f& position) : Item (image , position), m_isDead (false)
{
}

//**********************************
void StatItem::operate(Board& board)
{
}

//***********************************
bool StatItem::isDead()const
{
	return m_isDead;
}
