#include "GameDataConverter.h"

std::string GameDataConverter::convertGameStateToVisualRepresentation(std::array <char, 9> gameState)
{
	/*
	The string below will be populated either with placeholder numbers if
	no moves have been made or the symbol of a player who has made a move,
	e.g.

	       Empty:     |   |                   Moves     |   |
	                1 | 2 | 3                 Made:   1 | X | 3
	               ___|___|___                       ___|___|___
	                  |   |                             |   |
	                4 | 5 | 6                         4 | 5 | O
	               ___|___|___                       ___|___|___
	                  |   |                             |   |
	                7 | 8 | 9                         X | 8 | 9
	                  |   |                             |   |
	*/

	std::string edgeOfGameBoard = "   |   |\n ";
	std::string rowSeparator = "___|___|___\n   |   |\n ";
	std::string columnSeparator = " | ";


	std::array <std::string, 9> displayData{};

	/* If the gameState contains a symbol in any position, assign that symbol to
	the corresponding position in the display data array, or assign a placeholder number.
	*/
	for (int index = 0; index < 9; index++)
	{
		if (gameState[index] != '\0')
		{
			displayData[index] = gameState[index];
		}
		else
		{
			displayData[index] = std::to_string(index + 1);
		}
	}

	// Create strings for each row from the display data
	std::string rowOne = displayData[0] + columnSeparator + displayData[1] + columnSeparator + displayData[2] + "\n";
	std::string rowTwo = displayData[3] + columnSeparator + displayData[4] + columnSeparator + displayData[5] + "\n";
	std::string rowThree = displayData[6] + columnSeparator + displayData[7] + columnSeparator + displayData[8] + "\n";
	
	// Create one gameboard string from all row strings and return it to be printed to the SO
	std::string gameBoard = edgeOfGameBoard + rowOne + rowSeparator + rowTwo + rowSeparator + rowThree + edgeOfGameBoard;
	return (gameBoard);
}

//std::string GameDataConverter::convertScoreToVisualRepresentation(int playerOneScore, int playerTwoScore)
//{
//	std::string p1 = std::to_string(playerOneScore);
//	std::string p2 = std::to_string(playerTwoScore);
//	scoreBoard = R"(                         Player 1 [X] vs. Player 2 [O]\n\n)"
				//+ "                         " + p1 + "  -  " + p2 + "\n\n";
//	
//	return (scoreBoard);
//}