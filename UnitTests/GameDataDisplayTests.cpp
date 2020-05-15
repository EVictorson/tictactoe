#include "pch.h"
#include "CppUnitTest.h"
#include "../TheGame/GameDataConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameDataDisplayTests
{
	TEST_CLASS(convertGameStateToVisualRepresentation)
	{
	public:

		TEST_METHOD(ExpectSame_GameStateEmpty_PlaceHoldersOnly) // TODO: rename test
		{
			// Arrange
			std::array <char, 9> gameState;

			std::string expectedGameBoard = "   |   |\n 1 | 2 | 3\n___|___|___\n   |   |\n 4 | 5 | 6\n___|___|___\n   |   |\n 7 | 8 | 9\n   |   |\n ";

			// Act
			GameDataConverter gameDataConverter;
			std::string gameBoard = gameDataConverter.convertGameStateToVisualRepresentation(gameState);


			// Assert
			Assert::AreEqual(expectedGameBoard, gameBoard);
		}

		TEST_METHOD(ExpectSame_GameStateDraw_NoPlaceholders) // TODO: rename test
		{
			// Arrange
			std::array <char, 9> gameState = {
				'X', 'O', 'X',
				'X', 'X', 'O',
				'O', 'X', 'O',
				};

			std::string expectedGameBoard = "   |   |\n X | O | X\n___|___|___\n   |   |\n X | X | O\n___|___|___\n   |   |\n O | X | O\n   |   |\n ";

			// Act
			GameDataConverter gameDataConverter;
			std::string gameBoard = gameDataConverter.convertGameStateToVisualRepresentation(gameState);

			// Assert
			Assert::AreEqual(expectedGameBoard, gameBoard);
		}

		TEST_METHOD(ExpectSame_GameStateWon_SomePlaceholders) // TODO: rename test
		{
			// Arrange
			std::array <char, 9> gameState = {
				'X', '2', '3',
				'O', 'O', '6',
				'X', 'X', 'X',
				};

			std::string expectedGameBoard = "   |   |\n X | 2 | 3\n___|___|___\n   |   |\n O | O | 6\n___|___|___\n   |   |\n X | X | X\n   |   |\n ";

			// Act
			GameDataConverter gameDataConverter;
			std::string gameBoard = gameDataConverter.convertGameStateToVisualRepresentation(gameState);

			// Assert
			Assert::AreEqual(expectedGameBoard, gameBoard);
		}

		TEST_METHOD(ExpectSame_GameStateNoWin_SomePlaceholders) // TODO: rename test
		{
			// Arrange
			std::array <char, 9> gameState = {
				'X', '2', 'O',
				'O', '5', '6',
				'7', '8', 'X',
				};

			std::string expectedGameBoard = "   |   |\n X | 2 | O\n___|___|___\n   |   |\n O | 5 | 6\n___|___|___\n   |   |\n 7 | 8 | X\n   |   |\n ";

			// Act
			GameDataConverter gameDataConverter;
			std::string gameBoard = gameDataConverter.convertGameStateToVisualRepresentation(gameState);

			// Assert
			Assert::AreEqual(expectedGameBoard, gameBoard);
		}
	};
}