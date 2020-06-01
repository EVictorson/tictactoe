#include "menuDisplayer.h"

void MenuDisplayer::displaySubmenu(int userInput)
{
	std::array <std::string, 5> submenu{};

	Animator submenuAnimator;
	switch (userInput)
	{
	case 1:
		submenu = howToPlayMenu;
	case 2:
		submenu = highscoreMenu;
	case 3:
		submenu = creditsMenu;
	default:
		submenu = mainMenu;
	}

	submenuAnimator.animate(submenu);
}

void MenuDisplayer::displayMainMenu()
{
	Animator menuAnimator;
	menuAnimator.animate(mainMenu);
}
