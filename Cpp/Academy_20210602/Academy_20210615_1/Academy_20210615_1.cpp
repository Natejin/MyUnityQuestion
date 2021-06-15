// Academy_20210615_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Car.h"
#include "Rectangle.h"
int main()
{

	SuperCar s;
	s.SetSpeed(10);
	if (s.GetSpeed() < 15)
	{
		s.SetTurbo(true);
	}

	int speed = s.GetTurbo() ? s.GetSpeed() * 2 : s.GetSpeed();


	Rectangle r;

	Rectangle E(100, 100, 100, 100);
 
	/*
	상속관계:
	무엇은 무엇의 한종류이다 라는 뜻에서 파생...
	서브 클래싱, 확장... 여러이름은로 불리고
	객체지향 프로그래밍의 근간이 된다.

	부모 -> 자식
	클래스 간의 상속관계를 맺을 때는 공통의 기능을
	상위 클래스에 묶어 넣어 다른 클래스로 확장할 수 
	있게 하는것이 목적이다.

	만약 클래스들이 서로 비슷한 또는 완전히 같은 코드를 가지고 있다면 해당코드를 상위
	클래스로 묶어내는것을 고려하는 것이 좋다.


	EX)유닛 클래스
	이름, 나이, 키

		*/
}

