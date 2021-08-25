//base class for all items keep their sprite and their position check collisions and containing
//and has the virtual func "draw"

#pragma once

#include "Constant.h"
#include <SFML/Graphics.hpp>

class Item 
{
public:
	Item(const sf::Texture& image, const sf::Vector2f& position);
	virtual ~Item()  = 0 {};

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition()const;
	sf::Vector2f getCurPosition()const;
	void restartPosition();

	bool collision(const Item& other)const;
	bool contain(sf::Vector2f position)const;

	void draw(sf::RenderWindow& window)const;


protected:
	sf::Sprite m_sprite;

private:
	sf::Vector2f m_position;
};