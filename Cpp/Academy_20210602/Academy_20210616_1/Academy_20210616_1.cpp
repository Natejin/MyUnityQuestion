// Academy_20210616_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Parent.h"
#include "Child.h"


class PassangerCar
{
public:
    int seats;
    void setSeats(const int n) { seats = n; }
    void Set() { cout << "패신저" << endl; };

private:

};

class Truck {

public:
    int people;
    void setpeople(const int people) { this->people = people; }
    void Set() { cout << "트럭" << endl; };
};

class PickUp : public Truck, public PassangerCar {

};




int main()
{
    //차일드 객체를 생성했지만

    //Parent로 인식해서 삭제할떄 부모로 인식됨
    Parent* p = new Child();

    delete p;

    PickUp* pc = new PickUp();
    //pc->Set();
}

