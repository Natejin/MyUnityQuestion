#pragma once


#include <iostream>
#include <Windows.h>
#include "Position.h"

using namespace std;

class SliderPuzzle
{
private:
	string name;

	//int slidePuzzle[4][4];
	int count = 0;

public:
	SliderPuzzle();
	~SliderPuzzle();
	Position currentIndex;
	int slidePuzzle[4][4];
	void RandomNumGen();
	void OnGUI();
	void Suffle();
	string MoveUp();
	string MoveDown();
	string MoveLeft();
	string MoveRight();
	void Swap(Position origin, Position target);
	bool Check();



	//bool IsSolvable(int size, int targetIndex);
	//int GetRowNumberFromBelow(int width, int emptyTilePosition);
	//bool isSlidePuzzleSolvable(int numberOfInversions, int width, int emptyTilePosition);
};

