// Academy_20210615_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "Animal.h"
#include "Student.h"

int main()
{
    Dog d;
    //오버라이딩 : 멤버함수를 재정의 
    //조건 반환형,이름,매개변수가 같아야한다.
    //우선권이 있다.
    d.Speak();

    Student s("나이가",2050, "남극해");
    s.Print();
}
