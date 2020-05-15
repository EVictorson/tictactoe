#pragma once

#include <stdlib.h>
#include <array>

class GameWinChecker
{
public:
	const bool checkIfSymbolHasWon(char symbol, std::array<char, 9> gameState);

};
