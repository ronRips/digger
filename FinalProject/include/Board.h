//class Board manage the game, where the lives score and stones are changed, where the Movable Item are moved

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Monster.h"
#include "StatItem.h"
#include "Digger.h"
#include <fstream>
#include <iostream>
#include "Info.h"
#include "BFStruct.h"

class SmartMonster;


class Board
{
public:
	Board(std::ifstream& ifs, const sf::Vector2f& size, int stones, float time, int& lives, int& score, int& level);
	//for each iteration draw the board
	void draw();
	//check if in limits
	bool inLinits(const sf::Vector2f& position)const;
	//Controller execute the game by this function return true if continue the game
	bool play();
	void decStone();
	void addStones(int stones);
	void addTime(float time);
	void addScore(int score);
	sf::Vector2f getDiggerPosition()const;
	//initializing for BFS algorithm
	void initBFS();
	sf::Vector2i BFSize()const;

	static sf::Vector2f m_firstPoint;

private:
	friend SmartMonster;
	std::vector<std::vector<BFStruct>>& matrix(); //for BFS - maps the board by points

	//prepare the board
	void setRectangle();
	void loadFiles();
	void setItems( std::ifstream& ifs);
	void setInfo();
	void changeInfo();


	int assort()const;// detrmine if it would be a RegularMonster or SmartMonster
	void restart();       //if terminate the stones or time is over
	void handleDigCollision(float t);         //handle Digeer Collision
	void monstersMoveCollision(float t);        //handle Monster Collision
	void createBFS();

	sf::RenderWindow m_window;
	sf::RectangleShape m_rect;

	std::vector< std::unique_ptr<Monster>> m_monsters;
	std::vector <std::unique_ptr<StatItem>> m_statItem;
	std::unique_ptr<Digger> m_Digger;
	sf::Vector2f m_size;
	int& m_lives;
	int& m_score;
	int& m_level;
	int m_stones;
	float m_time;

	std::vector<std::vector<BFStruct>> m_math;

	sf::Texture m_digger;
	sf::Texture m_monster;
	sf::Texture m_diamond;
	sf::Texture m_stone;
	sf::Texture m_wall;
	sf::Texture m_gift;	

	sf::Font m_font;
	std::vector <Info> m_info;
};


