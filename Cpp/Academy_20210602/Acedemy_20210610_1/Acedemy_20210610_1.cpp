#include<iostream>

using namespace std;

int main() {
	/*
	��а� �մٴ� �͸� �˾Ƶֶ�
	���̵� �������İ��� �ſ��� å�ѱǳ���
	��а� �ִٴ°͸� �����ϰ� ��� �غ���
	*/

	//void //������ �ƹ��͵� ����

	//int* p;
	//�ڷ����� ���� ������ ������.
	//�ڷ����� ������ �����ʰ� �ƹ��� �ڷ����� �ּҸ� ���尡��




	int num = 10;

	////int�� ������ ����
	//int* pNum = &num;

	////int�� ������ ����
	//int** ppNum = &pNum;

	//cout << "num :\t" << num << endl;
	//cout << "pNum :\t" << pNum << endl;
	//cout << "ppNum :\t" << ppNum << endl;



	//int a = 3;
	//int* pa = &a;
	//int** ppa = &pa;

	//cout << "a :\t" << a << endl;
	//cout << "&a :\t" << &a << endl;
	//cout << "pa :\t" << pa << endl;
	//cout << "&pa :\t" << &pa << endl;
	//cout << "*pa :\t" << *pa << endl;
	//cout << "*ppa :\t" << *ppa << endl;
	//cout << "&ppa :\t" << &ppa << endl;
	//cout << "ppa :\t" << ppa << endl;
	//cout << "**ppa :\t" << **ppa << endl;



	int a = 10;
	int* pa = &a;

	int A = 10;
	void* pA = &A;

	cout << *(int*)pA << endl;





	int c = 3;
	double d = 3.1;

	void* vp = nullptr;
	vp = &c;//c�� �ּҰ��� ����
	cout << "vp�� �ּҰ� : " << vp << endl;


	//*vp = 1; ������ �ּҸ� �����̰����ؼ�
	//�������� ������ ���� �����ϰų� �����Ҽ�����.
	//������ ....��
	//int a = 1;
	//int* p = &a;//*p = 3;
	//cout << *p << endl;

	//cout <<*vp<<endl; �̰ǿ�����
	cout << *(int*)vp << endl;//������������ �̰ǉ�
	//3�̳��� vp�� ���ؼ� ���� ����ȯ����
	//1.(int*)vp->vp�� �ּҸ� int�� �ּҷ� ���� ����ȯ
	//2. �տ� *-> ���� ����ȯ�� �ּҿ� ����� ���� ����

	*(int*)vp = 5;
	//��������ȯ�� ����

	cout << *(int*)vp << endl;
	//��ӵǳ�

	//��� �ڷ����� �ּҸ� �����Ҽ��մ� �����ο� ������ ����
	//���̵��� �����͸� ���� �ּҰ� �ƴ� ���� �����Ҽ��� ������ �����Ϸ��� ���� ����ȯ�� �ؾ��Ѵ�.


}