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
	validUserInput = false;
	userInput = _getch();

	while (!validUserInput)
	{
		if (userInput == '1')
		{
			validUserInput = true;
			printInstructions();
		}
		else if (userInput == '2')
		{
			validUserInput = true;
			showScoreboard();
		}
		else if (userInput == '3')
		{
			validUserInput = true;
			showCredits();
		}

	}
}

void Menu::returnToMainMenu(bool anyKeyPressed)
{

}
