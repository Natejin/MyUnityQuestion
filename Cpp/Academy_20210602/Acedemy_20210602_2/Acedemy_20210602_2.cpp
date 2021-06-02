// Acedemy_20210602_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    //연산자
    //사칙연산자
    //+,-,*,/
    //% 몫은 버리고 나머지만

    //축약형
    //+=, -=
    

    cout << 1 + 2 << endl;
    cout << 2 - 1 << endl;
    cout << 2 * 5 << endl;
    cout << 3 / 2 << endl;

    int num = 2;
    num = 5;
    cout << "num값 : " << num << endl;

    int num1 = 1;
    int num2 = 3;
    int result = num1 + num2;

    cout << num1 + num2 << endl;
    cout << result << endl;

    int num3 = 5;
    int num4 = 6;
    int num5 = 7;

    int result1 ;

    result1 = num3 + num4 * num5;
    cout << result1 << endl;
    
    cin >> num3;
    cin >> num4;
    cin >> num5;

    result = num3 + num4 + num5;
    float result2 = result / 3;
    cout << "세개의 입력 받은 정수 : " << num3 << "," << num4 << "," << num5 << "의 합은 " << result << "이며 평균값은 " << result2 / 3 << endl;

    //Ctrl+F5 디버길 하지 않고 시작
    //F5 디버깅 시작
    //F10 프로시저 단위로 실행
    //F11 한단계씩 코드 실행

    //자료형 변수이름
    //int a;

    int a, b, c;
    int damage1, damage2;


}
