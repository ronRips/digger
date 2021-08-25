#include "Controller.h"
#include <sstream>
#include <string>
#include "Board.h"
#include "Menu.h"


//******************************************************************
void Controller::run()
{
	auto menu = Menu{};
	while (menu.newGame())
	{
		std::string str1 = "Board";
		int num = 0;
		std::string str2 = ".txt";
		std::string str = str1;
		str.append(std::to_string(num++)).append(str2);
		m_ifs.open(str);
		m_lives = LIVES;
		m_score = 0;
		bool reject = false;
		while (m_ifs.is_open())
		{
			readRow();
			auto board = Board{ m_ifs, m_size, m_stones, m_time, m_lives, m_score, num };
			board.draw();
			if (reject = board.play())
			{
				m_ifs.close();
				str = str1;
				str.append(std::to_string(num++)).append(str2);
				m_ifs.open(str);
			}
			else break;
		}
		m_ifs.close();
		if (reject)
			menu.reMenu(m_score);
		else if(m_lives)
			menu.reMenu();
		else menu.reMenu(1);
	}
}

//**********************************************
void Controller::readRow()
{
	std::string s;
	getline(m_ifs, s);

	std::istringstream iss(s);

	iss >> m_size.y >> m_size.x >> m_stones >> m_time;
	
}
