#include "Board.h"

#include "Digger.h"
#include "RegularMonster.h"
#include "SmartMonster.h"
#include "Diamond.h"
#include "Stone.h"
#include "Wall.h"
#include "Gift.h"
#include <experimental/vector>
#include <typeinfo>

sf::Vector2f Board::m_firstPoint{ 0,0 };

Board::Board(std::ifstream& ifs, const sf::Vector2f& size, int stones, float time, int& lives, int& score, int& level)
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Digger"), m_size (size), m_lives(lives),
             m_score (score), m_stones (stones), m_level (level) , m_time(time)
{ 
	m_firstPoint = sf::Vector2f((WINDOW_WIDTH - m_size.x * SIZE) / 2, (WINDOW_HEIGHT - m_size.y * SIZE) / 2);
	setRectangle();
	loadFiles();
	setItems(ifs);
	setInfo();
	createBFS();
}

//************************************************************

void Board::draw()
{
	m_window.clear(sf::Color(46, 346, 377));
	m_window.draw(m_rect);
	for (int i = 0; i < m_statItem.size(); i++)
			m_statItem[i]->draw(m_window);
	for (int j = 0; j < m_monsters.size(); j++)
		m_monsters[j]->draw(m_window);
	m_Digger->draw(m_window);

	changeInfo();
	for (auto& text : m_info)
		text.draw(m_window);

	m_window.display();
}

//***************************************************************
bool Board::inLinits(const sf::Vector2f& position)const
{
	if (m_rect.getGlobalBounds().contains(position))
		return true;
	return false;	
}

//*******************************************************
bool Board::play()
{
	auto time = sf::Clock{};
	
	auto clock = sf::Clock{};
	clock.restart();
	while (m_window.isOpen())
	{
		m_time -= time.restart().asSeconds();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				m_window.close();
				break;
			}
			m_Digger->getDirection(event);
		}
		float t = clock.restart().asSeconds();
		m_Digger->move(t , *this);

		handleDigCollision(t);

		monstersMoveCollision(t);
		
		int sumDiamond = 0;
		for (auto& stat : m_statItem)
			if (typeid(*stat) == typeid(Diamond))
				sumDiamond++;
		if (sumDiamond == 0)
		{
			addScore(LEVEL_SCORE);
			return true;			
		}
		if (m_stones <= 0 || m_time <= 0)
		{
			--m_lives; 
			--m_level;
			if(m_lives > 0)return true;
		}
		if (  m_lives <= 0 )return false;
		draw();
	}
	return false;
}

//*****************************************
void Board::decStone()
{
	m_stones--;
}

//************************************************
void Board::addStones(int stones)
{
	m_stones += stones;
}

//*************************************************
void Board::addTime(float time)
{
	m_time += time;
}

//**********************************************
void Board::addScore(int score)
{
	m_score += score;
}

//***********************************************
sf::Vector2f Board::getDiggerPosition()const
{
	return m_Digger->getCurPosition();
}

//**********************************************
void Board::initBFS()
{
	for (int i = 0; i<m_math.size(); i++)
		for (int j = 0; j < m_math[i].size(); j++)
		{
			m_math[i][j].isDestination = false;
			m_math[i][j].isSorce = false;
			m_math[i][j].isValid = true;
			m_math[i][j].parent = Point{ -1, -1 };
			m_math[i][j].position = sf::Vector2f{ m_firstPoint.x + 35 + j * SIZE , m_firstPoint.y + 35 + i * SIZE };

			for (auto& stat : m_statItem)
				if (stat->contain(m_math[i][j].position) && stat->isBlocker(*m_monsters[0]))
					m_math[i][j].isValid = false;

			if (m_Digger->contain(m_math[i][j].position))
				m_math[i][j].isDestination = true; 
		}
	int k = int((m_Digger->getCurPosition().y - Board::m_firstPoint.y + 35) / SIZE);
	int l = int((m_Digger->getCurPosition().x - Board::m_firstPoint.x + 35) / SIZE);

	m_math[k][l].isDestination = true;
}

//******************************************************************
sf::Vector2i Board::BFSize()const
{
	return sf::Vector2i(m_size.x , m_size.y );
}

//*************************************************
std::vector<std::vector<BFStruct>>& Board::matrix()
{
	return m_math;
}

