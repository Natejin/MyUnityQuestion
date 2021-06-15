#include "MainGame.h"

MainGame::MainGame()
{
    mother = new Mother();
    mother->Funciton1();
    mother->Funciton2();
    mother->Funciton3();

    cout << "===================" << endl;
    mother = new Child();
    mother->Funciton1();
    mother->Funciton2();
    mother->Funciton3();
}

MainGame::~MainGame()
{
    

}