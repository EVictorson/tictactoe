
#include "GameWinChecker.h"

const bool GameWinChecker::checkIfSymbolHasWon(char symbol, char gameState[])
{
	bool horizontalWin = (gameState[0] == symbol && gameState[1] == symbol && gameState[2] == symbol ||
		gameState[3] == symbol && gameState[4] == symbol && gameState[5] == symbol ||
		gameState[6] == symbol && gameState[7] == symbol && gameState[8] == symbol);

	bool verticalWin = (gameState[0] == symbol && gameState[3] == symbol && gameState[6] == symbol ||
		gameState[1] == symbol && gameState[4] == symbol && gameState[7] == symbol ||
		gameState[2] == symbol && gameState[5] == symbol && gameState[8] == symbol);

	bool diagonalWin = (gameState[0] == symbol && gameState[4] == symbol && gameState[8] == symbol ||
		gameState[2] == symbol && gameState[4] == symbol && gameState[6] == symbol);

	return (horizontalWin || verticalWin || diagonalWin);
}
