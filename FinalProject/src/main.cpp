
#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include "Controller.h"
#include "Board.h"
#include <string>

int main()
{
	auto con = Controller{};
	con.run();

	return 0;
}
