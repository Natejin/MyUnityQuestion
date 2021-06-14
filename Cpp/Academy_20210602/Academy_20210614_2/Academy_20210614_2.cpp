// Academy_20210614_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class MyArray {
private:
   
public:
    string str;
    int* data;
    int size;
    MyArray(int size);
    //깊은 복사를 위한 복사 생성자
    MyArray(const MyArray&);
    ~MyArray();
};

int main()
{
    //오류발생
    //기본 복사 생성자에서 단순히 멤버 값을 다른객체로 복사하기 때문이다.
    //메모리 주소 공유...
    //클론 객체를 위한 새로운 공간 할당되지않았고 동일한 공간을 서로 공유한다.

    //clone객체가 소멸하면서 공유메모리도 지워버리기 때문에 일어남
    //얕은 복사이기때문
    MyArray arr(10);
    arr.data[0] = 1;
    cout << arr.data[0] << endl;


    //오류 발생함
    MyArray clone = arr;
    clone.data[0] = 2;
    cout << arr.data[0] << endl;
    cout << clone.data[0] << endl;
}

MyArray::MyArray(int size)
{
    this->size = size;
    data = new int[size]; //생성자에서 동적 메모리 할당
}

//복사 생성자 정의
MyArray::MyArray(const MyArray& other)
{
    cout << "복사 생성자 호출" << endl;
    this->size = other.size;
    this->data = new int[other.size];
    for (size_t i = 0; i < other.size; i++)
    {
        this->data[i] = other.data[i];
    }
}

MyArray::~MyArray()
{
    if (data != NULL) delete[] this->data; //소멸자에서 할당한 메모래 해제
    data = nullptr;
}
