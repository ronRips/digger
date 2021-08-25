//derived class from Monster mange it's unique movement 

#pragma once

#include "Monster.h"

class RegularMonster :public Monster
{
public:
	RegularMonster (const sf::Texture& image, const sf::Vector2f& position);
	virtual void move(float time1, Board& board) override;
	virtual void moveBack(float time)override;
	virtual bool isBlocked(const Stone& stone)const override;

private:
	void deterDirection();
	int m_countSteps ;
};