#pragma once

#include <stdlib.h>
#include <array>
#include <conio.h>
#include <iostream>
#include <string>
#include "menuDisplayer.h"

class Menu
{
public:
	int getUserInput();
	bool validateUserInput(int userInput, std::array <int, 3> submenuOptions);
	bool checkForAnyKeyPressed();
	void navigateToSubmenu(int userInput);
	void returnToMainMenu(bool anyKeyPressed);
	std::array <int, 3> submenuOptions{ 1, 2, 3 };
};
