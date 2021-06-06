#include <iostream>
#include<string>
using namespace std;

int main() {

	bool isPlay = true;
	int index;
	while (isPlay)
	{
		cout << "실행하실 프로그램 번호를 골라주세요" << endl;
		cout << "1: 구구단" << endl;
		cout << "2: 별표찍기" << endl;
		cout << "0: 프로그램 종료" << endl;

		cin >> index;
		system("cls");
		switch (index)
		{
		case 0:
			isPlay = false;
			break;
		case 1:
			//구구단을 출력 
			//2중포문 돌려 만들기
			for (int i = 2; i < 10; i++)
			{
				cout << "구구단 " << i << " 단" << endl;
				for (int j = 1; j < 10; j++)
					cout << i << " * " << j << " = " << i * j << endl;
				cout << endl;
			}
			break;
		case 2:
			//별찍기
			int star;
			cout << "출력할 별표의 개수를 입력해주세요" << endl;
			cin >> star;

			if (star <= 0)
			{
				cout << "출력할 개수가 0보다 같거나 작습니다 별표 찍기 프로그램을 종료하고 주메뉴로 이동하겠습니다." << endl;
			}
			else {
				for (int i = star; i > 0; i--) cout << string((i), '*') << endl;
				for (int i = star; i > 0; i--) cout << string((star - i), ' ') << string(i, '*') << endl;
				for (int i = 1; i <= star; i++) cout << string((star - i), ' ') << string(i, '*') << endl;
			}
			cout << endl;
			break;
		default:
			cout << "입력번호에 해당하는 인덱스는 존재하지않습니다. 다시 입력해주세요." << endl;
			break;
		}
		cout << endl;
		cout << "=============================================================================" << endl;
		cout << endl;
	}
	cout << "프로그램을 종료합니다." << endl;
	//cout << endl;
}