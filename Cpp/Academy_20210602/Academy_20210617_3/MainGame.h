#pragma once

#include <iostream>
#include <vector>
using namespace std;


class MainGameMaster
{
private:
	//������ ���ͼ���
	vector<int> vNumber;
	//������ ���� �ݺ��� ����

	//int�� vector�� ����Ű�� iterator
	vector<int>::iterator viNumber;

public:
	MainGameMaster();
	~MainGameMaster();
	void OutputVNum();
	void OutputVINum();
};

