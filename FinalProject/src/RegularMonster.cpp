#include "regularMonster.h"

#include <ctime>
#include <cstdlib>
#include "Board.h"

//****************************************
RegularMonster::RegularMonster(const sf::Texture& image, const sf::Vector2f& position) : Monster (image, position), m_countSteps(0)
{
}

//********************************************************
void RegularMonster::move(float time, Board& board)
{
	if(m_countSteps % REG_MONSTER_STEPS == 0)
		deterDirection();
	float speed = time * REG_MONSTER_SPEED;

	if (!moveTo(m_direction, speed, board))
		 deterDirection();

	m_countSteps++;
}

//************************************************
void RegularMonster::moveBack(float time)
{
	float speed = time * REG_MONSTER_SPEED;
	MovableItem::moveBack(speed);
	deterDirection();
}

//******************************************************
bool RegularMonster::isBlocked(const Stone& stone)const
{
	return true;
}

//***********************************************
void RegularMonster::deterDirection()
{
	srand(time(NULL) + m_counter);

	m_direction = rand() % 4 + 76;
}
