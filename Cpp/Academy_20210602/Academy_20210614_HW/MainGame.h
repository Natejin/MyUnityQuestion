#pragma once
#include<iostream>
#include"Enemy.h"
#include"Player.h"

class MainGameMaster
{
private:
    Enemy* enemy;
    Player* player;
    int key;

public:
    MainGameMaster();
    ~MainGameMaster();

    void Update();
};