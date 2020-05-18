#include "MoveValidator.h"

bool MoveValidator::checkIfMoveIsValid(int playerMove, std::array <char, 9> gameState)
{
	return (gameState[playerMove-1] == '\0');
}