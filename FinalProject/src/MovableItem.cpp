#include "MovableItem.h"
#include "Board.h"

MovableItem::MovableItem(const sf::Texture& image, const sf::Vector2f& position) : Item(image, position), m_direction(STAND), m_opposite (false)
{
}

//*************************************
void MovableItem::move(float time , Board& board)
{
}

//********************************************************
bool MovableItem::moveTo(int direction, float speed, const Board& board)
{
	if (direction == UP)
		if (board.inLinits(sf::Vector2f(m_sprite.getGlobalBounds().left, m_sprite.getGlobalBounds().top - speed))) {
			m_sprite.move(0, -speed);
			return true;
		}
	if (direction == DOWN)
		if (board.inLinits(sf::Vector2f(m_sprite.getGlobalBounds().left, m_sprite.getGlobalBounds().top + m_sprite.getGlobalBounds().height + speed))) {
			m_sprite.move(0, speed);
			return true;
		}

	if (direction == LEFT)
		if (board.inLinits(sf::Vector2f(m_sprite.getGlobalBounds().left - speed, m_sprite.getGlobalBounds().top))) {
			m_sprite.move(sf::Vector2f(-speed, 0.0f));
			if (m_opposite) {
				m_sprite.scale(-1, 1);
				m_opposite = false;
			}

			return true;
		}

	if (direction == RIGHT)
		if (board.inLinits(sf::Vector2f(m_sprite.getGlobalBounds().left + +m_sprite.getGlobalBounds().width + speed, m_sprite.getGlobalBounds().top))) {
			m_sprite.move(speed, 0);
			if (!m_opposite) {
				m_sprite.scale(-1, 1);
				m_opposite = true;
			}
			return true;
		}
	return false;
}

//********************************************
void MovableItem::moveBack(float speed)
{
	switch (m_direction)
	{
	case DOWN:
		m_sprite.move(0, -speed);
		break;

	case UP:
		m_sprite.move(0, speed);
		break;

	case RIGHT:
		m_sprite.move(sf::Vector2f(-speed, 0.0f));
		break;

	case LEFT:
		m_sprite.move(speed, 0);
		break;
	}
}
