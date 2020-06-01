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
void showHighscoreMenu();
void showCreditsMenu();

void setUpGame();
void askToPlayAgain();
void getPlayerMove(char playerSymbol); // using refactored function

bool horizontalWin, verticalWin, diagonalWin, gameWon;
void checkForWin(); // using refactored function
const int gameBoardSize = 9;
void displayGameState(std::array <char, gameBoardSize> gameState); // using refactored function
void printWinningMessage();

std::array <char, gameBoardSize> gameState { };
std::string gameBoard;
std::string scoreBoard;
int playerMove;
int playerTurns;
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

void showMenu() {
	system("CLS");
	// Main Menu String
}

void printInstructions() {
	system("CLS");
	// How to Play String
	int pressedToContinue;
	pressedToContinue = _getch();
	if (pressedToContinue) {
		system("CLS");
		// how to win string
	} else {
		std::cout << "Press any key to continue...";
		_getch();
	}

	std::cout << "Press any key to return to the main menu...";
	int keyPressed;
	keyPressed = _getch();
	if (keyPressed) {
		showMenu();
	} else {
		std::cout << "Press any key to return to the main menu...";
		_getch();
	}
}

void showHighscoreMenu() {
	system("CLS");
	// highscore menu string

	int keyPressed;
	std::cout << "Press any key to return to the main menu...";
	keyPressed = _getch();
	if (keyPressed) {
		showMenu();
	} else {
		std::cout << "Press any key to return to the main menu...";
		_getch();
	}
}

void showCreditsMenu() {
	system("CLS");
	// Credits submenu string

	int keyPressed;
	std::cout << "Press any key to return to the main menu...";
		keyPressed = _getch();
	if (keyPressed) {
		showMenu();
	} else {
		std::cout << "Press any key to return to the main menu...";
		_getch();
	}
}

void playGame() {
	setUpGame();
	displayGameState(gameState);

	do {
		if (currentTurn % 2 == 1) {
			symbol = 'X';
			std::cout << "> Player 1's turn [X]\n";
		} else {
			symbol = 'O';
			std::cout << "> Player 2's turn [O]\n";
		}
		
		getPlayerMove(symbol);
		displayGameState(gameState);
		checkForWin();
		if (gameWon) {
			printWinningMessage();
		} else {
			currentTurn++;
		}
	} while (currentTurn != maximumPlayerTurns + 1 && !gameWon);

	if (!gameWon) {
		std::cout << "\nIt's a draw! Better luck next time...\n\n";
	}

	askToPlayAgain();
}

void setUpGame() {
	maximumPlayerTurns = gameBoardSize;
	currentTurn = 1;

  if (playerAnswer == 'y' || playerAnswer == 'Y') {
    playGame();
  } else {
    system("CLS");
  }
	// Populate the grid spaces with place holder numbers
	//for (int i = 0; i < gameBoardSize; i++) {

	//	gameState[i] = gridPositions[i];
	//}
}

void askToPlayAgain() {
	char playerAnswer;
	std::cout << "Do you want to play again? Y/N...\n";
	std::cin >> playerAnswer;

	if (playerAnswer == 'y' || playerAnswer == 'Y') {
		playGame();
	} else {
		system("CLS");
	}
}

void getPlayerMove(char playerSymbol) {
	bool moveAccepted = false;
	MoveValidator moveValidator;

	while (!moveAccepted) {
		std::cin >> playerMove;
		bool moveIsValid = moveValidator.checkIfMoveIsValid(playerMove, gameState);
		if (moveIsValid) {
			moveAccepted = true;
			gameState[playerMove-1] = playerSymbol;
			break;
		} else {
			std::cout << "That spot is already taken! Try again.\n\n";
		}
	}
}

void printWinningMessage() {
  if (currentTurn % 2 == 1) {
    std::cout << "> Player 1 wins! [X]\n\n";
    playerOneScore++;
  } else {
    std::cout << "> Player 2 wins! [O]\n\n";
    playerTwoScore++;
  }
}

void checkForWin() {
	GameWinChecker gameWinChecker;
	gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);
}

void displayGameState(std::array <char, gameBoardSize> gameState) {
	system("CLS");
	GameDataConverter gameDataConverter;
	std::cout << gameDataConverter.convertGameStateToVisualRepresentation(gameState);
}

