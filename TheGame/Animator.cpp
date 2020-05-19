#include "Animator.h"

void Animator::introduceGame()
{
	std::string step1 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
   |   |
___|___|___
   |   |
   |   |
   |   |
)";

	std::string step2 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
TIC|   |
___|___|___
   |   |
   |   |
   |   |
)";

	std::string step3 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
TIC|TAC|
___|___|___
   |   |
   |   |
   |   |
)";

	std::string step4 = R"(
Let's play...
   |   |
   |   |
___|___|___
   |   |
TIC|TAC|TOE!
___|___|___
   |   |
   |   |
   |   |
)";

    std::array <std::string, 4> sequence { step1, step2, step3, step4};

    for (auto step : sequence)
    {
        std::cout << step << std::endl;
        Sleep(1000);
        system("CLS");
    }
}
