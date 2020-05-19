#include "Animator.h"

void Animator::animate(std::array <std::string, 5> animationSequence)
{
    for (auto step : animationSequence)
    {
        if (step != "\0")
        {
            system("CLS");
            std::cout << step << std::endl;
            Sleep(1000);
        }
        else
        {
            break;
        }
    }
}

