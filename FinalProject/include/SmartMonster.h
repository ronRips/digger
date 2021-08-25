//derived class from Monster mange it's unique movement 

#pragma once

#include "Monster.h"
#include "BFStruct.h"

class SmartMonster :public Monster
{
public:
	SmartMonster(const sf::Texture& image, sf::Vector2f position);
	void move(float time, Board& board);
	virtual void moveBack(float time)override;
	virtual bool isBlocked(const Stone& stone)const override;

private:
	//manage the BFS algorithm for the moving
	int BFS(std::vector<std::vector<BFStruct>>& matBFS, sf::Vector2i sizeBFS);
	bool checkSons(Point point, std::vector<std::vector<BFStruct>>& matBFS, sf::Vector2i sizeBFS, std::vector<Point>& queue);
	void handleSon(Point parent, Point son, std::vector<std::vector<BFStruct>>& matBFS, std::vector<Point>& queue);

	float m_passed;
};


