#include <iostream>
#include<string>
using namespace std;

int main() {

	bool isPlay = true;
	int index;
	while (isPlay)
	{
		cout << "�����Ͻ� ���α׷� ��ȣ�� ����ּ���" << endl;
		cout << "1: ������" << endl;
		cout << "2: ��ǥ���" << endl;
		cout << "0: ���α׷� ����" << endl;

		cin >> index;
		system("cls");
		switch (index)
		{
		case 0:
			isPlay = false;
			break;
		case 1:
			//�������� ��� 
			//2������ ���� �����
			for (int i = 2; i < 10; i++)
			{
				cout << "������ " << i << " ��" << endl;
				for (int j = 1; j < 10; j++)
					cout << i << " * " << j << " = " << i * j << endl;
				cout << endl;
			}
			break;
		case 2:
			//�����
			int star;
			cout << "����� ��ǥ�� ������ �Է����ּ���" << endl;
			cin >> star;

			if (star <= 0)
			{
				cout << "����� ������ 0���� ���ų� �۽��ϴ� ��ǥ ��� ���α׷��� �����ϰ� �ָ޴��� �̵��ϰڽ��ϴ�." << endl;
			}
			else {
				for (int i = star; i > 0; i--) cout << string((i), '*') << endl;
				for (int i = star; i > 0; i--) cout << string((star - i), ' ') << string(i, '*') << endl;
				for (int i = 1; i <= star; i++) cout << string((star - i), ' ') << string(i, '*') << endl;
			}
			cout << endl;
			break;
		default:
			cout << "�Է¹�ȣ�� �ش��ϴ� �ε����� ���������ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			break;
		}
		cout << endl;
		cout << "=============================================================================" << endl;
		cout << endl;
	}
	cout << "���α׷��� �����մϴ�." << endl;
	//cout << endl;
}