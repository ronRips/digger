#include "..\include\Diamond.h"
#include "Board.h"

//*****************************************************************
Diamond::Diamond(const sf::Texture& image, const sf::Vector2f& position):  StatItem(image, position)
{
	m_sprite.setScale(sf::Vector2f{ SIZE / DIAMOND_WIDTH, SIZE / DIAMOND_HEIGHT });
}

//************************************************************
bool Diamond::isBlocker(MovableItem& item)const
{
	return false;
}

//**************************************************
void Diamond::operate(Board& board)
{
	m_isDead = true;
	board.addScore(DIAMOND_SCORE);
}
