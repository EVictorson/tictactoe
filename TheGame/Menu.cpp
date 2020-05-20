#include "Menu.h"

int Menu::getUserInput()
{
	bool userInputValid = false;
	int userInput = _getch();
	while (!userInputValid)
	{
		validateUserInput(userInput, submenuOptions);
	}

	return userInput;
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
