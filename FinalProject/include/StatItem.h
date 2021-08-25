//derived class from Item base class for all static items -  pure virtual

#pragma once

#include "Item.h"

class MovableItem;

class Board;

class StatItem :public Item
{
public:
	StatItem(const sf::Texture& image, const sf::Vector2f& position);

	virtual bool isBlocker(MovableItem& item)const = 0;
	virtual void operate(Board& board);
	bool isDead()const;
protected:
	bool m_isDead;    //to delete from a vector if eated
};

