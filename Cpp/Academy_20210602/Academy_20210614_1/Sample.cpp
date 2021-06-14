#include "Sample.h"

void Sample::SetScore(const int score)
{
	//this 포인터
	//객체 자신을 가리키는 포인터
	//일부러 값을 할당하지 않아도 객체내에서 생성된 객체 자기 자신을 가르킨다.
	//this는 주로 클래스의 멤버함수에서 매개변수와 멤버변수의 이름이 같을떄 
	//매개변수의 이름인지 멤버 변수이 이름인지 명확하게 지정할떄
	this->score = score;
}

//Sample& Sample::SendThisClass()
//{
//	return this;
//}
