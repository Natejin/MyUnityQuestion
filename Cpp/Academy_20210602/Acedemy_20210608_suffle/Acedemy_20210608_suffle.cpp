// Acedemy_20210608_suffle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int number[10];
    int dest, sour, temp;

	for (size_t i = 0; i < 10; i++)
	{
		number[i] = i;
	}

	cout << "���� ��~~" << endl;
	for (size_t i = 0;	i < 10; i++)
	{
		cout << "number[" << i << "]�ε���" << number[i] << endl;

	}

	for (size_t i = 0; i < 1000; i++)
	{
		dest = rand() % 10; //0~9
		sour = rand() % 10; //0~9

		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	cout << "���� ��~~" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << "number[" << i << "]�ε���" << number[i] << endl;

	}

	cout << "==================================" << endl;

	int rottoNum[45];
	
	for (size_t i = 1; i < 46; i++)
	{
		rottoNum[i - 1] = i;
	}

	for (size_t i = 0; i < 1000; i++)
	{
		dest = rand() % 45; //0~9
		sour = rand() % 45; //0~9

		temp = rottoNum[dest];
		rottoNum[dest] = rottoNum[sour];
		rottoNum[sour] = temp;
	}

	for (size_t i = 0; i < 6; i++)
	{
		cout << "�ζǹ�ȣ[" << i << "] : " << rottoNum[i] << endl;
	}
}
