#pragma once

#include <iostream>
#include <vector>
using namespace std;


class MainGameMaster
{
private:
	//정수형 벡터선언
	vector<int> vNumber;
	//정수형 벡터 반복자 선언

	//int형 vector를 가르키는 iterator
	vector<int>::iterator viNumber;

public:
	MainGameMaster();
	~MainGameMaster();
	void OutputVNum();
	void OutputVINum();
};

