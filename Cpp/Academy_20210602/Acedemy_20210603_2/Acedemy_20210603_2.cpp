// Acedemy_20210603_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	//조건문, 분기문
	//if (조건이 만족하면)
	//{
	//		여기를 실행
	//}

	//if (0)
	//{
	//	cout << "출력하라" << endl;
	//}

	//int num = 10;
	//if (num == 10)
	//{
	//	cout << "if문 조건이 참이므로 여기가 실행된다~!!!" << endl;
	//	cout << "num값은 : " << num << endl;
	//}

	////아래와 같은 형태는 모든 if 조건을 검사한다.
	////첫번쨰 조건을 만족해도 다음 if문을 조건해서 실행한다.

	////if (true) {}
	////if (true) {}
	////if (true) {}
	////if (true) {}

	//int num1 = 30;
	//if (num1 == 50)
	//{
	//	cout << "만족!!!!" << endl;
	//}
	//else {
	//	cout << "위 if문이 거짓이므로 여기가 실행된다." << endl;
	//}

	//int input;
	//cout << "아무 숫자나 입력해보기 : ";
	//cin >> input;

	//if (input < 10)
	//{
	//	cout << "내가 입력한 값 : " << input << endl;
	//}
	//else {
	//	cout << "내가 입력한 값은 input < 10가 아님 : " << input << endl;
	//}

	//if (input < 0)
	//{
	//	cout << "내가 입력한 값은 0 보다 작음!!! : " << input << endl;
	//	//여기 조건을 만족한다면 아래에 있는 조건들을 전부 건너 뛴다.
	//}
	//else if (input > 0)
	//{
	//	cout << "내가 입력한 값은 0 보다 크다: " << input << endl;
	//}

	//else
	//{
	//	cout << "내가 입력한 값은 0임!! " << input << endl;
	//	//위 조건이 전부 만족을 하지 않으면 여기 실행
	//}

	//cout << "내가 좋아하는 이상형의 나이를 입력해보자!! : ";
	//int age;
	//cin >> age;
	//if (age == 20)
	//{
	//	cout << "동갑내기!! 많이 싸우겠는걸?" << endl;
	//}
	//else if (age > 20) {
	//	cout << "너무 차이나면 그렇지만 나쁘지않은듯" << endl;
	//}
	//else if (age < 20 && age > 15) {
	//	cout << "요즘은 연하가 좋지" << endl;
	//}
	//else {
	//	cout << "이번생에 글렀어... ㅜㅜ" << endl;
	//}

	//3교시 부터
	//	입력을 두 수를 받는다.
	//	1을 누르면 덧셈 2 = 뺼셈 3 곱하기 4 나누기

	//int num1, num2, control, result;
	//cin >> num1, num2, control;

	////입력
	//cout <<"입력 받을 첫번쨰 수 : ";
	//cin >> num1;
	//cout << "입력 받을 두번쨰 수 : ";
	//cin >> num2;
	//cout << "입력 받을 명령어 (1은 덧셈, 2은 뺄셈, 3은 곱하기, 4는 나누기) : ";
	//cin >> control;

	////if (control == 1)
	////{
	////	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	////}
	////else if (control == 2)
	////{
	////	cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	////}
	////else if (control == 3)
	////{
	////	cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
	////}
	////else if (control == 4)
	////{
	////	cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
	////}

	////계산하는 로직
	//if (control == 1) result = num1 + num2;
	//else if (control == 2) result = num1 - num2;
	//else if (control == 3) result = num1 * num2;
	//else if (control == 4) result = num1 / num2;
	//else cout << "선택번호(1~4)를 잘못 눌렀다!!" << endl;

	////출력
	//cout << "결과 : " << result << endl;



	//bool isAttack = true;
	//bool isHit = true;
	//if (isAttack)
	//{
	//	//플레이어가 몬스터를 공격
	//	if (isHit)
	//	{
	//		//몬스터 피감소
	//	}else {
	//		//몬스터 회피
	//	}
	//}
	//else {
	//
	//}

	//1. 두개의 정수를 입력받아서 두수의 차를 출력해라.
	//2. 단 입력된숫자가 순서에 상관없이 무조건 큰수에서 작은수를 뺸결과를 출력

	int num1, num2, control, result;
	cout << "입력 받을 첫번쨰 수 : ";
	cin >> num1;
	cout << "입력 받을 두번쨰 수 : ";
	cin >> num2;

	result = num1 - num2;

	//result = result > 0 ? result : ~result;
	//if ((result & 0x80000000) != 0)
	if(((result>>31) & 1) == 1)
	{
		result = ~result;	//비트 벡터 변환
		result++;			//비트에 1을 더함
	}
	
	cout << "값 : " << result << endl;

	//학생의 전체 평균점수에 대한 학점을 출력해라.

	int math, english, korean;
	char grade;
	cout << "수학 점수 : ";
	cin >> math;
	cout << "국어 점수  : ";
	cin >> english;
	cout << "영어 점수  : ";
	cin >> korean;

	result = (math + english + korean) / 3;

	if (result >= 90) grade = 'A';
	else if (result >= 80) grade = 'B';
	else if (result >= 70) grade = 'C';
	else if ( result>= 60) grade = 'D';
	else grade = 'F';

	cout << "당신의 평균점수는 " << result << " 이므로 학점은 " << grade << " 입니다" << endl;
}