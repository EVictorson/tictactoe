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

bool Menu::validateUserInput(int userInput, std::array <int, 3> submenuOptions)
{
	for (auto option : submenuOptions)
	{
		if (userInput == option)
		{
			return true;
			break;
		}
		else if (userInput)
		{
			return true;
			break;
		}
	}

	if (!userInput)
	{
		std::cout << "Sorry, that's not something I can do. Try again.\n" << std::endl;
	}
}

bool Menu::checkForAnyKeyPressed()
{
	int keyPressed = _getch();
	if (keyPressed)
	{
		return true;
	}
	else
	{
		std::cout << "Press any key to return to the main menu...";
	}
}

}
