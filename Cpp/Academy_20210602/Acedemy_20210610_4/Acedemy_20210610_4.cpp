// Acedemy_20210610_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
enum class PROGRAM {ID, REVERSE, EVEN, REMOVESPECIFICTEXT};

using namespace std;
int main()
{
	//PROGRAM program = PROGRAM::ID;
	//string idNumber;
	//switch (program)
	//{
	//case PROGRAM::ID:
	//	//지금 해볼꺼
	//	//1. 입력 : 901010-1234567
	//	//출력 : 9010101234567
	//	getline(cin, idNumber);
	//	idNumber.erase(idNumber.find("-"), 1);
	//	cout << idNumber;
	//	break;
	//case PROGRAM::REVERSE:
	//	break;
	//case PROGRAM::EVEN:
	//	break;
	//case PROGRAM::REMOVESPECIFICTEXT:
	//	break;
	//default:
	//	break;
	//}





	//cout << endl;

	////2. abcdefgh
	////역으로 출력
	//string temp = "abcdefgh";
	//string reverseTemp = "";
	//int count = temp.length();
	//for (size_t i = 0; i < count; i++)
	//{
	//	reverseTemp += temp.back();
	//	temp.pop_back();
	//}
	//cout << reverseTemp;

	//3.입력 문자에서 제거할 문자 모두 찾아서 제거
	//string inputStr, removeStr;
	//cout << "입력할 문자를 적어주세요 : ";
	//getline(cin, inputStr);
	//cout << endl;

	//cout << "제거할 문자를 적어주세요 : ";
	//getline(cin, removeStr);
	//cout << endl;
	//int index = 0;
	//while (index < inputStr.length())
	//{
	//	int tempIndex = inputStr.find(removeStr, index);
	//	if (tempIndex == -1) break;
	//	inputStr.erase(tempIndex, removeStr.length());
	//	index = tempIndex;
	//}
	//cout << inputStr;

}

