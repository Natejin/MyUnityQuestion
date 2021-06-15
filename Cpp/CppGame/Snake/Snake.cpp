// PrivateProject_Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <ctime>
#include <chrono>
#include <iostream>
#include "GameBoard.h"
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;


void clear_screen(void)
{
	DWORD n;                         /* Number of characters written */
	DWORD size;                      /* number of visible characters */
	COORD coord = { 0 };               /* Top left screen position */
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	/* Get a handle to the console */
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(h, &csbi);

	/* Find the number of characters to overwrite */
	size = csbi.dwSize.X * csbi.dwSize.Y;

	/* Overwrite the screen buffer with whitespace */
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

	/* Reset the cursor to the top left position */
	SetConsoleCursorPosition(h, coord);
}



void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
int main()
{
	
	system("mode con:cols=40 lines=25");
	system("title Slide Puzzle Game");

	GameBoard game;
	game.OnGUI();
	int key = (int)eAsciiKey::UP;
	bool hasFood = false;
	int timeCount = 0;
	int spawnFoodTime;

	while (true)
	{
		Sleep(game.GetSpeed());
		if (_kbhit()) do { key = _getch(); } while (key == 224); //키 입력받음
		gotoxy(0, 0); //system("cls") 안쓰고 (0, 0)으로 커서 이동 후
		//gt->DrawGameTable(); // 다시 그리기
		game.GetInput((eAsciiKey)key);
		game.OnGUI();
		if (!game.GethasFood())
		{
			spawnFoodTime = timeCount + rand() % 5 + 5;
			game.SetFood();
		}
		
		timeCount++;
	}
}

