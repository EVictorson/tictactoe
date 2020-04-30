// TheGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>

void playGame();
void printIntro();
void printInstructions();
void drawCurrentGameState();
void resetGame();
void askToPlayAgain();
void checkForWin();
void printWinningMessage();
void showMenu();
void showScoreboard();
void showCredits();

const int gridSize = 11;
char gridPositions[gridSize] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };
char gridLabels[gridSize];
bool gameWon;
int playerTurns;
int currentTurn;
char userInput;
bool validUserInput;

int main()
{
	printIntro();
	showMenu();
	playGame();
	askToPlayAgain();
}

void printIntro()
{
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "   TIC|   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "   TIC|TAC|   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "   TIC|TAC|TOE!\n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(2000);
	system("CLS");
}

void printInstructions()
{
	system("CLS");
	std::cout << "HOW TO PLAY\n";
	std::cout << "--------------------------------------------------------------------------\n\n";
	std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n";
	std::cout << "- Type a number on the grid and press \'Enter\' to place your mark there.\n\n";
	std::cout << "Type [B] and press \'Enter\' to return to the main menu.\n";

	std::cin >> userInput;

	if (userInput == 'B') {
		showMenu();
	}
	else
	{
		std::cout << "I'm sorry, I don't understand that command. Try again.\n";
	}
	
}

void showMenu()
{
	std::cout << "TIC TAC TOE GAME\n\n";
	std::cout << "- Play New Game [N]\n";
	std::cout << "- How to Play [P]\n";
	std::cout << "- Scoreboard [S]\n";
	std::cout << "- Credits [C]\n\n";

	validUserInput = false;

	while (!validUserInput) {
		std::cin >> userInput;
		if (userInput == 'P' || userInput == 'p')
		{
			printInstructions();
			validUserInput = true;
		}
		else if (userInput == 'S' || userInput == 's')
		{
			showScoreboard();
			validUserInput = true;
		}
		else if (userInput == 'C' || userInput == 'c')
		{
			validUserInput = true;
			showCredits();
		}
		else if (userInput == 'N' || userInput == 'n')
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

void showScoreboard()
{
	system("CLS");
	std::cout << "SCOREBOARD\n";
	std::cout << "--------------------------------------------------------------------------\n\n";
	std::cout << "This feature is coming soon!\n";
	std::cout << "Type [B] and press \'Enter\' to return to the main menu.\n";
	std::cin >> userInput;
	if (userInput == 'B') {
		system("CLS");
		showMenu();
	}
	else
	{
		std::cout << "I'm sorry, I don't understand that command. Try again.\n";
	}
}

void showCredits()
{
	system("CLS");
	std::cout << "CREDITS\n";
	std::cout << "--------------------------------------------------------------------------\n\n";
	std::cout << "This game was made by Tessa Power.\n";
	std::cout << "Type [B] and press \'Enter\' to return to the main menu.\n";
	std::cin >> userInput;
	if (userInput == 'B') {
		system("CLS");
		showMenu();
	}
	else
	{
		std::cout << "I'm sorry, I don't understand that command. Try again.\n";
	}
}

void playGame()
{
	resetGame();
	drawCurrentGameState();

	do
	{
		char currentPlayerMark;
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

		int playerChoice;
		std::cin >> playerChoice;

		if (playerChoice > 0 && playerChoice < 10)
		{
			gridLabels[playerChoice] = currentPlayerMark;
		}
		else
		{
			std::cout << "That doesn't seem right! Try again.\n\n";
		}

		drawCurrentGameState();
		checkForWin();
		if (gameWon) {
			printWinningMessage();
			break;
		}
		else
		{
			currentTurn++;
		}
	} while (currentTurn < playerTurns && gameWon == false);

	std::cout << "Total turns taken: " << currentTurn << std::endl;
	std::cout << "gameWon was " << gameWon << std::endl;
}

void drawCurrentGameState()
{
	std::cout << "Player 1 [X] vs. Player 2 [O]\n\n";

	std::cout << "      |   |   \n";
	std::cout << "    " << gridLabels[1] << " | " << gridLabels[2] << " | " << gridLabels[3] << " \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "    " << gridLabels[4] << " | " << gridLabels[5] << " | " << gridLabels[6] << " \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "    " << gridLabels[7] << " | " << gridLabels[8] << " | " << gridLabels[9] << " \n";
	std::cout << "      |   |   \n\n";
}

void resetGame()
{
	system("CLS");
	playerTurns = gridSize-1;
	currentTurn = 1;

	// Populate the grid spaces with numbers again
	for (int i = 0; i < gridSize; i++) {

		gridLabels[i] = gridPositions[i];
	}
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

void checkForWin()
{
	if ((gridLabels[1] == gridLabels[2]) && (gridLabels[2] == gridLabels[3]) ||
		(gridLabels[4] == gridLabels[5]) && (gridLabels[5] == gridLabels[6]) ||
		(gridLabels[7] == gridLabels[8]) && (gridLabels[8] == gridLabels[9]) ||
		(gridLabels[1] == gridLabels[4]) && (gridLabels[4] == gridLabels[7]) ||
		(gridLabels[2] == gridLabels[5]) && (gridLabels[5] == gridLabels[8]) ||
		(gridLabels[3] == gridLabels[6]) && (gridLabels[6] == gridLabels[9]) ||
		(gridLabels[1] == gridLabels[5]) && (gridLabels[5] == gridLabels[9]) ||
		(gridLabels[3] == gridLabels[5]) && (gridLabels[5] == gridLabels[7]))
	{
		gameWon = true;
	}
	else
	{
		gameWon = false;
	}
}

void printWinningMessage()
{
	std::cout << "You won!" << std::endl;
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
