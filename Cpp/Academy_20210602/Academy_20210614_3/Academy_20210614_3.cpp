// Academy_20210614_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SlidePuzzle.h"

int main()
{
	srand(time(NULL));
	for (int i = 24; i >= 0; i--)
	{
		number[save - i] = i;
	}

	for (size_t i = 0; i < 200; i++)
	{
		dest = rand() % 24;
		sour = rand() % 24;
		int temp = number[dest];
		number[sour] = number[dest];
		number[dest] = number[sour];
	}
}

