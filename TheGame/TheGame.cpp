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
#include "Menu.h"
#include "menuDisplayer.h"
#include "GameWinChecker.h"
#include "GameDataConverter.h"
#include "MoveValidator.h"
#include "Animator.h"

void playGame();
void printIntro(); // using refactored function
void showMenu();

void setUpGame();
void askToPlayAgain();
void getPlayerMove(char playerSymbol); // using refactored function

void checkForWin(); // using refactored function
const int gameBoardSize = 9;
void displayGameState(std::array <char, gameBoardSize> gameState); // using refactored function

void printWinningMessage();

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

int main()
{
	printIntro();
	showMenu();
	playGame();
}

void printIntro()
{
	Animator animator;
	animator.animate(animator.introSequence);
}

void showMenu()
{
	Menu menu;
	MenuDisplayer menuDisplayer;

	menuDisplayer.displayMainMenu();
	int userInput = menu.getUserInput();
	menu.navigateToSubmenu(userInput);
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
