// Acedemy_20210607_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
using namespace std;

int globalVariable;
static int num;
void Test();

//지역변수  (local Variable);   
//전역변수  (global Variable);  수정 유지보수 어려움
//정적변수  (static Variable);  초기화는 한번만 일어남, 전역변수의 단점을 보완하면서 지역변수의 형태 (프로그램 시작하면 초기화 한번만 실행) (초기화 할필요없음)
//정적 전역변수 
//외부변수 (extern Variable);


//구분         지역변수         전역변수          정적지역변수        정적전역변수
//선언위치      중괄호내부       중괄호외부         중괄혼내부          중괄호외부
//생성시점      중괄호내부       프로그램시작시     중괄호내부      프로그램시작시
//소멸시점      중괄호탈출       프로그램 종료시    프로그램종료시     프로그램종료시
//사용범위      중괄호내부       프로그램전체      중괄호내부       선언된소스
//초기화        쓰레기값지정     0으로자동       0으로자동           0으로



//register int a cpu내부에 저장 속도빠름 메모리가 극히 부족함 예 반복문 검사 //컴파일러가 자동으로 설정해줌 //고로 안해도됨



int main()
{
    int localVariable = 1;
    cout << "나는 지역변수 : " << localVariable << endl;
    cout << "나는 전역변수 : " << globalVariable << endl;

    Test();
    cout << "전역변수 num 값 : " << num << endl;
    int index = 0;
    while (index < 10)
    {
        static int num = 0;
        num++;
        cout << num << endl;
        Sleep(300);
        index++;
    }
    cout << "전역변수 num 값 : " << num << endl;
}


int sum(int x, int y) { return x + y; }

void Test() {
    num = 60;
}