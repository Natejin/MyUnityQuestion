// Academy_20210615_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "MainGame.h"

using namespace std;

class Animal
{
public:
   virtual void Speak() { cout << "부모 이스 토킹" << endl; }

};

class Dog : public Animal {

public:
   void Speak() { cout << "개시키가 이스 토킹" << endl; } 
   //부모가 virtual이므로 자식에서 컴파일러가 virtual로 변환됨
};

class Cat : public Animal {

public:
    void Speak() { cout << "고양이년 이스 토킹" << endl; }
};


int main()
{
    //업케스팅 : 자식클래스중에서 부모클래스 부분만 사용할수있다.
    //상향 변환
    
    //Animal* a1 = new Dog();
    //a1->Speak();
    //Animal* a2 = new Cat();
    //a2->Speak();

    //가상함수 : 다형성을 지원하고 재정의할  가능성있으면 가상함수로 선언하는 것이 좋다.
    //자식에서 재정의한 함수가 있으면 자식이 호출되고 없으면 부모의 함수가 호출된다.

    //바인딩 개념
    //동적바인딩 : 실행하는 동안에 호출될 함수가 결정됨 , 
    // 포인터가 가르키는 함수가 뭐냐? 
    // 다형성을 구현할수있다 (virtural)
    // 속도가 상대적으로 느리다 (가상함수 = 다형성을 지원한다.)
    // 컴파일할때 호출할 함수를 결정하지않고 프로그램 실행중에 호출할 함수를 결정
    // 
    // 
    //정적바인딩 : 기본적으로 static 바인딩 : 
    //컴파일 단계에서 모든 마인딩 호출이 완료 
    //컴파일하는동안 대상이 결정되서 속도가 빠르다.
    
    MainGame maingame;
    
}
