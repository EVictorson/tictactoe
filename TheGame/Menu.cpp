#include "Menu.h"

int Menu::getUserInput()
{
	int userInput = _getch();
	bool userInputValid = false;
	while (!userInputValid)
	{
		for (auto option : submenuOptions)
		{
			if (userInput == option)
			{
				userInputValid = true;
				return userInput;
			}
			else if (userInput)
			{
				userInputValid = true;
				return;
			}
		}
	}
}

bool Menu::checkForAnyKeyPressed(int userInput)
{

}

void Menu::navigateToSubmenu(int userInput)
{

}

void Menu::returnToMainMenu(int userInput)
{

}