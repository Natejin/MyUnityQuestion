// Academy_20210611_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Square{


public:
	int length;
	int height;
	void SquareSetUp(int len, int hei) {
		length = len;
		height = hei;
	}
	void CalculateAreaAndPrint() {
		cout << length * height << endl;
	}
	void OnGUI();
};

int main()
{
	Square square;
	int length, height;
	cout << "가로의 크기를 적어주세요 (2보다 큰값을 적어주세요): ";
	cin >> length;
	cout << endl;
	cout << "세로의 크기를 적어주세요 (2보다 큰값을 적어주세요): ";
	cin >> height;
	cout << endl;
	square.SquareSetUp(length, height);
	square.OnGUI();
	square.CalculateAreaAndPrint();
}

void Square::OnGUI() {
	string mid = "";
	string boaderStr = "";
	for (size_t i = 0; i < length - 2; i++)
	{
		boaderStr += "──";
		mid += "  ";
	}
	cout << "┌" << boaderStr << "┐";
	for (size_t i = 0; i < height - 2; i++)
	{
		cout << endl;
		cout << "│" << mid << "│";
	}
	cout << endl;
	cout << "└" << boaderStr << "┘";
	cout << endl;
}