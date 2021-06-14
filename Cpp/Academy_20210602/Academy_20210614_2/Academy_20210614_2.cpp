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
    //���� ���縦 ���� ���� ������
    MyArray(const MyArray&);
    ~MyArray();
};

int main()
{
    //�����߻�
    //�⺻ ���� �����ڿ��� �ܼ��� ��� ���� �ٸ���ü�� �����ϱ� �����̴�.
    //�޸� �ּ� ����...
    //Ŭ�� ��ü�� ���� ���ο� ���� �Ҵ�����ʾҰ� ������ ������ ���� �����Ѵ�.

    //clone��ü�� �Ҹ��ϸ鼭 �����޸𸮵� ���������� ������ �Ͼ
    //���� �����̱⶧��
    MyArray arr(10);
    arr.data[0] = 1;
    cout << arr.data[0] << endl;


    //���� �߻���
    MyArray clone = arr;
    clone.data[0] = 2;
    cout << arr.data[0] << endl;
    cout << clone.data[0] << endl;
}

MyArray::MyArray(int size)
{
    this->size = size;
    data = new int[size]; //�����ڿ��� ���� �޸� �Ҵ�
}

//���� ������ ����
MyArray::MyArray(const MyArray& other)
{
    cout << "���� ������ ȣ��" << endl;
    this->size = other.size;
    this->data = new int[other.size];
    for (size_t i = 0; i < other.size; i++)
    {
        this->data[i] = other.data[i];
    }
}

MyArray::~MyArray()
{
    if (data != NULL) delete[] this->data; //�Ҹ��ڿ��� �Ҵ��� �޸� ����
    data = nullptr;
}
