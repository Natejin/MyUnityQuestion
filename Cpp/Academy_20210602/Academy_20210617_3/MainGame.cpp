#include "MainGame.h"


MainGame::MainGame() {

	for (int i = 0; i < 10; i++)
	{
		vNumber.push_back(i + 1);
	}
	OutputVNum();

	cout << endl << "=================================" << endl << endl;
	vNumber.insert(vNumber.begin(), 20);
	vNumber.insert(vNumber.begin() + 1, 50);
	vNumber.insert(vNumber.end()-1, 3, -10);
	//vNumber.insert(vNumber.begin() + 1, 50);
	OutputVNum();
	cout << endl << "================= 이터레이터 ================" << endl << endl;
	OutputVINum();

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