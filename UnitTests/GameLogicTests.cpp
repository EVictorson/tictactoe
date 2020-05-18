#include "pch.h"
#include "CppUnitTest.h"
#include "../TheGame/GameWinChecker.h"
#include "../TheGame/MoveValidator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameLogicTests
{
	TEST_CLASS(checkIfSymbolHasWon)
	{
	public:

		TEST_METHOD(ExpectWon_SymbolFillsHorizontalRow_WinningSymbol)
		{
			// Arrange
			char symbol = 'X';
			std::array<char, 9> gameState = {
				'\0', 'O', '\0',
				'X', 'X', 'X',
				'\0', '\0', 'O'
			};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsTrue(gameWon, L"More information here...");
		}

		TEST_METHOD(ExpectWon_SymbolFillsVerticalRow_WinningSymbol)
		{
			// Arrange
			char symbol = 'X';
			std::array<char, 9> gameState = {
				'O', 'X', '\0',
				'\0', 'X', '\0',
				'O', 'X', '\0'
			};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsTrue(gameWon, L"More information here...");
		}

		TEST_METHOD(ExpectWon_SymbolFillsDiagonalRow_WinningSymbol)
		{
			// Arrange
			char symbol = 'X';
			std::array<char, 9> gameState = {
				'X', '\0', '\0',
				'O', 'X', '\0',
				'X', 'O', 'X'
			};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsTrue(gameWon, L"More information here...");
		}

		TEST_METHOD(ExpectNotWon_GameStateEmpty)
		{
			// Arrange
			char symbol = 'X';
			std::array<char, 9> gameState = { };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);


			// Assert
			Assert::IsFalse(gameWon, L"More information here...");
		}

		TEST_METHOD(ExpectNotWon_GameStateDraw)
		{
			// Arrange
			char symbol = 'X';
			std::array<char, 9> gameState = {
				'X', 'O', 'X',
				'X', 'X', 'O',
				'O', 'X', 'O'
			};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"More information here...");
		}

		TEST_METHOD(ExpectNotWon_GameStateContainsNoWin)
		{
			// Arrange
			char symbol = 'X';
			std::array<char, 9> gameState = {
				'X', '\0', '\0',
				'\0', 'O', '\0',
				'\0', '\0', '\0'
			};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"More information here...");
		}
		
		TEST_METHOD(ExpectNotWon_GameStateContainsWin_SymbolIsNotWinningSymbol)
		{
			// Arrange
			char symbol = 'O';
			std::array<char, 9> gameState = {
				'X', '\0', '\0',
				'\0', 'X', '\0',
				'X', 'O', 'X'
			};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"More information here...");
		}

	};

	TEST_CLASS(checkIfMoveIsValid)
	{
	public:

		TEST_METHOD(ExpectValid_GameStateEmpty)
		{
			// Arrange
			int playerMove = 4;
			std::array<char, 9> gameState { };

			// Act
			MoveValidator moveValidator;
			bool moveIsValid = moveValidator.checkIfMoveIsValid(playerMove, gameState);

			// Assert
			Assert::IsTrue(moveIsValid, L"More information here...");
		}

		TEST_METHOD(ExpectValid_GameStateNoWin_SomeMovesMade)
		{
			// Arrange
			int playerMove = 4;
			std::array<char, 9> gameState = {
				'X', '\0', '\0',
				'\0', 'O', '\0',
				'\0', '\0', '\0'
			};

			// Act
			MoveValidator moveValidator;
			bool moveIsValid = moveValidator.checkIfMoveIsValid(playerMove, gameState);

			// Assert
			Assert::IsTrue(moveIsValid, L"More information here...");
		}

		TEST_METHOD(ExpectInvalid_GameStateNoWin_SomeMovesMade)
		{
			// Arrange
			int playerMove = 1;
			std::array<char, 9> gameState = {
				'X', '\0', '\0',
				'\0', 'O', '\0',
				'\0', '\0', '\0'
			};

			// Act
			MoveValidator moveValidator;
			bool moveIsValid = moveValidator.checkIfMoveIsValid(playerMove, gameState);

			// Assert
			Assert::IsFalse(moveIsValid, L"More information here...");
		}
	};
}
