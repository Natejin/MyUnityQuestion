#include "SliderPuzzle.h"

using namespace std;


SliderPuzzle::SliderPuzzle() {

}

SliderPuzzle::~SliderPuzzle() {

}

void SliderPuzzle::SetPosition(int x, int y) {
	currentIndex = Position(x, y);
}

void SliderPuzzle::RandomNumGen() {
	bool checkNum1[4] = {};
	int index = 0;

	//currentIndex = Position(0, 0);
	//번호 생성
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			slidePuzzle[i][j] = index++;
		}
	}
	Suffle();
}

void SliderPuzzle::Suffle()
{

	for (int i = 0; i < 100000; i++)
	{
		int StartRow = rand() % 4;
		int StartCol = rand() % 4;
		int RandomRow = rand() % 4;
		int RandomCol = rand() % 4;



		int tmp = slidePuzzle[StartRow][StartCol];
		slidePuzzle[StartRow][StartCol] = slidePuzzle[RandomRow][RandomCol];
		slidePuzzle[RandomRow][RandomCol] = tmp;

	}
}

void SliderPuzzle::OnGUI() {

	string boaderStr = "";
	for (size_t i = 0; i < 4; i++)
	{
		boaderStr += "---+";
	}
	for (size_t i = 0; i < 4; i++)
	{
		cout << "+" << boaderStr << endl;
		cout << "|";
		for (size_t j = 0; j < 4; j++)
		{
			if (slidePuzzle[i][j] == 0)
			{
				cout << " # |";
			}
			else {
				if (slidePuzzle[i][j] < 10)
				{
					cout << " " << slidePuzzle[i][j] << " |";
				}
				else {
					cout << slidePuzzle[i][j] << " |";
				}
			}
		}
		cout << endl;
	}
	cout << "+" << boaderStr << endl;
}


string SliderPuzzle::MoveUp()
{
	if (currentIndex.x > 0)
	{
		Swap(currentIndex, Position(currentIndex.x - 1, currentIndex.y));
		return "위로 이동했습니다.";
	}
	else {
		return "위로 이동할수 없습니다.";
	}
}

string SliderPuzzle::MoveDown()
{
	if (currentIndex.x < 3)
	{
		Swap(currentIndex, Position(currentIndex.x + 1, currentIndex.y));
		return "아래로 이동했습니다.";
	}
	else {
		return "아래로 이동할수 없습니다.";
	}
}
string SliderPuzzle::MoveLeft()
{
	if (currentIndex.y < 3)
	{
		Swap(currentIndex, Position(currentIndex.x, currentIndex.y + 1));
		return "오른쪽으로 이동했습니다.";
	}
	else {

		return "오른쪽으로 이동할수 없습니다.";
	}
}
string SliderPuzzle::MoveRight()
{
	if (currentIndex.y > 0)
	{
		Swap(currentIndex, Position(currentIndex.x, currentIndex.y - 1));
		return "왼쪽으로 이동했습니다.";
	}
	else {
		return "왼쪽으로 이동할수 없습니다.";
	}
}

bool SliderPuzzle::Check() {
	int value =1;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cout << slidePuzzle[i][j] << " ";
			if (value != slidePuzzle[i][j])
			{
				if (i == 3 && j == 3)
				{
					return true;
				}
				return false;
			}
			
			value++;
		}
	}
	return true;
}

void SliderPuzzle::Swap(Position& origin, Position target) {

	int temp = slidePuzzle[origin.x][origin.y];
	slidePuzzle[origin.x][origin.y] = slidePuzzle[target.x][target.y];
	slidePuzzle[target.x][target.y] = temp;

	origin = target;
}


