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
				'1', 'O', '3',
				'X', 'X', 'X',
				'7', '8', 'O',
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
				'O', 'X', '3',
				'4', 'X', '6',
				'O', 'X', '9',
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
				'X', '2', '3',
				'O', 'X', '6',
				'X', 'O', 'X',
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
			std::array<char, 9> gameState = {
				'1', '2', '3',
				'4', '5', '6',
				'7', '8', '9',
			};

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
				'O', 'X', 'O',
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
				'X', '2', '3',
				'4', 'O', '6',
				'7', '8', '9',
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
				'X', '2', '3',
				'O', 'X', '6',
				'X', 'O', 'X',
			};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"More information here...");
		}

	};
}
