#pragma once

#include <stdlib.h>
#include <string>

class GameDataConverter
{
public:
	std::string convertGameStateToVisualRepresentation(char gameState[]);
	// std::string convertScoreToVisualRepresentation(int playerOneScore, int playerTwoScore);
};

