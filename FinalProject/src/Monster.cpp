#include "Monster.h"

//***************constructor**********************
Monster::Monster(const sf::Texture& image, const sf::Vector2f& position) :  MovableItem(image, position)
{
	m_sprite.setOrigin(sf::Vector2f{  MONSTER_WIDTH * 0.7 / 2 ,  MONSTER_HEIGHT * 0.7 / 2 });
	m_sprite.setScale(sf::Vector2f{ SIZE / MONSTER_WIDTH, SIZE / MONSTER_HEIGHT });
	m_sprite.move(sf::Vector2f{ SIZE / 2, SIZE / 2 });
	setPosition(m_sprite.getPosition());

	m_opposite = true;

	static int counter = 0;
	m_counter = counter++;
}
