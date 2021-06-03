#include <iostream>
#include <array>

using namespace std;

int main()
{
	int num; //num이라는 이름의 변수 선언

	//정수의 저장이 가능한 메모리 공간을 할당하고 그 메모리 공간의 이름 num

	num = 10;
	int num1 = 10;
	// int Age != age; // 대소문자 구분
	
	//자료형 
	//	데이터를 표현하는기준 
	//	메모리를 할당할 공간이기에 정시해줘야한다.

	//연산자														결합 방향			예
	//	이항연산자 : 두개의 피연산자를 요구하는 연산자
	//	= : 연산자 오른쪽에 있는 값을 왼쪽에 있는 변수에 대입			<-			int a = 1;
	//	+ : 두 피연산자의 값을 더한다.								->
	//	- : 왼쪽에 피연산자의 값에 오른쪽의 피연산자 값을 뺸다			->
	//	* : 곱한다.													->		
	//	/ : 왼쪽의 피연산자 값을 오른쪽의 피연사자 값으로 나눈다.		->
	//	% : 왼쪽의 피연산자 값을 오른쪽의 피연사자 값으로 나눈 나머지	->

	//복합 대입 연산자
	// a = a+b		----->	 a+=b;
	// a = a-b		----->	 a-=b;
	// a = a*b		----->	 a*=b;
	// a = a/b		----->	 a/=b;
	// a = a%b		----->	 a%=b;

	//증가 감소 연산자
	//	단항연산자로써 활용빈도가 매우높다.
	//	++a;	(전위연산) 값을 1증가 후 속한 문장의 나머지를 진행한다. (선증가후 대입)		결합방향은 <-
	//	a++;	(후위연산) 속한 문장을 먼저 진행한후 값을 1증가 (선 연산, 후 감소)			결합방향은 ->
	//	--a;	(전위연산) 값을 1감소 후 속한 문장의 나머지를 진행한다. (선 감소, 후 대입)		결합방향은 <-
	//	a--;	(후위연산) 속한 문장을 먼저 진행한후 값을 1감소 (선 연산, 후 감소)			결합방향은 ->	

	//관계 연산자 
	// 대소와 동등의 관계를 따지는 연산자;
	//	a<b		:	a가 b보다 작은가?
	//	a>b		:	a가 b보다 큰가?
	//	a<=b	:	a가 b보다 같거나 작은가?
	//	a>=b	:	a가 b보다 같거나 큰가?
	//	a==b	:	a와 b가 같은가?
	//	a!=b	:	a와 b가 같지 않은가?
	//
	//	관계연사자가 조건을 만족하면 true(1), 아니면 false(0)

	//논리 연산자
	//	0이 아닌 모든값은 true;
	//	&&(AND)	:	a && b		a와 b가 true면 true 그외에는 false
	//	||(OR)	:	a || b		a와 b중 하나라도 true면 true 그외에는 false
	//	!		:	!a			a가 true면 false, false면 true;
	
	//비트 연산
	//	&(AND)	: 두개의 비트가 모두 1일때 1을 반환
	// 	   0 & 0 : 0
	// 	   0 & 1 : 0
	// 	   1 & 0 : 0
	// 	   1 & 1 : 1
	// 
	//	|(OR)	: 두개의 비트중에 하나라도 1일때 1을 반환
	// 	   0 | 0 : 0
	// 	   0 | 1 : 1
	// 	   1 | 0 : 1
	// 	   1 | 1 : 1
	// 
	//	^(XOR)	: 두개의 비트가 다를떄 1을 변환
	// 	   0 | 0 : 0
	// 	   0 | 1 : 1
	// 	   1 | 0 : 1
	// 	   1 | 1 : 0

	//shift연산(비트 이동)
	//	비트의 열을 왼쪽으로 1칸씩 이동할때마다 정수의 값은 2배
	//	반대로 오른쪽으로 이동할떄마다 정수의 값은 2로 나누어진다.
	//	상황에 따라 곱셈과 나눗셈은 비트 이동으로 대체 할수 있다.








	cout << "================증가 감소 연산자========================" << endl;
	int a = 15;
	int b = 15;

	cout << "a : " << a << endl;
	cout << "a의 후위 증가 :" << a++ << endl;
	cout << "b의 선위 증가 :" << ++b << endl;

	cout << "================관계 연산자========================" << endl;

	int result[6];
	string symbol[6];

	result[0] = a < b;
	result[1] = a > b;
	result[2] = a <= b;
	result[3] = a >= b;
	result[4] = a == b;
	result[5] = a != b;

	symbol[0] = "<";
	symbol[1] = ">";
	symbol[2] = "<=";
	symbol[3] = ">=";
	symbol[4] = "==";
	symbol[5] = "!=";

	cout << sizeof(result) << endl;

	int resultCount = sizeof(result) << 2;
	for (int i = 0; i < resultCount; i++)
	{
		cout << "a "<< symbol[i] << " b : " << result[i] << endl;
	}

	cout << "================논리 연산자========================" << endl;
	int number = 10;
	int number1 = 20;
	int res = number == 9 && number1 == 20;
	int res1 = number <= 10 || number1 < 20;
	int res2 = !number1;

	cout << res << endl;
	cout << res1 << endl;
	cout << res2 << endl;

	cout << "================비트 연산자========================" << endl;
	int bitNum = 15;			//0000 1111
	int bitNum1 = 20;			//0001 0100
								//----------
	//bitNum & bitNum1			//0000 0100

	int bitResult = bitNum & bitNum1;
	cout <<"bitNum("<< bitNum <<")&" << "bitNum1("<<bitNum1 << ") = "<< bitResult <<endl;



	 bitNum = 15;				//0000 1111
	 bitNum1 = 20;				//0001 0100
								//----------
	//bitNum | bitNum1			//0001 1111

	bitResult = bitNum | bitNum1;
	cout << "bitNum(" << bitNum << ")|" << "bitNum1(" << bitNum1 << ") = " << bitResult << endl;


	bitNum = 15;				//0000 1111
	bitNum1 = 20;				//0001 0100
							   //----------
   //bitNum | bitNum1			//0001 1011

	bitResult = bitNum ^ bitNum1;
	cout << "bitNum(" << bitNum << ")^" << "bitNum1(" << bitNum1 << ") = " << bitResult << endl;

	cout << "================ Shift 연산자 ==================" << endl;
	int sNum = 15;	// 00001111
	int sResult = sNum << 1; // 비트를 왼쪽으로 1칸 밀어준다 혹은 곱하기 2;
	int sResult1 = sNum << 2; // 비트를 왼쪽으로 1칸 밀어준다 혹은 곱하기 4;
	int sResult2 = sNum << 3; // 비트를 왼쪽으로 1칸 밀어준다 혹은 곱하기 8;


	cout << sResult << endl;
	cout << sResult1 << endl;
	cout << sResult2 << endl;
	return 0;
}
