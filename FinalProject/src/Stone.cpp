#include "Stone.h"
#include "Board.h"
#include "MovableItem.h"

//***************************************************************************************************
Stone::Stone(const sf::Texture& image, const sf::Vector2f& position) : StatItem (image, position)
{
	m_sprite.setScale(sf::Vector2f{ SIZE / STONE_WIDTH, SIZE / STONE_HEIGHT });
}

//**************************************************
bool Stone::isBlocker( MovableItem& item)const
{
	return item.isBlocked(*this);
}

//**********************************************************
void Stone::operate(Board& board)
{
	m_isDead = true;
	board.decStone();
}
