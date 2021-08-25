#pragma once

#include "Wall.h"
#include <iostream>

//***************************************************************************
Wall::Wall(const sf::Texture& image, const sf::Vector2f& position) :  StatItem (image, position)
{
	m_sprite.setScale(sf::Vector2f{ SIZE / WALL_WIDTH, SIZE / WALL_HEIGHT });
}

//******************************************************
bool Wall::isBlocker(MovableItem& item)const
{
	return true;
}

