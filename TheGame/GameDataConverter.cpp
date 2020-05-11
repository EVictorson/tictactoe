#include "GameDataConverter.h"

std::string GameDataConverter::convertGameStateToVisualRepresentation(char gameState[])
{
	// Access the value of the array element instead of the ASCII number of the value

	char* positions[9];

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



	std::string gameBoard = R"(
   |   |
 )" + std::to_string(gameState[0]) + " | " + std::to_string(gameState[1]) + " | " + std::to_string(gameState[2]) + R"(
___|___|___
   |   |
 )" + std::to_string(gameState[3]) + " | " + std::to_string(gameState[4]) + " | " + std::to_string(gameState[5]) + R"(
___|___|___
   |   |
 )" + std::to_string(gameState[6]) + " | " + std::to_string(gameState[7]) + " | " + std::to_string(gameState[8]) + R"(
   |   |
)";

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