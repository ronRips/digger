//derived class from MovableItem and base for monsters 
#pragma once

#include "MovableItem.h"


class Monster :public MovableItem
{
public:
	Monster(const sf::Texture& image, const sf::Vector2f& position);

protected:
	int m_counter;
};
