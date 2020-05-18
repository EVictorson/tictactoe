#include "pch.h"
#include "CppUnitTest.h"
#include "../TheGame/GameWinChecker.h"

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
}
