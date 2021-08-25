#include "Digger.h"
#include "Board.h"

//*********************************************************
Digger::Digger(const sf::Texture& image, const sf::Vector2f& position):  MovableItem (image, position)
{
	m_sprite.setOrigin(sf::Vector2f{ DIGGER_WIDTH * 0.8 / 2 ,  DIGGER_HEIGHT * 0.8 / 2 });
	m_sprite.setScale(sf::Vector2f{ SIZE / DIGGER_WIDTH, SIZE / DIGGER_HEIGHT });
	m_sprite.move(sf::Vector2f{ SIZE / 2, SIZE / 2 });
	setPosition(m_sprite.getPosition());   
}

//*******************************************************
void Digger::move(float time, Board& board)
{
	float speed = time * DIGGER_SPEED;
		moveTo(m_direction, speed, board);
}

//**************************************************
void Digger::moveBack(float time)
{
	float speed = time * DIGGER_SPEED;
	MovableItem::moveBack(speed);
}

//*************************************************
bool Digger::isBlocked(const Stone& stone)const
{
	return false;
}

//**********************************************
void Digger::getDirection(const sf::Event& event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_direction = UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_direction = DOWN;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_direction = LEFT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_direction = RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		m_direction = STAND;	
}

//************************************************************
void Digger::restartDirection()
{
	m_direction = STAND;
	if (m_opposite) {
		m_sprite.scale(-1, 1);
		m_opposite = false;
	}
}

