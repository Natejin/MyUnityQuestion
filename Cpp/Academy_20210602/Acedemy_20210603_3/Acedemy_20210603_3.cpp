#include<iostream>
using namespace std;

int main() {

	cout << "��ƺ���� ���迡 �� �� ȯ���Ѵ�." << endl;
	cout << "������ ������" << endl;
	cout << "1.�ٹٸ���, 2.�Ҽ�����, 3. �Ƹ���, 4.��ũ�θ༭. 5.�ȶ��" << endl;
	cout << "���g~ : " << endl;

	int selectNum;
	cin >> selectNum;
	switch (selectNum) // �Է¹��� �༮�� ����� �´�.
	{
	case 1:
		cout << "�ٹٸ����� �����ߴ�!!!" << endl;
		break;
	case 2:
		cout <<"�Ҽ������� �����ߴ�!!!" << endl;
		break;
	case 3:
		cout << "�Ƹ����� �����ߴ�!!!" << endl;
		break;
	case 4:
		cout << "��ũ�θǼ��� �����ߴ�!!!" << endl;
		break;
	case 5:
		cout << "�ȶ���� �����ߴ�!!!" << endl;
		break;
	default:
		cout << "����̵带 �ϴ� ������ �׾��!!!" << endl;
		break;
	}

	//��Ʋ�ݿ� ����...
	//���ɸ��͸� ����
	//�ڱⰡ �ѹ� �غ��� ���� ����.

}