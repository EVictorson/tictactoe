#pragma once
#include <stdlib.h>
#include "Animator.h"
#include <array>
#include <iostream>
#include <string>

class MenuDisplayer
{
public:

    void displayMainMenu();
    void displaySubmenu(int userInput);

    // Main Menu
	
//	const std::string mainMenuStep1 = R"(\
//+---------------+
//|  TIC TAC TOE  |
//+---------------+
//)";
//
//    const std::string mainMenuStep2 = R"(\
//+---------------+
//|  TIC TAC TOE  |
//+---------------+
//1. How to Play
//)";
//
//    const std::string mainMenuStep3 = R"(\
//+---------------+
//|  TIC TAC TOE  |
//+---------------+
//1. How to Play
//2. Scoreboard
//)";
//
//    const std::string mainMenuStep4 = R"(\
//+---------------+
//|  TIC TAC TOE  |
//+---------------+
//1. How to Play
//2. Scoreboard
//3. Credits
//)";

    const std::string mainMenu = R"(\
+---------------+
|  TIC TAC TOE  |
+---------------+
1. How to Play
2. Scoreboard
3. Credits



Press [Enter] to play...)";

    //const std::array <std::string, 5> mainMenu{ mainMenuStep1, mainMenuStep2, mainMenuStep3, mainMenuStep4, mainMenuStep5 };

    // Return to Main Menu string

    const std::string returnToMainMenu = "Press any key to return to the main menu...";
    
    // How to Play Submenu

//    const std::string howToPlayMenuStep1 = R"(
//+---------------+
//|  HOW TO PLAY  |
//+---------------+
//
//- Two players take turns placing their marker, an [X] or an [O].
//- Type a number on the grid and press \'Enter\' to place your marker there.
//)";
//
//    const std::string howToPlayMenuStep2 = R"(
//+---------------+
//|  HOW TO PLAY  |
//+---------------+
//
//- Two players take turns placing their marker, an [X] or an [O].
//- Type a number on the grid and press \'Enter\' to place your marker there.
//
//+---------------+
//|  HOW TO WIN!  |
//+---------------+
//
//- Get three in a row vertically, horizontally or diagonally to win.
//
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//___|___|___         ___|___|___         ___|___|___
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//___|___|___         ___|___|___         ___|___|___
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//)";
//
//    const std::string howToPlayMenuStep3 = R"(
//+---------------+
//|  HOW TO PLAY  |
//+---------------+
//
//- Two players take turns placing their marker, an [X] or an [O].
//- Type a number on the grid and press \'Enter\' to place your marker there.
//
//+---------------+
//|  HOW TO WIN!  |
//+---------------+
//
//- Get three in a row vertically, horizontally or diagonally to win.
//
//   |   |               |   |               |   |
//   | X |               |   |             X |   |
//___|___|___         ___|___|___         ___|___|___
//   |   |               |   |               |   |
//   |   |             X |   |               |   |
//___|___|___         ___|___|___         ___|___|___
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//)";
//
//    const std::string howToPlayMenuStep4 = R"(
//+---------------+
//|  HOW TO PLAY  |
//+---------------+
//
//- Two players take turns placing their marker, an [X] or an [O].
//- Type a number on the grid and press \'Enter\' to place your marker there.
//
//+---------------+
//|  HOW TO WIN!  |
//+---------------+
//
//- Get three in a row vertically, horizontally or diagonally to win.
//
//   |   |               |   |               |   |
//   | X |               |   |             X |   |
//___|___|___         ___|___|___         ___|___|___
//   |   |               |   |               |   |
//   | X |             X | X |               | X |
//___|___|___         ___|___|___         ___|___|___
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//   |   |               |   |               |   |
//)";

    const std::string howToPlayMenu = R"(
+---------------+
|  HOW TO PLAY  |
+---------------+

- Two players take turns placing their marker, an [X] or an [O].
- Type a number on the grid and press \'Enter\' to place your marker there.

+---------------+
|  HOW TO WIN!  |
+---------------+

- Get three in a row vertically, horizontally or diagonally to win.

   |   |               |   |               |   |
   | X |               |   |             X |   |
___|___|___         ___|___|___         ___|___|___
   |   |               |   |               |   |
   | X |             X | X | X             | X |
___|___|___         ___|___|___         ___|___|___
   |   |               |   |               |   |
   |   | X             |   |               |   | X
   |   |               |   |               |   |


)";

    //const std::array <std::string, 5> howToPlayMenu { howToPlayMenuStep1, howToPlayMenuStep2, howToPlayMenuStep3, howToPlayMenuStep4 };

    // Highscore submenu

    const std::string highscoreMenu = R"(
+--------------+\
|  SCOREBOARD  |
+--------------+

This feature is coming soon!

)";

    //const std::array <std::string, 5> highscoreMenu { highscoreMenuStep1 };

    // Credits submenu

    const std::string creditsMenu = R"(
+-----------+
|  CREDITS  |
+-----------+

Made by Tessa Power.
Github: tessapower
Email: tessa@tessapower.co

)";

    //const std::array <std::string, 5> creditsMenu { creditsMenuStep1 };

};
