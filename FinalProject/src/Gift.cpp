#include "Gift.h"
#include "Board.h"

//********************************************************
Gift::Gift(const sf::Texture& image, const sf::Vector2f& position) : StatItem (image, position)
{
	m_sprite.setScale(sf::Vector2f{ SIZE / GIFT_WIDTH, SIZE / GIFT_HEIGHT });
}

//*******************************************************
bool Gift::isBlocker(MovableItem& item)const
{
	return false;
}

//*******************************************************
void Gift::operate(Board& board)
{
	setMode();
	switch (m_mode)
	{
	case 0:
		board.addStones(STONE_GIFT);
		break;
	case 1:
		board.addTime(TIME_GIFT);
		break;
	case 2:
		board.addScore(SCORE_GIFT);
		break;
	}
	m_isDead = true;
}

//*****************************************************
void Gift::setMode()
{
	srand(time(NULL));
	m_mode = rand() % 3;
}
