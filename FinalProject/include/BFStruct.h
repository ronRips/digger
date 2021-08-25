//BFStruct for the BFS algorithm that maps the board and would find the shortest path from the
//SmartMonster to the Digger
//
//struct Point for utility

#pragma once
#include <SFML/Graphics.hpp>

struct Point
{
	Point(int y = -1, int x = -1) : row(y), col(x) {};
	int row, col;
};

struct BFStruct
{
	bool isValid;
	bool isSorce;
	bool isDestination;
	sf::Vector2f position;
	Point parent;
};
