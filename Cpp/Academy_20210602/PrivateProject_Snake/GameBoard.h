#pragma once

#include <iostream>
#include <vector>
#include "Position.h"
using namespace std;

enum class eAsciiKey
{
	EXTENDED_0x00 = 0,
	ESC = 27,
	SPACE_BAR = 32,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	EXTENDED_0xE0 = 224
};

enum class State {
	Error,
	Moveable,
	MeetWall,
	MeetSelf,
	MeetFood

};

enum class MAPDATA
{
	EMPTY,
	SNAKE,
	WALL,
	FOOD
};



class GameBoard
{
private:
	vector<Position> snake;
	int frameTime;
	MAPDATA map[20][20];
	State NextBehavior(int newPosX, int newPosY);
	string text = "����Ű�� �Է��ϼ���";
	bool hasFood;
	int currentSize;
	int currentLevel;
	vector<int> nextSize = { 4,5,6,8,10,12,15,18,21,25,29,34,39,44,50,56,62};
	vector<int> nextSpeed = { 100,90,80,70,60,50,45,40,35,30,25,20,15,10 };
public:
	GameBoard();
	string GetText();
	void OnGUI();
	State GetInput(eAsciiKey i);
	bool GethasFood() { return hasFood; }
	void SetFood();
	int GetSpeed() { return nextSpeed[currentLevel]; }
};
