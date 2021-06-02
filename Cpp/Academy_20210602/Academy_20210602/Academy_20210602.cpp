// Academy_20210602.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void PrintString(string type, unsigned int size) {
    cout << type <<  "형 사이즈 : " << size << " 바이트" << endl;
}


int globalVariable = 5;
int main()
{
    //출력
    cout << "오늘하루도 즐거운 일만 ㅋㅋㅋ제발..." << endl;
    cout << "수요일 웹툰 재미난거 있으면 추천 바람..." << endl;

    //변수 
    int num = 0; //변수선언 및 초기화
    cout << "num안에 들어있는 값 : " << num  << endl; //num 안에 들어있는 값을 출력

    int num1;
    num1 = 1; //선언하고 초기화
    cout << "num1안에 들어있는 값 : " << num1 << endl; //num 안에 들어있는 값을 출력

    char a = 'a'; //문자를...
    cout << a << endl;

    //변수 이름 지을때 주의할점 절대 하지 말아야 할 점

    //int int;
    //int 1;
    //int 한글;

    int playerAttackDamage = 100;
    cout << "플레이어의 공격력 : " << playerAttackDamage << endl;
    
    float number = 1.12345;
    int number1 = 2.456;
    bool isActive = false;

    //8비트 = 1바이트
    
    //int, short, long, long long - 정수형 4바이트 공간할당
    //float, double, long double - 실수형
    //char -문자형
    //bool  // 코드가 더러워지므로 최소한으로 줄인다.

    cout << "실수 number값 : "  << number << endl;
    cout << "정수 number1값 : " << number1 << endl;
    cout << "bool : " << isActive << endl;
    cout << endl << endl;
    cout << "=============================" << endl;
    cout << "int 형 사이즈 : " << sizeof(int) << " 바이트" << endl;
    PrintString("int", sizeof(int));
    PrintString("float", sizeof(float));
    PrintString("short", sizeof(short));
    PrintString("double", sizeof(double));
    PrintString("bool", sizeof(bool));
    PrintString("char", sizeof(char));



    //입력 cin, scanf
    //출력 cout, printf

    int input; //입력용 변수
    cin >> input; // 입력을 받으면
    cout << "내가 입력한 숫자 : " << input << endl; // 여기에 출력

    //로컬변수(지역변수)  //함수내에 존재
    //전역변수(글로벌 변수)


    //숙제 1
    //데이터 타입 조사 : 몇바이트? 데이터 타입들이 표현할수 있는 범위


    //숙제 2
    //메모리 영역에 대하여 기술해라
}




// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.



