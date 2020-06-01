#include "pch.h"
#include "CppUnitTest.h"
#include "../TheGame/Menu.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameMenuTests
{
	TEST_CLASS(getUserInput)
	{
	public:

		TEST_METHOD(ExpectTrue_UserInputValid)
		{
			// Arrange
			int userInput = 3;
			std::array <int, 3> submenuOptions{ 1, 2, 3 };

			// Act
			Menu menu;
			bool userInputIsValid = menu.validateUserInput(userInput, submenuOptions);

			// Assert
			Assert::IsTrue(userInputIsValid, L"More information here...");
		}

		TEST_METHOD(ExpectFalse_UserInputInvalid)
		{
			// Arrange
			int userInput = 9;
			std::array <int, 3> submenuOptions{ 1, 2, 3 };

			// Act
			Menu menu;
			bool userInputIsValid = menu.validateUserInput(userInput, submenuOptions);

			// Assert
			Assert::IsFalse(userInputIsValid, L"More information here...");
		}

		TEST_METHOD(ExpectTrue_UserPressedEnter)
		{
			// Arrange
			int userInput = 10; // Ascii code for "Enter"
			std::array <int, 3> submenuOptions{ 1, 2, 3 };

			// Act
			Menu menu;
			bool userInputIsValid = menu.validateUserInput(userInput, submenuOptions);

			// Assert
			Assert::IsTrue(userInputIsValid, L"More information here...");
		}
	};

}