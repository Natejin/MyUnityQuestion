#include "SliderPuzzle.h"

using namespace std;


SliderPuzzle::SliderPuzzle() {

}

SliderPuzzle::~SliderPuzzle() {

}

void SliderPuzzle::RandomNumGen() {
	//int size = 4;
	bool checkNum1[4] = {};
	int index = 0;

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
		//int currentIndex = rand() % 4;
		//int StartCol = rand() % 4;
		/*int Random = rand() % 2 * -2 + 1;
		int tmp = slidePuzzle[currentIndex.x][currentIndex.y];
		if (Random == -1)
		{
			if (currentIndex.x == 0)
			{
				slidePuzzle[currentIndex.x][currentIndex.y] = slidePuzzle[currentIndex.x + 1][currentIndex.y];
				slidePuzzle[currentIndex.x + 1][currentIndex.y] = tmp;
			}
			else if (currentIndex.x == 3)
			{
				slidePuzzle[currentIndex.x][currentIndex.y] = slidePuzzle[currentIndex.x - 1][currentIndex.y];
				slidePuzzle[currentIndex.x - 1][currentIndex.y] = tmp;
			}
			else {
				slidePuzzle[currentIndex.x][currentIndex.y] = slidePuzzle[currentIndex.x + Random][currentIndex.y];
				slidePuzzle[currentIndex.x + Random][currentIndex.y] = tmp;
			}
		}
		else {
			if (currentIndex.y == 0)
			{
				slidePuzzle[currentIndex.x][currentIndex.y] = slidePuzzle[currentIndex.x][currentIndex.y + 1];
				slidePuzzle[currentIndex.x][currentIndex.y + 1] = tmp;
			}
			else if (currentIndex.y == 3)
			{
				slidePuzzle[currentIndex.x][currentIndex.y] = slidePuzzle[currentIndex.x][currentIndex.y - 1];
				slidePuzzle[currentIndex.x][currentIndex.y - 1] = tmp;
			}
			else {
				slidePuzzle[currentIndex.x][currentIndex.y] = slidePuzzle[currentIndex.x][currentIndex.y + Random];
				slidePuzzle[currentIndex.x][currentIndex.y + Random] = tmp;
			}
		}*/

		int StartRow = rand() % 4;
		int StartCol = rand() % 4;
		int RandomRow = rand() % 4;
		int RandomCol = rand() % 4;

		int tmp = slidePuzzle[StartRow][StartCol];
		slidePuzzle[StartRow][StartCol] = slidePuzzle[RandomRow][RandomCol];
		slidePuzzle[RandomRow][RandomCol] = tmp;
	}
}



//bool SliderPuzzle::IsSolvable(int size, int targetIndex) {
//	int inversions = 0;
//	int position = 0;
//	int lineSize = sqrt(size);
//	for (int i = 0; i < size - 1; i++)
//		for (int j = i + 1; j < size; j++) {
//			if (slidePuzzle[j / lineSize][j % lineSize] == targetIndex)
//			{
//				position = j + 1;
//				continue;
//			}
//			if (slidePuzzle[i / lineSize][i % lineSize] > slidePuzzle[j / lineSize][j % lineSize])
//			{
//				inversions++;
//			}
//		}
//	//cout << "inversions : " << inversions << " lineSize : " << lineSize << " position : " << position << endl;
//	//Sleep(1000);
//	return isSlidePuzzleSolvable(inversions, lineSize, position);
//
//}

//int SliderPuzzle::GetRowNumberFromBelow(int width, int emptyTilePosition)
//{
//	return emptyTilePosition % width;
//}
//
//bool SliderPuzzle::isSlidePuzzleSolvable(int numberOfInversions, int width, int emptyTilePosition)
//{
//	if (width % 2 != 0)
//		return (numberOfInversions % 2 == 0);
//
//	int rowNumber = GetRowNumberFromBelow(width, emptyTilePosition);
//	//cout << "rowNumber : " << rowNumber << endl;
//	//Sleep(5000);
//	if (rowNumber % 2 != 0)
//		return (numberOfInversions % 2 == 0);
//	else
//		return (numberOfInversions % 2 != 0);
//}




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
				currentIndex = Position(i, j);
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

void SliderPuzzle::Swap(Position origin, Position target) {

	int temp = slidePuzzle[origin.x][origin.y];
	slidePuzzle[origin.x][origin.y] = slidePuzzle[target.x][target.y];
	slidePuzzle[target.x][target.y] = temp;


}


