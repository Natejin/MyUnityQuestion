// Academy_20210611.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

enum State : bool {
	STATE_NONE = true,
	STATE_DAMAGE = false

};

int main()
{

	int speed = 10;
	double y = 0;

	if ((speed >= 10) && !(y> 0.0f) && !State::STATE_DAMAGE)
	{
		cout << "달린다!!!" << endl;
	}

	const bool isJump = y > 0.0f;
	const bool isDamage = State::STATE_DAMAGE;
	const bool isDash = (speed >= 10) && !isJump && !isJump;

	if (isDash)
	{
		cout << "고고씽!!!";
	}
}

////조건식은 최대한 간략하게!! 그래야 디버깅하기 쉽다.
//bool isJump{
//	return y > 0.0f;
//}
//
//bool isDamage() {
//	return State::STATE_DAMAGE;
//}
//
//bool isDash() {
//	if (isJump())return false;
//	if (isDamage()) return false;
//}

