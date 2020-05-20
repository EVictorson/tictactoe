#pragma once

#include <stdlib.h>
#include <array>
#include <conio.h>
#include <iostream>
#include <string>

class Menu
{
	int getUserInput();
	bool checkForAnyKeyPressed(int userInput);
	void navigateToSubmenu(int userInput);
	void returnToMainMenu(bool anyKeyPressed);
	std::array <int, 3> submenuOptions{ 1, 2, 3 };
};
