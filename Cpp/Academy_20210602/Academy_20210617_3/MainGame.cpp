#include "MainGame.h"


MainGameMaster::MainGameMaster() {
	for (int i = 0; i < 10; i++) {
		vNumber.push_back(i + 1);
	}
	for (int i = 0; i < vNumber.size(); i++)
	{
		cout << viNumber[i] << endl;
	}
	cout << "==========������!!!!==========" << endl;

	vNumber.insert(vNumber.begin(), 20);
	vNumber.insert(vNumber.begin() + 1, 50);//�迭�� ��ġ(�ε���),��
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

MainGameMaster::~MainGameMaster() {

}

void MainGameMaster::OutputVNum() {
	for (int i = 0; i < vNumber.size(); i++)
	{
		cout << vNumber[i] << endl;
	}
}

void MainGameMaster::OutputVINum() {
	for (viNumber = vNumber.begin(); viNumber != vNumber.end(); ++viNumber)
	{
		cout << *viNumber << endl;
	}

	for (viNumber = vNumber.begin(); viNumber != vNumber.end(); ++viNumber)
	{
		cout << &viNumber << endl;
	}
}