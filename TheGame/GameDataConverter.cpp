#include "GameDataConverter.h"

std::string GameDataConverter::convertGameStateToVisualRepresentation(char gameState[])
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
	

	std::string rowOne = gameState[0] + columnSeparator + gameState[1] + columnSeparator + gameState[2] + "\n";
	std::string rowTwo = gameState[3] + columnSeparator + gameState[4] + columnSeparator + gameState[5] + "\n";
	std::string rowThree = gameState[6] + columnSeparator + gameState[7] + columnSeparator + gameState[8] + "\n";


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