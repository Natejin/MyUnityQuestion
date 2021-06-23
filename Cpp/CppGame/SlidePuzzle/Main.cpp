//�����̵� ���� ���� �����

#include "SliderPuzzle.h"
#include "Algoritsm.h"
#include <conio.h>
#include <vector>

using namespace std;
enum DIRECT {
	���� = 72,
	�Ʒ��� = 80,
	���� = 75,
	������ = 77,
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

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (slide.slidePuzzle[i][j] == 0)
			{
				slide.SetPosition(i, j);
			}
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
		cout << "������ �Է����ּ���" << endl;

		int i = _getch();
		if (i == 224) {
			i = _getch();
			switch (i) {
			case ����:
				textOutput = slide.MoveUp();
				break;
			case �Ʒ���:
				textOutput = slide.MoveDown();
				break;
			case ����:
				textOutput = slide.MoveRight();
				break;
			case ������:
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
	cout << "�����մϴ�~~~~~~~~~~~~~~" << endl;
}