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
			std::array <char, 9> gameState = {
				'1', '2', '3',
				'4', '5', '6',
				'7', '8', '9',
				};

			std::string expectedGameBoard = R"(
			   |   |
			 1 | 2 | 3
			___|___|___
			   |   |
			 4 | 5 | 6
			___|___|___
			   |   |
			 7 | 8 | 9
			   |   |
			)";

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

			std::string expectedGameBoard = R"(
			   |   |
			 X | O | X
			___|___|___
			   |   |
			 X | X | O
			___|___|___
			   |   |
			 O | X | O
			   |   |
			)";

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

			std::string expectedGameBoard = R"(
			   |   |
			 X | 2 | 3
			___|___|___
			   |   |
			 O | O | 6
			___|___|___
			   |   |
			 X | X | X
			   |   |
			)";

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

			std::string expectedGameBoard = R"(
			   |   |
			 X | 2 | O
			___|___|___
			   |   |
			 O | 5 | 6
			___|___|___
			   |   |
			 7 | 8 | X
			   |   |
			)";

			// Act
			GameDataConverter gameDataConverter;
			std::string gameBoard = gameDataConverter.convertGameStateToVisualRepresentation(gameState);

			// Assert
			Assert::AreEqual(expectedGameBoard, gameBoard);
		}
	};
}