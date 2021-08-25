//derived class from StatItem 

#pragma once

#include "StatItem.h"

class Wall :public StatItem
{
public:
	Wall(const sf::Texture& image, const sf::Vector2f& position);
	virtual bool isBlocker(MovableItem& item)const override;

private:
};

