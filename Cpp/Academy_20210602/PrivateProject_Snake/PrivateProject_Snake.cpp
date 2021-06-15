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

//static HANDLE hBuffer[2];//콘솔2개
//int nScreenIndex;
//#define MAP_X_MAX 5
//#define MAP_Y_MAX 5
//void CreatBuffer()
//{
//	COORD size = { MAP_X_MAX, MAP_Y_MAX };
//	CONSOLE_CURSOR_INFO cci;
//	SMALL_RECT rect;
//	rect.Bottom = 0;
//	rect.Left = 0;
//	rect.Right = MAP_X_MAX - 1;;
//	rect.Top = MAP_Y_MAX - 1;
//	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	SetConsoleScreenBufferSize(hBuffer[0], size);
//	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);
//
//	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	SetConsoleScreenBufferSize(hBuffer[1], size);
//	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);
//
//	cci.dwSize = 1;
//	cci.bVisible = FALSE;
//	SetConsoleCursorInfo(hBuffer[0], &cci);
//	SetConsoleCursorInfo(hBuffer[1], &cci);
//
//}
//
//void WriteBuffer(int x, int y, char* str)
//{
//	DWORD dw;
//	COORD CursorPosition = { x, y };
//	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);
//	WriteFile(+- hBuffer[nScreenIndex], str, strlen(str), &dw, NULL);
//}
//
//void FlippingBuffer()
//{
//	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
//	nScreenIndex = !nScreenIndex;
//}
//
//void ClearBuffer()
//{
//	COORD Coor = { 0,0 };
//	DWORD dw;
//	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', MAP_X_MAX * MAP_Y_MAX, Coor, &dw);
//}
//
//
//void DeleteBuffer()
//{
//	CloseHandle(hBuffer[0]);
//	CloseHandle(hBuffer[1]);
//}
//
//void setConsoleSize(const int cols, const int lines)
//{
//	std::string consoleSize = "mode con: cols=" + std::to_string(cols) + " lines=" + std::to_string(lines);
//	system(consoleSize.c_str());
//}
//void setConsoleTitle(const std::string& title)
//{
//	std::string gameTitle = "title " + title;
//	system(gameTitle.c_str());
//}
//void removeConsoleCursor(void)
//{
//	CONSOLE_CURSOR_INFO cursorInfo;
//	cursorInfo.bVisible = 0;
//	cursorInfo.dwSize = 1;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//}

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