//***************************************************
void Board::setRectangle()
{
	m_rect = sf::RectangleShape {sf::Vector2f(m_size.x *SIZE, m_size.y * SIZE) };
	m_rect.setOrigin(sf::Vector2f(m_size.x * SIZE / 2, m_size.y * SIZE / 2));
	m_rect.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
	m_rect.setOutlineColor(sf::Color::Black);
	m_rect.setOutlineThickness(1.2);
	m_rect.setFillColor(sf::Color(128, 128, 255));
}

//********************************************************
void Board::loadFiles()
{
	m_digger.loadFromFile("digger.png");
	m_monster.loadFromFile("monster.png");
	m_diamond.loadFromFile("diamond.png");
	m_stone.loadFromFile("stone.png");
	m_wall.loadFromFile("wall.png");
	m_gift.loadFromFile("gift.png");
}

//********************************************************
void Board::setItems(std::ifstream& ifs)
{
	std::string s;
	for (int i = 0; i < m_size.y; i++) {
		getline(ifs, s);
		for (int j = 0; j < m_size.x; j++)
			switch (s[j])
			{
			case DIGGER:
				m_Digger = std::make_unique <Digger>( m_digger, sf::Vector2f(float(j),float(i)) );
				break;

			case MONSTER: {
				int type = assort();
				if (type != 1) 
					m_monsters.push_back(std::make_unique <RegularMonster>(m_monster, sf::Vector2f(float(j), float(i))));
				else
					m_monsters.push_back(std::make_unique <SmartMonster>(m_monster, sf::Vector2f(float(j), float(i))));
				break;
			}
			case DIAMOND: {
				m_statItem.push_back(std::make_unique<Diamond>(m_diamond, sf::Vector2f(float(j), float(i))));
				break;
			}
			case STONE: {
				m_statItem.push_back(std::make_unique<Stone>(m_stone, sf::Vector2f(float(j), float(i))));
				break;
			}
			case WALL: {
				m_statItem.push_back(std::make_unique<Wall>( m_wall, sf::Vector2f(float(j), float(i)) ));
				break;
			}
			case GIFT:
				m_statItem.push_back(std::make_unique<Gift>(m_gift, sf::Vector2f(float(j), float(i))));
				break;
			}
	}
}

//**************************************************************************
void Board::setInfo()
{
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	m_info.push_back(Info{ "Lives: ", m_lives, sf::Vector2f{20, 0}, m_font });
	m_info.push_back(Info{ "Level: ", m_level, sf::Vector2f{300, 0}, m_font });
	m_info.push_back(Info{ "Score: ", m_score, sf::Vector2f{580, 0}, m_font });
	m_info.push_back(Info{ "Stones: ", m_stones, sf::Vector2f{860, 0}, m_font });
	m_info.push_back(Info{ "Time: ",int (m_time), sf::Vector2f{1140, 0}, m_font });
}

//*******************************************************************************
void Board::changeInfo()
{
	m_info[0].setVal(m_lives);
	m_info[1].setVal(m_level);
	m_info[2].setVal(m_score);
	m_info[3].setVal(m_stones);
	m_info[4].setVal(int(m_time));
}

//***************************************************************
int Board::assort()const
{
	static int count = 0;
	srand(time(NULL) + count++);
	return rand()%2;
}

//**********************************************************
void Board::restart()
{
	m_Digger->restartDirection();
	m_Digger->restartPosition();
	for (auto& monster : m_monsters)
		monster->restartPosition();
}

//***************************************************
void Board::handleDigCollision(float t)
{
	for (auto& stat : m_statItem)
		if (m_Digger->collision(*stat))
			if (stat->isBlocker(*m_Digger))
				m_Digger->moveBack(t);
			else stat->operate(*this);
	std::experimental::erase_if(m_statItem, [](const auto& stat) {return stat->isDead(); });

	for (auto& monster : m_monsters)
		if (m_Digger->collision(*monster)) {
			m_lives--;
			restart();
		}
}

//********************************************************
void Board::monstersMoveCollision(float t)
{
	for (auto& monster : m_monsters)
	{
		monster->move(t, *this);
		if (monster->collision(*m_Digger)) {
			m_lives--;
			restart();
		}
		for (auto& stat : m_statItem)
			if (monster->collision(*stat) && stat->isBlocker(*monster))
				monster->moveBack(t);
	}
}

//*****************************************************
void Board::createBFS()
{
	BFStruct bfs;
	std::vector <BFStruct> row;
	
	for (int j = 0; j < m_size.x ; j++)
		row.push_back(bfs);

	for (int i = 0; i < m_size.y ; i++)
		m_math.push_back(row);

	initBFS();
}

