#pragma once
#include <Windows.h>

class BoardGUI
{
	static HANDLE g_hScreen[2];//콘솔2개

public:
	void DoubleBuffer() {
		g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

		g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		DWORD dw;   //좌표를 저장하기 위한 구조채를 선언.

		COORD CursorPosition = { 0, 0 };    //좌표 설정

		SetConsoleCursorPosition(g_hScreen[0], CursorPosition);    //좌표 이동

		WriteFile(g_hScreen[0], "Hello, World!", strlen("Hello, World! 1"), &dw, NULL);    //버퍼에 씀
		SetConsoleActiveScreenBuffer(g_hScreen[0]);
	}
};

