#pragma once

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdlib.h>
#include <array>
#include <conio.h>
#include <iostream>
#include <string>

class Animator
{
public:
	void animate(std::array <std::string, 5> animationSequence);
};
