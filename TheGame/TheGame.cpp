// TheGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Copyright Tessa Power 2020

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <array>
#include "GameWinChecker.h"
#include "GameDataConverter.h"
#include "MoveValidator.h"
#include "Animator.h"

void playGame();
void printIntro(); // using refactored function
void printInstructions();

void setUpGame();
void askToPlayAgain();
void getPlayerMove(char playerSymbol); // using refactored function

void checkForWin(); // using refactored function
const int gameBoardSize = 9;
void displayGameState(std::array <char, gameBoardSize> gameState); // using refactored function

void printWinningMessage();
void showMenu();
void showHighscoreMenu();
void showCreditsMenu();

std::array <char, gameBoardSize> gameState { };
std::string gameBoard;
std::string scoreBoard;
bool gameWon;
int playerMove;
int maximumPlayerTurns;
int currentTurn;
char userInput;
bool validUserInput;
int playerOneScore = 0;
int playerTwoScore = 0;
char symbol;

const std::string step1 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
   |   |
___|___|___
   |   |
   |   |
   |   |
)";

const std::string step2 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
TIC|   |
___|___|___
   |   |
   |   |
   |   |
)";

const std::string step3 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
TIC|TAC|
___|___|___
   |   |
   |   |
   |   |
)";

const std::string step4 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
TIC|TAC|TOE!
___|___|___
   |   |
   |   |
   |   |
)";

const std::array <std::string, 5> introductionAnimationSequence{ step1, step2, step3, step4 };

int main()
{
	printIntro();
	showMenu();
	playGame();
}

void printIntro()
{
	Animator animator;
	animator.animate(introductionAnimationSequence);
}

void showMenu()
{
	system("CLS");
	std::cout << "+---------------+\n";
	std::cout << "|  TIC TAC TOE  |\n";
	std::cout << "+---------------+\n\n";
	std::cout << "1. How to Play\n";
	std::cout << "2. Scoreboard\n";
	std::cout << "3. Credits\n\n\n\n";
	std::cout << "Press [Enter] to play...\n";

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
			showHighscoreMenu();
		}
		else if (userInput == '3')
		{
			validUserInput = true;
			showCreditsMenu();
		}
		else if (userInput)
		{
			validUserInput = true;
			return;
		}
		else
		{
			std::cout << "I'm sorry, I don't understand that command. Try again.\n";
		}
	}
}

void printInstructions()
{
	system("CLS");
	std::cout << "+---------------+\n";
	std::cout << "|  HOW TO PLAY  |\n";
	std::cout << "+---------------+\n\n";
	std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
	std::cout << "Press any key to continue...";
	int pressedToContinue;
	pressedToContinue = _getch();
	if (pressedToContinue)
	{
		system("CLS");
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO PLAY  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO WIN!  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n\n";
		Sleep(1000);
		system("CLS");
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO PLAY  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO WIN!  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   | X |               |   |             X |   |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |             X |   |               |   |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n\n";
		Sleep(1000);
		system("CLS");
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO PLAY  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO WIN!  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   | X |               |   |             X |   |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   | X |             X | X |               | X |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   |   |               |   |               |   |   \n\n";
		Sleep(1000);
		system("CLS");
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO PLAY  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "+---------------+\n";
		std::cout << "|  HOW TO WIN!  |\n";
		std::cout << "+---------------+\n\n";
		std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   | X |               |   |             X |   |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   | X |             X | X | X             | X |   \n";
		std::cout << "___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "   |   |               |   |               |   |   \n";
		std::cout << "   | X |               |   |               |   | X \n";
		std::cout << "   |   |               |   |               |   |   \n\n";
	}
	else
	{
		std::cout << "Press any key to continue...";
		_getch();
	}

	std::cout << "Press any key to return to the main menu...";
	int keyPressed;
	keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "Press any key to return to the main menu...";
		_getch();
	}
}

void showHighscoreMenu()
{
	system("CLS");
	std::cout << "+--------------+\n";
	std::cout << "|  SCOREBOARD  |\n";
	std::cout << "+--------------+\n\n";
	std::cout << "This feature is coming soon!\n\n";

	int keyPressed;
	std::cout << "Press any key to return to the main menu...";
	keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "Press any key to return to the main menu...";
		_getch();
	}
}

void showCreditsMenu()
{
	system("CLS");
	std::cout << "+-----------+\n";
	std::cout << "|  CREDITS  |\n";
	std::cout << "+-----------+\n\n";
	std::cout << "This game was made by Tessa Power.\n\n";

	int keyPressed;
	std::cout << "Press any key to return to the main menu...";
		keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "Press any key to return to the main menu...";
		_getch();
	}
}

void playGame()
{
	setUpGame();
	displayGameState(gameState);

	do
	{
		if (currentTurn % 2 == 1)
		{
			symbol = 'X';
			std::cout << "> Player 1's turn [X]\n";
		}
		else
		{
			symbol = 'O';
			std::cout << "> Player 2's turn [O]\n";
		}
		
		getPlayerMove(symbol);
		displayGameState(gameState);
		checkForWin();
		if (gameWon) {
			printWinningMessage();
		}
		else
		{
			currentTurn++;
		}
	} while (currentTurn != maximumPlayerTurns + 1 && !gameWon);

	if (!gameWon)
	{
		std::cout << "\nIt's a draw! Better luck next time...\n\n";
	}

	askToPlayAgain();
}

void setUpGame()
{
	maximumPlayerTurns = gameBoardSize;
	currentTurn = 1;

	// Populate the grid spaces with place holder numbers
	//for (int i = 0; i < gameBoardSize; i++) {

	//	gameState[i] = gridPositions[i];
	//}
}

void askToPlayAgain()
{
	char playerAnswer;
	std::cout << "Do you want to play again? Y/N...\n";
	std::cin >> playerAnswer;

	if (playerAnswer == 'y' || playerAnswer == 'Y')
	{
		playGame();
	}
	else {
		system("CLS");
	}
}

void getPlayerMove(char playerSymbol)
{
	bool moveAccepted = false;
	MoveValidator moveValidator;

	while (!moveAccepted)
	{
		std::cin >> playerMove;
		bool moveIsValid = moveValidator.checkIfMoveIsValid(playerMove, gameState);
		if (moveIsValid)
		{
			moveAccepted = true;
			gameState[playerMove-1] = playerSymbol;
			break;
		}
		else
		{
			std::cout << "That spot is already taken! Try again.\n\n";
		}
	}
}

void checkForWin()
{
	GameWinChecker gameWinChecker;
	gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);
}

void displayGameState(std::array <char, gameBoardSize> gameState)
{
	system("CLS");
	GameDataConverter gameDataConverter;
	std::cout << gameDataConverter.convertGameStateToVisualRepresentation(gameState);
}

void printWinningMessage()
{
	if (currentTurn % 2 == 1)
	{
		std::cout << "> Player 1 wins! [X]\n\n";
		playerOneScore++;
	}
	else
	{
		std::cout << "> Player 2 wins! [O]\n\n";
		playerTwoScore++;
	}
}
