// Acedemy_20210610_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


//1. 대전게임을 -> 구조체로 써서
//2. 객체지향이란 무엇인가?
//3. 캡슐화 다형성, 상속, 추상화
struct Car {
    int colorl; // 상태

    void ForwardMove();

};

//기본적으로 private
class MyClass {
private:

public:
    MyClass();
    ~MyClass();


};

class CClass {
private:
    int color;
    int speed;
    int gear;

   
public:
    void ForwardMove();
    void Stop();

};

int main()
{
    
}
