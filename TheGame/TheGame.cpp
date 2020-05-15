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

void playGame();
void printIntro();
void printInstructions();

void setUpGame();
void askToPlayAgain();
void getPlayerMove(char currentPlayerMark);
bool checkValidMove(int playerMove);

bool horizontalWin, verticalWin, diagonalWin, gameWon;
void checkForWin(); // using refactored function
void displayGameState(std::array <char, gameBoardSize> gameState); // using refactored function

void printWinningMessage(); // TODO: use draw method to print winning message
void showMenu(); // TODO: use draw method to show menu
void showHighscoreMenu();
void showCreditsMenu();

const int gameBoardSize = 9;
std::array<char, gameBoardSize> gridPositions = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
std::array <char, gameBoardSize> gameState;
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

int main() {
  printIntro();
  showMenu();
  playGame();
}

void printIntro() {
	std::cout << "Let's play...\n\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "Let's play...\n\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "TIC|   |   \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "Let's play...\n\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "TIC|TAC|   \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "Let's play...\n\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "TIC|TAC|TOE!\n";
	std::cout << "___|___|___\n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n";
	std::cout << "   |   |   \n\n";
	Sleep(2000);
	system("CLS");
}

void showMenu() {
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

	while (!validUserInput) {
		if (userInput == '1') {
			validUserInput = true;
			printInstructions();
		}	else if (userInput == '2') {
			validUserInput = true;
			showHighscoreMenu();
		} else if (userInput == '3') {
			validUserInput = true;
			showCreditsMenu();
		}	else if (userInput) {
			validUserInput = true;
			return;
		} else {
			std::cout << "I'm sorry, I don't understand that command. Try again.\a\n";
		}
	}
}

void printInstructions() {
	system("CLS");
	std::cout << "+---------------+\n";
	std::cout << "|  HOW TO PLAY  |\n";
	std::cout << "+---------------+\n\n";
	std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
	std::cout << "Press any key to continue...";
	int pressedToContinue;
	pressedToContinue = _getch();
	if (pressedToContinue) {
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
	std::cout << "+--------------+\n";
	std::cout << "|  SCOREBOARD  |\n";
	std::cout << "+--------------+\n\n";
	std::cout << "This feature is coming soon!\n\n";

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
	std::cout << "+-----------+\n";
	std::cout << "|  CREDITS  |\n";
	std::cout << "+-----------+\n\n";
	std::cout << "This game was made by Tessa Power.\n\n";

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
	} while (currentTurn < maximumPlayerTurns && !gameWon);

	if (!gameWon) {
		std::cout << "It's a draw! Better luck next time...\n\n";
	}

	askToPlayAgain();
}

void setUpGame() {
	maximumPlayerTurns = gameBoardSize - 1;
	currentTurn = 1;

  if (playerAnswer == 'y' || playerAnswer == 'Y') {
    playGame();
  } else {
    system("CLS");
  }
	// Populate the grid spaces with place holder numbers
	for (int i = 0; i < gameBoardSize; i++) {

		gameState[i] = gridPositions[i];
	}
}

void getPlayerMove(char currentPlayerMark) {
  bool validMove = false;
  while (!validMove) {
    std::cin >> playerMove;
    if (checkValidMove(playerMove)) {
      validMove = true;
      gridLabels[playerMove] = currentPlayerMark;
      break;
    } else {
      std::cout << "           That spot is already taken! Try again.\n\n";
    }
  }
}

bool checkValidMove(int playerMove) {
  if (playerMove > 0 && playerMove < 10 && gridLabels[playerMove] == 'X' ||
      playerMove > 0 && playerMove < 10 && gridLabels[playerMove] == 'O') {
    std::cout << "That doesn't seem right. Try again.\n";
    return false;
  } else {
    return true;
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

void displayGameState(std::array <char, gameBoardSize> gameState)
{
	GameDataConverter gameDataConverter;
	std::cout << gameDataConverter.convertGameStateToVisualRepresentation(gameState);
}

