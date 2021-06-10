#include<iostream>

using namespace std;
#include <string>

int main() {

	string s = "나는 스트링 클래스다!!!";
	string s1 = "문자열을 합쳐볼까?";

	cout << s + s1 << endl;
	//스트링은 연산자 오버로딩을 지원해서 쉬움

	string s2 = "Hello";
	string s3 = "Hello";
	//얘가 가지고 있는
	//내장되어있는 멤버 함수가 많아
	//추가 삭제 검색을위한용임
	//엄청많은데 대략적으로 많이쓰고기억나는것만적어보자
	if (s2 == s3) {
		cout << "동일함!!";
	}
	else
	{
		cout << "다름";
	}
	//멤버 함수호출 s3. 식으로 struct 멤버함수 호출할때랑 똑같음
	/*
	멤버함수			역할
	s[i]				i번째원소
	s.empty				s가비어있으면 true
	s.insert(pos,s2)	s의 pos위치에 s2를 삽입
	s.remove(pos,len)	s의 pos위치에 len만큼 삭제
	s.find(s2)			s에서 문자열 s2가 발견되는 첫번째 인덱스반환
	s.find(pos,s2)		s의 pos위치부터 문자열 s2가 발견되는 첫번째 인덱스반환
	*/
	//01234567
	string test = "i am a boy";
	int index = test.find("boy");
	cout << "boy가 발견된 첫번째 인덱스 : " << index << endl;
	//7나옴
	cout << "test 문자열의 길이 : " << test.length() << endl;
	//단점 char보단 느리긴함 근데 큰차이는없음
	//장점 편함
	//NULL이 포함되지않음
	//문자열의 길이를 전혀 신경쓰지않아도됨
	//객체로써의 블럭 규격이 끝나는순간
	//클래스에서 소멸자가 생성되서 메모리 누수가 발생하지않음
	//배열처럼 한문자씩 할수잇음
	cout << test[0] << endl;//i나옴 우와우
	//연산자 오버로딩이 되어있어서
	//연산자들로 더하거나 문자열 연산이 됨.
	//string클래스의 맴버함수가 많은데
	//내부안에 문자열 가공이 되게 쉬워

	int list[] = { 1,2,3,4,5,6,7,8 };

	//C11부터 지원되는기능 범위기반 포문
	//측정후 그만큼만 auto쓰는 걸 권장하긴함
	//들어잇는 데이터타입 측정해서 자동으로
	//많이쓰면 탈난대
	//for탭하고 rfor나오는거
	for (int& i : list)
	{
		cout << i << endl;
	}

	string name[] = { "철수","영희","말미잘" };

	for (auto& i : name)
	{
		cout << (i + "안녕?") << endl;
	}

	//string class를 사용하는 입출력
	//<<,>>연산자를 정의해서 입출력 연산을 구현하고 있음
	//문자열 입력에 있어서는 약간 복잡..cin에서 string타입으로
	//입력하는 경우 공백문자가 있으면 중단된다.
	//공백포함 한줄전체를 읽으려면 getline함수를 사용한다.
	//string input;
	//cin >> input;
	//cout << input << endl;


	//cin >> input;//이렇게 하면 약간 문제가잇어
	//공백이잇으면 입력이 중단됨
	//그래서 그걸 해결하기위한 함수가있다.. ㅎㄷㄷㄷㄷㄷ

	string input, addr;
	cout << "이름을 입력하세요 : ";
	cin >> input;
	cin.ignore(); // 엔터키 ㄴㄴ
	cout << "주소를 입력하세요 : ";
	getline(cin, addr);
	cout << addr << "의" << input << "씨 안녕하세요?" << endl;

}