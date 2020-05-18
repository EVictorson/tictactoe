#pragma once

#include <stdlib.h>
#include <array>

class MoveValidator
{
public:
	bool checkIfMoveIsValid(int playerMove, std::array <char, 9> gameState);
};

