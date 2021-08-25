//derived class from MovableItem 

#pragma once

#include "MovableItem.h"


class Digger :public MovableItem
{
public:
	Digger(const sf::Texture& image, const sf::Vector2f& position);

	virtual void move(float time, Board& board)override;
	virtual void moveBack(float time) override;
	virtual bool isBlocked(const Stone& stone) const override;
	void getDirection(const sf::Event& event);
	void restartDirection();

private:
};
