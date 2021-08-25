//A menu class receives a call from the board and gives two options or 
//close the board by closing the window or clicking the exit button or accessing 
//the game by pressing a new game button

#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(); //Menu constructor
	bool newGame();//A bool function that returns true to start the game and false to exit the menu
	void reMenu(int mode = 0);//For a replay
	
private:
	void editMenu();
	void lose();
	void win(int score);
	void definRectangle();
	void readFile();
	void definText();

	sf::RenderWindow m_window;
	sf::Font m_font;
	sf::Text m_text1;
	sf::Text m_text2;
	sf::Text m_textWin;
	sf::Texture m_texturRect;
	sf::Texture m_texturWin;
	sf::Sprite m_spritWin;
	sf::Sprite m_spritRect1;
	sf::Sprite m_spritRect2;
	sf::Sprite m_spritRectLose;
	sf::Texture m_Bckground;
	sf::Texture m_textureLose;
	sf::Sprite m_spriteBckground;
	sf::RectangleShape m_rectangleshapeNew;
	sf::RectangleShape m_rectangleshapeExit;
};
