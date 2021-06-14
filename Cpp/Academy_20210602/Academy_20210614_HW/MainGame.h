#pragma once
#include<iostream>
#include"Enemy.h"
#include"Player.h"

class MainGame
{
private:
    Enemy* enemy;
    Player* player;
    int key;

public:
    MainGame();
    ~MainGame();

    void Update();
};