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
    void Set() { cout << "�н���" << endl; };

private:

};

class Truck {

public:
    int people;
    void setpeople(const int people) { this->people = people; }
    void Set() { cout << "Ʈ��" << endl; };
};

class PickUp : public Truck, public PassangerCar {

};




int main()
{
    //���ϵ� ��ü�� ����������

    //Parent�� �ν��ؼ� �����ҋ� �θ�� �νĵ�
    Parent* p = new Child();

    delete p;

    PickUp* pc = new PickUp();
    //pc->Set();
}

