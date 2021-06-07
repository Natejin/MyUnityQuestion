#include <iostream>
#include<string>
using namespace std;


int sum(int a, int b);
int subtract(int a, int b);
int multiple(int a, int b);
int divide(int a, int b);

int main() {
	int a, b;
	cin >> a;
	cin >> b;

	cout << a << " + " << b << " = " << sum(a, b) << endl;
	cout << a << " - " << b << " = " << subtract(a, b) << endl;
	cout << a << " * " << b << " = " << multiple(a, b) << endl;
	cout << a << " / " << b << " = " << divide(a, b) << endl;

	cout << endl << endl;
	int a = 20;



}

void Function_A() {
	cout << "main 함수  a의 값";
}

int sum(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiple(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
