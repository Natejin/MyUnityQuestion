#include<iostream>
//#pragma warnig
#pragma warning(disable:4996)
using namespace std;

int main() {

	//���ڿ� ��� ABCD�� �����ּҸ� �����϶�� �ǹ�
	//const char* p = "ABCD";
	//// char* p = "ABCD"; �׳� ���� ����
	////�׳ɾ���� �Ӽ����� ���ؾ���
	////��� �ؼ� ��� ���ľ��ϴµ� �߸𸣰���

	//cout << p << endl;
	////ABCD ���´�
	//cout << p+1 << endl;
	////BCD ���´�

	////p[0] = 'X'; �̰� ������
	////����ü�� ���ڿ� ����⶧���� �ٲܼ�������

	//char str[] = "QWER";
	//str[0] = 'A';
	//cout << str << endl;
	////�ߵ� AWER

	//p = str;
	//cout << p << endl;
	//�ߵ� AWER����

	//������ ���� ���ȭ ����
	//const ��� ���̳Ŀ� ���� �ٸ����
	//�����;����������ؼ� const �Ǵ�
	//1. ������ ������ �ٸ� �޸� ������ �ּҸ� �������� ���ϰ��Ѵ�.
	//(������ �ϳ��� �ּҸ� ����)
	//constŰ���尡 ��� �پ����� ������� �ϴ��� �ݵ�� ���

	char a = 'A';
	char b = 'B';

	char* const p = &a;//���ȭ�� ������ p = &a �̰Ÿ� ������ a�� �ּҸ� ���尡��
	//�׷��� �Ʒ���
	//p = &b;������ 

	//2. ������ ������ ���� �޸� ������ ���� �������� ���ϰ��Ѵ�.

	char a1 = 'A';
	char b2 = 'B';

	const char* p1 = &a;
	//*p1 = 'D'; ������

	//3. ������ ������ ���� �޸� ������ �ּҿ� �� ��� �������� ���ϰ��Ѵ�.
	//������ ���� �����̴� �̰͵�
	char a2 = 'A';
	char b2 = 'B';

	const char* const p2 = &a;
	//p2=&b;
	//*p2='D'; �Ѵٿ����� 

	//constŰ���� �������� �뵵 : ������ ������ �����ϴ� �ּҳ�
	//�����ϴ� ���� �б�Ӽ��� �����ϴµ� �ַ� ���
	//read only �б⸸�ض�
	//�׳� const�� ���°��� ����

	/*���ڿ��߿��ѵ� ���ڿ��� �峭ġ�°� ���� ���´�
	���̸� ���ؼ� ���ϰ� ���ϰ�
	���ڿ� A~Z �մµ� �빮�ڸ� ����ϰų�
	�������� ����غ�����*/

	/////////////

	char engStr[] = "HelloWorld";
	char korStr[] = "�ȳ��ϼ���";
	cout << "���� ���ڿ��� ���� : " << strlen(engStr) << endl;
	cout << "�ѱ� ���ڿ��� ���� : " << strlen(korStr) << endl;

	cout << "���� ���ڿ��� ũ�� : " << sizeof(korStr) << endl;
	cout << "�ѱ� ���ڿ��� ũ�� : " << sizeof(korStr) << endl;

	//���ڿ� ��
	char str[10] = "Hello";
	const char* str1 = "Hello";
	int res = strcmp(str, str1);//���ڿ� �� �Լ�
	cout << res << endl;//0������ ������ 0����
	//����ũ�� 1 �ڰ�ũ�� -1
	//�񱳴� �ƽ�Ű�ڵ�� ����

	cout << strcmp("aaa", "aaa") << endl;
	//0����
	cout << strcmp("aab", "aaa") << endl;
	//1����
	//a �� �ƽ�Ű10������97
	//b �� �ƽ�Ű10������98
	cout << strcmp("aab", "aaf") << endl;
	//-1����

	char str2[6] = "Hello";
	char str3[6];//str3��[4]�� �ȵ� ũ��Ǳ���

	//strcpy(str3, str2)
	//strcpy_s(str3, str2);//���ڿ� ���� �Լ� �ڿ��� �տ� �ְٴ�.
	//cout << str3 << endl; �׳� strcpy���� ���ȼ��� �����ؼ� ���������� ������
	//1�࿡ PRAGMA ���� ���� �����ϸ��

	//���ڿ� ���̱�

	char str4[10] = "world";
	char str5[20] = "Hello";
	strcat(str5, str4);//�ڿ��� �պ��� �ڿ� ���δ�.
	cout << str5 << endl;

	//���ڿ� �ڸ���

	char str6[30] = "abcd / efgh";
	char str7[30] = "i am a boy";

	const char* ptr = strtok(str7, " ");
	const char* ptr1 = strtok(str7, " ");
	//��Ʈ�� ��ū ����������� �ش繮�ڿ��� �ڸ��ٴ�
	//�����͸� ��ȯ

	while (ptr != NULL)//�ڸ����ڿ��� ���������������� ������
	{
		cout << ptr << endl;//�ڸ��༮ ���
		ptr = strtok(NULL, " ");
		//���� ���ڿ��� �߶� ������ ��ȯ
	}
	while (ptr1 != NULL)//�ڸ����ڿ��� ���������������� ������
	{
		cout << ptr1 << endl;//�ڸ��༮ ���
		ptr1 = strtok(NULL, "/");
		//���� ���ڿ��� �߶� ������ ��ȯ
	}
	char str8[30] = "i am a boy";

	const char* ptr2 = strtok(str8, 'a');
	//a�� �����ϴ�~���ڿ��˻�

	while (ptr2 != NULL)
	{
		cout << ptr2 << endl;
		prt2 = strchr(ptr1 + 1, 'a');
		//�����Ϳ� 1�� ���ؼ� a��������~
	}

	/////////
	//�ܼ� �ڷ� ����
}