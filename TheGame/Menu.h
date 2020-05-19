#pragma once

#include <stdlib.h>
#include <array>
#include <string>
#include <conio.h>

class Menu
{
	int getUserInput();
	int checkForAnyKeyPressed(int userInput);
	void navigateToSubmenu(int userInput);
	void returnToMainMenu(int userInput);
};

