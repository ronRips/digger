//derived class from StatItem 

#pragma once

#include "StatItem.h"

class Diamond :public StatItem
{
public:
	Diamond(const sf::Texture& image, const sf::Vector2f& position);
	virtual bool isBlocker(MovableItem& item)const override;
	virtual void operate(Board& board)override;

private:
};
