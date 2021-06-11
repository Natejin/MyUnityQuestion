#pragma once


#include <iostream>
#include <Windows.h>
#include "Position.h"
#include "Algoritsm.h"

using namespace std;

class SliderPuzzle
{
private:
	string name;


	int count = 0;

public:
	SliderPuzzle();
	~SliderPuzzle();
	int slidePuzzle[4][4];
	Position currentIndex;
	void RandomNumGen();
	void OnGUI();
	void Suffle();
	string MoveUp();
	string MoveDown();
	string MoveLeft();
	string MoveRight();
	void Swap(Position origin, Position target);
	bool Check();
};

