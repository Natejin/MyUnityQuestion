//슬라이드 퍼즐 게임 만들기

#include "SliderPuzzle.h"
#include "Algoritsm.h"
#include <conio.h>

using namespace std;
enum DIRECT {
	위쪽 = 72,
	아래쪽 = 80,
	왼쪽 = 75,
	오른쪽 = 77,
};
int main() {
	SliderPuzzle slide;
	srand((int)time(NULL));
	Algoritsm algoritsm;
	

	bool isSolvable = true;
	while (isSolvable)
	{
		slide.RandomNumGen();
		if (algoritsm.IsSolvable(slide.slidePuzzle))
		{
			isSolvable = false;
		}
	}

	Sleep(1000);

	string textOutput = "";
	bool isPlaying = true;
	while (isPlaying)
	{
		system("cls");
		slide.OnGUI();
		cout << textOutput << endl;
		cout << "==================================" << endl;
		cout << "방향을 입력해주세요" << endl;

		int i = _getch();
		if (i == 224) {
			i = _getch();
			switch (i) {
			case 위쪽:
				textOutput = slide.MoveUp();
				break;
			case 아래쪽:
				textOutput = slide.MoveDown();
				break;
			case 왼쪽:
				textOutput = slide.MoveRight();
				break;
			case 오른쪽:
				textOutput = slide.MoveLeft();
				break;
			}
		}
		if (slide.Check())
		{
			isPlaying = false;
		}
	}

	system("cls");
	slide.OnGUI();
	cout << textOutput << endl;
	cout << "==================================" << endl;
	cout << "축하합니다~~~~~~~~~~~~~~" << endl;
}