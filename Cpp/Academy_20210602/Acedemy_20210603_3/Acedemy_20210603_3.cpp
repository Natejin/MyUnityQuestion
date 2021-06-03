#include<iostream>
using namespace std;

int main() {

	cout << "디아블로의 세계에 온 걸 환영한다." << endl;
	cout << "직업을 골라봐라" << endl;
	cout << "1.바바리안, 2.소서리스, 3. 아마존, 4.네크로멘서. 5.팔라딘" << endl;
	cout << "골라봥~ : " << endl;

	int selectNum;
	cin >> selectNum;
	switch (selectNum) // 입력받은 녀석이 여기로 온다.
	{
	case 1:
		cout << "바바리안을 선택했다!!!" << endl;
		break;
	case 2:
		cout <<"소서리스를 선택했다!!!" << endl;
		break;
	case 3:
		cout << "아마존을 선택했다!!!" << endl;
		break;
	case 4:
		cout << "네크로맨서을 선택했다!!!" << endl;
		break;
	case 5:
		cout << "팔라딘을 선택했다!!!" << endl;
		break;
	default:
		cout << "드루이드를 하는 병신은 죽어랏!!!" << endl;
		break;
	}

	//베틀넷에 접속...
	//롤케릭터를 선택
	//자기가 한번 해보고 싶은 영웅.

}