#pragma once
#include <Windows.h>

class BoardGUI
{
	static HANDLE g_hScreen[2];//�ܼ�2��

public:
	void DoubleBuffer() {
		g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

		g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		DWORD dw;   //��ǥ�� �����ϱ� ���� ����ä�� ����.

		COORD CursorPosition = { 0, 0 };    //��ǥ ����

		SetConsoleCursorPosition(g_hScreen[0], CursorPosition);    //��ǥ �̵�

		WriteFile(g_hScreen[0], "Hello, World!", strlen("Hello, World! 1"), &dw, NULL);    //���ۿ� ��
		SetConsoleActiveScreenBuffer(g_hScreen[0]);
	}
};

