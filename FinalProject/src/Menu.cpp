#pragma once
#include<iostream>
#include "Menu.h"
#include "Constant.h"

//**************************************************
Menu::Menu() :m_window(sf::VideoMode{ WINDOW_WIDTH, WINDOW_HEIGHT }, "Digger menu")
{
	m_window.clear();
	
	editMenu();
	m_window.display();
}

//**************************************************
void Menu::definRectangle()
{
	m_rectangleshapeNew.setSize(sf::Vector2f(255, 125));
	m_rectangleshapeNew.setPosition(sf::Vector2f(10, 710));
	m_rectangleshapeExit.setSize(sf::Vector2f(255, 125));
	m_rectangleshapeExit.setPosition(sf::Vector2f(300, 710));
}

//******************************************************
void Menu::readFile()
{
	m_Bckground.loadFromFile("Bckground.png");
	m_texturRect.loadFromFile("Rectangle.png");
	m_spriteBckground.setScale(sf::Vector2f(3, 2));

	m_spriteBckground.setTexture(m_Bckground);
	m_spritRect1.setTexture(m_texturRect);
	m_spritRect1.setScale(sf::Vector2f(0.5, 0.5));
	m_spritRect1.setPosition(sf::Vector2f(10, 630)); 

	m_spritRect2.setTexture(m_texturRect);
	m_spritRect2.setScale(sf::Vector2f(0.5, 0.5));
	m_spritRect2.setPosition(sf::Vector2f(300, 630));
}

//******************************************************
void Menu::definText()
{
	m_font.loadFromFile("C:/Windows/Fonts/BRITANIC.ttf");

	m_text2 = sf::Text("new game", m_font);
	m_text2.setColor(sf::Color::Black);
	m_text2.setScale(1.5, 1.5);
	m_text2.setPosition(40, 740);

	m_text1 = sf::Text("exit", m_font);
	m_text1.setColor(sf::Color::Black);
	m_text1.setPosition(360, 740);
	m_text1.setScale(1.8, 1.8);
}

//*************************************************************
void Menu::editMenu()
{
	definRectangle();
	readFile();
	definText();

	m_spritRectLose.setTexture(m_texturRect);

	m_window.draw(m_spriteBckground);
	m_window.draw(m_spritRect1);
	m_window.draw(m_spritRect2);
	m_window.draw(m_text1);
	m_window.draw(m_text2);
}

//******************************************************
bool Menu::newGame()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		if (m_window.waitEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				m_window.close();
				return false;
			}
			auto position = m_window.mapPixelToCoords(sf::Vector2i{ event.mouseButton.x, event.mouseButton.y });
			if (event.type == sf::Event::MouseButtonReleased) {
				if (m_rectangleshapeNew.getGlobalBounds().contains(position)) {
					m_window.close();
					return true;
				}
				if (m_rectangleshapeExit.getGlobalBounds().contains(position)) {
					m_window.close();
					return false;
				}
			}
		}
	}
}

//********************************************************************
void Menu::reMenu(int mode)
{
	m_window.create(sf::VideoMode{ WINDOW_WIDTH, WINDOW_HEIGHT }, "Digger menu");
	m_window.clear();
	editMenu();
	if (mode == 1)
		lose();
	else if (mode != 0)
		win(mode);
	m_window.display();
}

//*********************************************************
void Menu::lose()
{
	sf::IntRect area = sf::IntRect({ 0,0 }, {718, 205});
	m_textureLose.loadFromFile("lose.png");
	m_spritRectLose.setTexture(m_textureLose);
	m_spritRectLose.setTextureRect(area);
	m_spritRectLose.setPosition(sf::Vector2f(550, 0));
	m_window.draw(m_spritRectLose);
}

//******************************************************************
void Menu::win(int score)
{
	m_texturWin.loadFromFile("youWin.png");
	m_spritWin.setTexture(m_texturWin);
	m_spritWin.setScale(1.6, 2.3);
	m_spritWin.setPosition(550, 150);

	m_window.draw(m_spritWin);

	std::string strScore;
	strScore = "your score : ";
	m_textWin = sf::Text(strScore, m_font);
	m_textWin.setString(strScore.append(std::to_string(score)));
	m_textWin.setPosition(420, 3);
	m_textWin.setOutlineColor(sf::Color::Black);
	m_textWin.setOutlineThickness(0.3);
	m_textWin.setColor(sf::Color(255, 0, 0));
	m_textWin.setScale(5, 5);
	m_window.draw(m_textWin);
}