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
#include "GameWinChecker.h"

void playGame();
void printIntro();
void printInstructions();
std::string convertGameStateToVisualRepresentation(char gameState[]);
std::string convertScoreToVisualRepresentation(int playerOneScore, int playerTwoScore);
void draw(std::string stringToDrawOnScreen);
void setUpGame();
void askToPlayAgain();
void getPlayerMove(char playerSymbol);
bool checkValidMove(int playerMove);
void checkForWin();
void printWinningMessage(); // TODO: use draw method to print winning message
void showMenu(); // TODO: use draw method to show menu
void showHighscoreMenu();
void showCreditsMenu();

const int gameBoardSize = 10;
char gameState[gameBoardSize] = { };
std::string gameBoard;
std::string scoreBoard;
bool horizontalWin, verticalWin, diagonalWin, gameWon;
int playerMove;
int maximumPlayerTurns;
int currentTurn;
char userInput;
bool validUserInput;
int playerOneScore = 0;
int playerTwoScore = 0;
char currentPlayerMark;

int main()
{
	printIntro();
	showMenu();
	playGame();
}

void printIntro()
{
	std::cout << "                                  Let's play...\n\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "                                  Let's play...\n\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  TIC|   |   \n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "                                  Let's play...\n\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  TIC|TAC|   \n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "                                  Let's play...\n\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                  TIC|TAC|TOE!\n";
	std::cout << "                                  ___|___|___\n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n";
	std::cout << "                                     |   |   \n\n";
	Sleep(2000);
	system("CLS");
}

void showMenu()
{
	system("CLS");
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  TIC TAC TOE  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "                               1. How to Play\n";
	std::cout << "                               2. Scoreboard\n";
	std::cout << "                               3. Credits\n\n\n\n";
	std::cout << "                            Press [Enter] to play...\n";

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
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO PLAY  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "           - Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "           - Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
	std::cout << "           Press any key to continue...";
	int pressedToContinue;
	pressedToContinue = _getch();
	if (pressedToContinue)
	{
		system("CLS");
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO PLAY  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "           - Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO WIN!  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n\n";
		Sleep(1000);
		system("CLS");
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO PLAY  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "           - Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO WIN!  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    | X |               |   |             X |   |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |             X |   |               |   |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n\n";
		Sleep(1000);
		system("CLS");
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO PLAY  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "           - Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO WIN!  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    | X |               |   |             X |   |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    | X |             X | X |               | X |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    |   |               |   |               |   |   \n\n";
		Sleep(1000);
		system("CLS");
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO PLAY  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Two players take turns placing their marker, an [X] or an [O].\n";
		std::cout << "           - Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
		std::cout << "                               +---------------+\n";
		std::cout << "                               |  HOW TO WIN!  |\n";
		std::cout << "                               +---------------+\n\n";
		std::cout << "           - Get three in a row vertically, horizontally or diagonally to win.\n\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    | X |               |   |             X |   |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    | X |             X | X | X             | X |   \n";
		std::cout << "                 ___|___|___         ___|___|___         ___|___|___\n";
		std::cout << "                    |   |               |   |               |   |   \n";
		std::cout << "                    | X |               |   |               |   | X \n";
		std::cout << "                    |   |               |   |               |   |   \n\n";
	}
	else
	{
		std::cout << "           Press any key to continue...";
		_getch();
	}

	std::cout << "           Press any key to return to the main menu...";
	int keyPressed;
	keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "           Press any key to return to the main menu...";
		_getch();
	}
}

void showHighscoreMenu()
{
	system("CLS");
	std::cout << "                                +--------------+\n";
	std::cout << "                                |  SCOREBOARD  |\n";
	std::cout << "                                +--------------+\n\n";
	std::cout << "                          This feature is coming soon!\n\n";

	int keyPressed;
	std::cout << "           Press any key to return to the main menu...";
	keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "           Press any key to return to the main menu...";
		_getch();
	}
}

void showCreditsMenu()
{
	system("CLS");
	std::cout << "                                  +-----------+\n";
	std::cout << "                                  |  CREDITS  |\n";
	std::cout << "                                  +-----------+\n\n";
	std::cout << "                      This game was made by Tessa Power.\n\n";

	int keyPressed;
	std::cout << "           Press any key to return to the main menu...";
		keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "           Press any key to return to the main menu...";
		_getch();
	}
}

void playGame()
{
	setUpGame();
	draw(convertGameStateToVisualRepresentation(gameState));

	do
	{
		if (currentTurn % 2 == 1)
		{
			currentPlayerMark = 'X';
			std::cout << "> Player 1's turn [X]\n";
		}
		else
		{
			currentPlayerMark = 'O';
			std::cout << "> Player 2's turn [O]\n";
		}
		
		getPlayerMove(currentPlayerMark);
		draw(convertGameStateToVisualRepresentation(gameState));
		checkForWin();
		if (gameWon) {
			printWinningMessage();
		}
		else
		{
			currentTurn++;
		}
	} while (currentTurn < maximumPlayerTurns && gameWon == false);

	if (!gameWon)
	{
		std::cout << "           It's a draw! Better luck next time...\n\n";
	}

	askToPlayAgain();
}

void draw(std::string stringToDrawOnScreen) {
	system("CLS");
	std::cout << stringToDrawOnScreen;
}

std::string convertScoreToVisualRepresentation(int playerOneScore, int playerTwoScore)
{
	scoreBoard = "                         Player 1 [X] vs. Player 2 [O]\n\n                                    " + std::to_string(playerOneScore) + "  -  " + std::to_string(playerTwoScore) + "\n\n";
	
	return (scoreBoard);
}

std::string convertGameStateToVisualRepresentation(char gameState[])
{
	gameBoard = "                                     |   |   \n                                    " + std::to_string(gameState[0]+1) + " |  " + std::to_string(gameState[1]+1) + " |  " + std::to_string(gameState[2] + 1) + " \n                                  ___|___|___\n                                     |   |   \n                                   " + std::to_string(gameState[3] + 1) + " | " + std::to_string(gameState[4] + 1) + " | " + std::to_string(gameState[5] + 1) + " \n                                  ___|___|___\n                                     |   |   \n                                   " + std::to_string(gameState[6] + 1) + " | " + std::to_string(gameState[7] + 1) + " | " + std::to_string(gameState[8] + 1) + " \n                                     |   |   \n\n";

	return (gameBoard);
}

void setUpGame()
{
	maximumPlayerTurns = gameBoardSize - 1;
	currentTurn = 1;

	// Reset the gameState by removing all elements from the array
	gameState[gameBoardSize] = { };
}

void askToPlayAgain()
{
	char playerAnswer;
	std::cout << "Do you want to play again? Y/N...\n";
	std::cin >> playerAnswer;

	if (playerAnswer == 'y' || playerAnswer == 'Y') {
		playGame();
	}
	else {
		system("CLS");
	}
}

void getPlayerMove(char currentPlayerMark)
{
	bool validMove = false;
	while (!validMove) {
		std::cin >> playerMove;
		if (checkValidMove(playerMove))
		{
			validMove = true;
			gameState[playerMove-1] = currentPlayerMark;
			break;
		}
		else
		{
			std::cout << "           That spot is already taken! Try again.\n\n";
		}
	}
}

bool checkValidMove(int playerMove)
{
	if (playerMove >= 0 && playerMove < 10 && gameState[playerMove-1] == 'X' || playerMove >= 0 && playerMove < 10 && gameState[playerMove-1] == 'O')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void checkForWin()
{
	GameWinChecker gameWinChecker;
	gameWon = gameWinChecker.checkIfSymbolHasWon(currentPlayerMark, gameState);
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
