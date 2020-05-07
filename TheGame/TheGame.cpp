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
#include "GameWinChecker.h"

void playGame();
void printIntro();
void printInstructions();
void drawCurrentGameState();
void setUpGame();
void askToPlayAgain();
void getPlayerMove(char currentPlayerMark);
bool checkValidMove(int playerMove);
void checkForWin();
void printWinningMessage();
void showMenu();
void showScoreboard();
void showCredits();

const int gridSize = 11;
char gridPositions[gridSize] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };
char gridLabels[gridSize];
bool horizontalWin, verticalWin, diagonalWin, gameWon;
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

void showMenu() {
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

  while (!validUserInput) {
    if (userInput == '1') {
      validUserInput = true;
      printInstructions();
    } else if (userInput == '2') {
      validUserInput = true;
      showScoreboard();
    } else if (userInput == '3') {
      validUserInput = true;
      showCredits();
    } else if (userInput) {
      validUserInput = true;
      return;
    } else {
      std::cout << "I'm sorry, I don't understand that command. Try again.\n";
    }
  }
}

void printInstructions() {
  //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  //SetConsoleTextAttribute(hConsole, 2);

  system("CLS");
  std::cout << "                               +---------------+\n";
  std::cout << "                               |  HOW TO PLAY  |\n";
  std::cout << "                               +---------------+\n\n";
  std::cout << "           - Two players take turns placing their marker, an [X] or an [O].\n";
  std::cout << "           - Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
  std::cout << "           Press any key to continue...";
  int pressedToContinue;
  pressedToContinue = _getch();
  if (pressedToContinue) {
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
  } else {
    std::cout << "           Press any key to continue...";
    _getch();
  }

  std::cout << "           Press any key to return to the main menu...";
  int keyPressed;
  keyPressed = _getch();
  if (keyPressed) {
    showMenu();
  } else {
    std::cout << "           Press any key to return to the main menu...";
    _getch();
  }
}

void showScoreboard() {
  system("CLS");
  std::cout << "                                +--------------+\n";
  std::cout << "                                |  SCOREBOARD  |\n";
  std::cout << "                                +--------------+\n\n";
  std::cout << "                          This feature is coming soon!\n\n";

  int keyPressed;
  std::cout << "           Press any key to return to the main menu...";
  keyPressed = _getch();
  if (keyPressed) {
    showMenu();
  } else {
    std::cout << "           Press any key to return to the main menu...";
    _getch();
  }
}

void showCredits() {
  system("CLS");
  std::cout << "                                  +-----------+\n";
  std::cout << "                                  |  CREDITS  |\n";
  std::cout << "                                  +-----------+\n\n";
  std::cout << "              This game was made by Tessa Power.\n\n";

  int keyPressed;
  std::cout << "           Press any key to return to the main menu...";
    keyPressed = _getch();
  if (keyPressed) {
    showMenu();
  } else {
    std::cout << "           Press any key to return to the main menu...";
    _getch();
  }
}

<<<<<<< HEAD
void playGame() {
  setUpGame();
  drawCurrentGameState();

  do {
    if (currentTurn % 2 == 1) {
      currentPlayerMark = 'X';
      std::cout << "> Player 1's turn [X]\n";
    } else {
      currentPlayerMark = 'O';
      std::cout << "> Player 2's turn [O]\n";
    }
    
    getPlayerMove(currentPlayerMark);
    drawCurrentGameState();
    checkForWin();
    if (gameWon) {
      printWinningMessage();
    } else {
      currentTurn++;
    }
  } while (currentTurn < playerTurns && gameWon == false);

  if (!gameWon) {
    std::cout << "           It's a draw! Better luck next time...\n\n";
  }

  askToPlayAgain();
=======
void playGame()
{
	setUpGame();
	draw(convertGameStateToVisualRepresentation(gameState));

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
		draw(convertGameStateToVisualRepresentation(gameState));
		checkForWin();
		if (gameWon) {
			printWinningMessage();
		}
		else
		{
			currentTurn++;
		}
	} while (currentTurn < maximumPlayerTurns && !gameWon);

	if (!gameWon)
	{
		std::cout << "           It's a draw! Better luck next time...\n\n";
	}

	askToPlayAgain();
>>>>>>> Rename currentPlayerMark variable to symbol
}

void drawCurrentGameState() {
  scoreBoard = "                         Player 1 [X] vs. Player 2 [O]\n\n                                    " + std::to_string(playerOneScore) + "  -  " + std::to_string(playerTwoScore) + "\n\n";
  
  return (scoreBoard);
}

std::string convertGameStateToVisualRepresentation(char gameState[]) {
  gameBoard = "                                     |   |   \n                                    " + std::to_string(1) + " |  " + std::to_string(2) + " |  " + std::to_string(3) + " \n                                  ___|___|___\n                                     |   |   \n                                   " + std::to_string(4) + " | " + std::to_string(5) + " | " + std::to_string(6) + " \n                                  ___|___|___\n                                     |   |   \n                                   " + std::to_string(7) + " | " + std::to_string(8) + " | " + std::to_string(9) + " \n                                     |   |   \n\n";

  return (gameBoard);
}

void setUpGame() {
  playerTurns = gridSize - 1;
  currentTurn = 1;

  // Populate the grid spaces with place holder numbers
  for (int i = 0; i < gridSize; i++) {
    gridLabels[i] = gridPositions[i];
  }
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

