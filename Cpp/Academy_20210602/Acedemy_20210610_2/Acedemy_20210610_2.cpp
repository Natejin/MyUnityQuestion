#include<iostream>
//#pragma warnig
#pragma warning(disable:4996)
using namespace std;

int main() {

	//문자열 상수 ABCD의 시작주소를 저장하라는 의미
	//const char* p = "ABCD";
	//// char* p = "ABCD"; 그냥 쓰면 오류
	////그냥쓸라면 속성들어가서 뭐해야함
	////언어 준수 모드 고쳐야하는데 잘모르겟음

	//cout << p << endl;
	////ABCD 나온다
	//cout << p+1 << endl;
	////BCD 나온다

	////p[0] = 'X'; 이거 오류남
	////얘자체가 문자열 상수기때문에 바꿀수가없다

	//char str[] = "QWER";
	//str[0] = 'A';
	//cout << str << endl;
	////잘됨 AWER

	//p = str;
	//cout << p << endl;
	//잘됨 AWER나옴

	//포인터 변수 상수화 목적
	//const 어디에 붙이냐에 따라 다른기능
	//데이터안정성을위해서 const 건다
	//1. 포인터 변수에 다른 메모리 공간의 주소를 저장하지 못하게한다.
	//(오로지 하나의 주소만 저장)
	//const키워드가 어디에 붙었을때 어떤동작을 하는지 반드시 물어봄

	char a = 'A';
	char b = 'B';

	char* const p = &a;//상수화를 시켯음 p = &a 이거를 오로지 a의 주소만 저장가능
	//그래서 아래꺼
	//p = &b;에러남 

	//2. 포인터 변수를 통해 메모리 공간의 값을 변경하지 못하게한다.

	char a1 = 'A';
	char b2 = 'B';

	const char* p1 = &a;
	//*p1 = 'D'; 오류남

	//3. 포인터 변수를 통해 메모리 공간의 주소와 값 모두 변경하지 못하게한다.
	//안정성 보장 목적이다 이것도
	char a2 = 'A';
	char b2 = 'B';

	const char* const p2 = &a;
	//p2=&b;
	//*p2='D'; 둘다오류남 

	//const키워드 실질적인 용도 : 포인터 변수가 저장하는 주소나
	//접근하는 값에 읽기속성을 적용하는데 주로 사용
	//read only 읽기만해라
	//그냥 const를 쓰는것을 권장

	/*문자열중요한데 문자열로 장난치는거 많이 나온다
	길이를 구해서 뭘하고 뭘하고
	문자열 A~Z 잇는데 대문자만 출력하거나
	역순으로 출력해보세여*/

	/////////////

	char engStr[] = "HelloWorld";
	char korStr[] = "안녕하세요";
	cout << "영문 문자열의 길이 : " << strlen(engStr) << endl;
	cout << "한글 문자열의 길이 : " << strlen(korStr) << endl;

	cout << "영문 문자열의 크기 : " << sizeof(korStr) << endl;
	cout << "한글 문자열의 크기 : " << sizeof(korStr) << endl;

	//문자열 비교
	char str[10] = "Hello";
	const char* str1 = "Hello";
	int res = strcmp(str, str1);//문자열 비교 함수
	cout << res << endl;//0나왓음 같으면 0나옴
	//앞이크면 1 뒤가크면 -1
	//비교는 아스키코드로 비교함

	cout << strcmp("aaa", "aaa") << endl;
	//0나옴
	cout << strcmp("aab", "aaa") << endl;
	//1나옴
	//a 의 아스키10진수로97
	//b 의 아스키10진수로98
	cout << strcmp("aab", "aaf") << endl;
	//-1나옴

	char str2[6] = "Hello";
	char str3[6];//str3이[4]면 안됨 크면되긴함

	//strcpy(str3, str2)
	//strcpy_s(str3, str2);//문자열 복사 함수 뒤에껄 앞에 넣겟다.
	//cout << str3 << endl; 그냥 strcpy쓰면 보안성이 위험해서 쓰지마세요 오류뜸
	//1행에 PRAGMA 오류 무시 선언하면됨

	//문자열 붙이기

	char str4[10] = "world";
	char str5[20] = "Hello";
	strcat(str5, str4);//뒤에껄 앞변수 뒤에 붙인다.
	cout << str5 << endl;

	//문자열 자르기

	char str6[30] = "abcd / efgh";
	char str7[30] = "i am a boy";

	const char* ptr = strtok(str7, " ");
	const char* ptr1 = strtok(str7, " ");
	//스트링 토큰 공백기준으로 해당문자열을 자르겟다
	//포인터를 반환

	while (ptr != NULL)//자른문자열이 나오지않을때까지 돌려라
	{
		cout << ptr << endl;//자른녀석 출력
		ptr = strtok(NULL, " ");
		//다음 문자열을 잘라서 포인터 반환
	}
	while (ptr1 != NULL)//자른문자열이 나오지않을때까지 돌려라
	{
		cout << ptr1 << endl;//자른녀석 출력
		ptr1 = strtok(NULL, "/");
		//다음 문자열을 잘라서 포인터 반환
	}
	char str8[30] = "i am a boy";

	const char* ptr2 = strtok(str8, 'a');
	//a로 시작하는~문자열검색

	while (ptr2 != NULL)
	{
		cout << ptr2 << endl;
		prt2 = strchr(ptr1 + 1, 'a');
		//포인터에 1을 더해서 a다음부터~
	}

	/////////
	//콘솔 자료 참고
}