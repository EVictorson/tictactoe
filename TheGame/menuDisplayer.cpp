#include "menuDisplayer.h"

void MenuDisplayer::displaySubmenu(int userInput)
{
	//std::array <std::string, 5> submenu{};

	//Animator submenuAnimator;
	switch (userInput)
	{
	case 1:
		system("CLS");
		std::cout << howToPlayMenu << std::endl;
		std::cout << returnToMainMenu << std::endl;
	case 2:
		system("CLS");
		std::cout << highscoreMenu << std::endl;
		std::cout << returnToMainMenu << std::endl;
	case 3:
		system("CLS");
		std::cout << creditsMenu << std::endl;
		std::cout << returnToMainMenu << std::endl;
	default:
		displayMainMenu();
	}

	//submenuAnimator.animate(submenu);
	//if (submenu != mainMenu)
	//{
	//	std::cout << returnToMainMenu << std::endl;
	//}
}

void MenuDisplayer::displayMainMenu()
{
	system("CLS");
	std::cout << mainMenu;
}
