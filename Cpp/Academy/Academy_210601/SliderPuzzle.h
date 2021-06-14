#pragma once


#include <iostream>
#include <Windows.h>
#include "Position.h"

using namespace std;

class SliderPuzzle
{
private:
	string name;
	Position currentIndex;
	int count = 0;

public:
	SliderPuzzle();
	~SliderPuzzle();
	int slidePuzzle[4][4];

	void RandomNumGen();
	void OnGUI();
	void Suffle();
	void SetPosition(int x, int y);
	string MoveUp();
	string MoveDown();
	string MoveLeft();
	string MoveRight();
	void Swap(Position& origin, Position target);
	bool Check();
};

