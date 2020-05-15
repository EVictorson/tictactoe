#pragma once

#include <stdlib.h>
#include <string>
#include <array>

class GameDataConverter
{
public:
	std::string convertGameStateToVisualRepresentation(std::array <char, 9> gameState);
	// std::string convertScoreToVisualRepresentation(int playerOneScore, int playerTwoScore);
};

