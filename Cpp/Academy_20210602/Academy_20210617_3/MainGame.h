#pragma once

#include <iostream>
#include <vector>
using namespace std;


class MainGame
{
private:
	//������ ���ͼ���
	vector<int> vNumber;
	//������ ���� �ݺ��� ����

	//int�� vector�� ����Ű�� iterator
	vector<int>::iterator viNumber;

public:
	MainGame();
	~MainGame();
	void OutputVNum();
	void OutputVINum();
};

