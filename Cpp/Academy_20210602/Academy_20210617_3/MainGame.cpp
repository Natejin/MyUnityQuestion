#include "MainGame.h"


MainGame::MainGame() {
	for (int i = 0; i < 10; i++) {
		vNumber.push_back(i + 1);
	}
	for (int i = 0; i < vNumber.size(); i++)
	{
		cout << viNumber[i] << endl;
	}
	cout << "==========삽입후!!!!==========" << endl;

	vNumber.insert(vNumber.begin(), 20);
	vNumber.insert(vNumber.begin() + 1, 50);//배열의 위치(인덱스),값
	vNumber.insert(vNumber.end() - 1, 3, 100);
	for (int i = 0; i < vNumber.size(); i++)
	{
		cout << vNumber[i] << endl;
	}
	cout << "========================" << endl;
	for (viNumber = vNumber.begin(); viNumber != vNumber.end(); ++viNumber)
	{
		cout << *viNumber << endl;
	}

}

MainGame::~MainGame() {

}

void MainGame::OutputVNum() {
	for (int i = 0; i < vNumber.size(); i++)
	{
		cout << vNumber[i] << endl;
	}
}

void MainGame::OutputVINum() {
	for (viNumber = vNumber.begin(); viNumber != vNumber.end(); ++viNumber)
	{
		cout << *viNumber << endl;
	}

	for (viNumber = vNumber.begin(); viNumber != vNumber.end(); ++viNumber)
	{
		cout << &viNumber << endl;
	}
}