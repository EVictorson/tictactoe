#pragma once

#include <stdlib.h>
#include <array>
#include <conio.h>
#include <iostream>
#include <string>

class Menu
{
	int getUserInput();
	int checkForAnyKeyPressed(int userInput);
	void navigateToSubmenu(int userInput);
	void returnToMainMenu(int userInput);
};

