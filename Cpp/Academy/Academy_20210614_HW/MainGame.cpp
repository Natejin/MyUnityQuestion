#include "MainGame.h"

using namespace std;

MainGame::MainGame() :key(0)
{
    enemy = new Enemy(100);
    player = new Player(100);
}

MainGame::~MainGame()
{
    delete enemy;
    delete player;

}

void MainGame::Update()
{
    cout << "플레이어 체력 : " << player->GetHP() << endl;
    cout << "고블린 체력 : " << enemy->GetHP() << endl;

    while (true)
    {
        cout << "힙력 : ";
        cin >> key;
        switch ((PLAYERSKILL)key)
        {
        case PLAYERSKILL::NONE:
            cout << "아무것도 하지 않는 패배자다" << endl;
            break;
        case PLAYERSKILL::POSTION:
            player->SetHP(player->GetHP() + 100);
            cout << "플레이어 체력 ㅣ " << player->GetHP() << endl;
            break;
        case PLAYERSKILL::SKILL:
 
            cout << "플레이어가 파이어볼을 시전하여 공격"<< endl;
            enemy->SetHP(enemy->GetHP() - player->GetAtk());
            cout << "고블린 체력 : " << enemy->GetHP() << endl;
            break;
        default:
            break;
        }

    }
}