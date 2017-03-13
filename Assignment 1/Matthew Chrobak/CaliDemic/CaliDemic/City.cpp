#include "City.h"
#include "Game.h"
#include <iostream>
#include <string>

const int City::RenderWidth = 20;
const int City::RenderHeight = 20;

City::City()
{
}


City::~City()
{
}

void City::consoleAddNodeAtCoordDialogue(int x, int y)
{
	City* city = new City();
	std::cout << "Please enter a name: " << std::endl;
	std::getline(std::cin, city->name);

	while (city->name == "") {
		std::getline(std::cin, city->name);
	}

	city->x = x;
	city->y = y;

	std::cout << "Black: " << InfectionColor::Black << std::endl;
	std::cout << "Blue: " << InfectionColor::Blue << std::endl;
	std::cout << "Yellow: " << InfectionColor::Yellow << std::endl;
	std::cout << "Red: " << InfectionColor::Red << std::endl;

	std::string input;
	std::getline(std::cin, input);
	city->color = (InfectionColor)std::atoi(input.c_str());

	Game::getGameBoard()->addCity(city);
}