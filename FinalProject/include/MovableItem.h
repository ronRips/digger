//derived class from Item and base class for all movable and execute the moving thet common to all of them
#pragma once

#include "Item.h"

class Board;
class Stone;

class MovableItem :public Item
{
public:
	MovableItem(const sf::Texture& image, const sf::Vector2f& position);
	virtual void move(float time, Board& board) = 0;
	bool moveTo(int direction, float speed, const Board& board);
	virtual void moveBack(float time);
	virtual bool isBlocked(const Stone& stone)const =0;

protected:
	int m_direction;
	bool m_opposite;
};
