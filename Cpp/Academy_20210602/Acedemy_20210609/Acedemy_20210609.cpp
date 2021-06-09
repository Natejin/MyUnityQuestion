#include<iostream>
using namespace std;

//열거형 : enum
//열거형을 사용하면, 변수가 갖는 값에 의미를 부여할수있다. 가독성 UP
//컴파일러는 열거형 멤버들을 정수형 상수형으로 인식한다.
//세미콜론으로 사용하지 않고 쉼표를 사용한다.
//enum을 잘 이용하면 상태패턴을 구현 할 수 있다.
//GOF디자인 PDF를 올려주신다고 한다.
//enum은 switch랑 한몸이라고 생각한다.
//enum class를 사용하면 된다.
enum WEEK
{
	//차례대로 자리를 가진다. (ONE=0,TWO=1...)직접 입력할 수도있다.
	ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN
};
enum COLOR
{
	//RED, GREEN=5, BLUE, BLACK, WHITE
	RED, GREEN, BLUE, BLACK, WHITE
};
enum DIRECTION
{
	FORWARD,
	LEFT,
	RIGHT
};
enum MOTION
{
	R_WALK, L_WALK, R_RUN, L_RUN
};

enum class COLOR1
{
	RED = 1, GREEN, BLUE, BLACK, WHITE
};
enum class DIRECTION1
{
	FORWARD, LEFT, RIGHT
};

enum class ITEMTYPE
{
	ITEMTYPE_SWORD,
	ITEMTYPE_SHIELD,
	ITEMTYPE_POSION
};

void GetItem(ITEMTYPE itemType) {
	if (itemType == ITEMTYPE::ITEMTYPE_SWORD)
	{
		cout << "칼을 습득하였습니다." << endl;
		//return string("칼을 습득하였습니다.");
	}
	else if (itemType == ITEMTYPE::ITEMTYPE_SHIELD) {
		cout << "방패를 습득하였습니다." << endl;
	}
	else if (itemType == ITEMTYPE::ITEMTYPE_POSION) {
		cout << "자양강장제를 습득하였습니다." << endl;
	}
}
int main() {
	cout << RED << endl;
	cout << GREEN << endl;
	cout << BLUE << endl;
	cout << BLACK << endl;
	cout << WHITE << endl;

	MOTION motion;
	motion = L_WALK;

	switch (motion)
	{
	case R_WALK:
		cout << "오른쪽으로 걷는다." << endl;
		break;
	case L_WALK:
		cout << "왼쪽으로 걷는다." << endl;
		break;
	case R_RUN:
		cout << "오른쪽으로 뛴다." << endl;
		break;
	case L_RUN:
		cout << "왼쪽으로 뛴다." << endl;
		break;

	}
	cout << endl << endl;
	if (motion == L_WALK)//모션이 L_WALK이면,
	{
		motion = R_RUN;//R_RUN으로 바꿔라.
		if (motion == R_RUN)//모션이 R_RUN이면,
		{
			cout << "오른쪽으로 뛴다." << endl;//출력
		}
	}

	COLOR c = RED;//RED=0
	DIRECTION d = FORWARD;//FORWARD=0

	if (c == d/*0==0?*/)//true
	{
		cout << "둘이 같다" << endl;//true값 출력
	}
	else//false
	{
		cout << "같지 않다!" << endl;//false값 출력
	}
	cout << endl << endl;
	//std:: 범위 지정 연산자.

	//열거형 클래스 : 범위 규칙이 지정되어 있기때문에 범위를 지정해주어야 한다.
	//COLOR1::RED와 DIRECTION1::FORWARD는 비교를 할 수 없다.
	COLOR1 color = COLOR1::RED;//COLOR1::RED(COLOR::=범위)
	DIRECTION1 direction = DIRECTION1::FORWARD;

	//cout << "아이템을 줍겠습니까?" << endl;
	//int input;
	//while (true)
	//{
	//	cin >> input;
	//	GetItem((ITEMTYPE)input);//타입을 바꿔버린다.
	//}

	int inputColor;
	while (true)
	{
		cout << "색상을 선택하시오. " << endl;
		cout << "1.빨간색 2.초록색 3.파란색 4.검은색 5.하얀색 " << endl;
		cout << "선택할 색은? : ";
		cin >> inputColor;
		switch ((COLOR1)inputColor)//타입 변환
		{
		case COLOR1::RED:
			cout << "빨간색" << endl;
			break;
		case COLOR1::GREEN:
			cout << "초록색" << endl;
			break;
		case COLOR1::BLUE:
			cout << "파란색" << endl;
			break;
		case COLOR1::BLACK:
			cout << "검은색" << endl;
			break;
		case COLOR1::WHITE:
			cout << "하얀색" << endl;
		default:
			break;
		}
	}
}