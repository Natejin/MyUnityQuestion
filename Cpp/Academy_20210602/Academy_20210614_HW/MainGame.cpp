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
    cout << "�÷��̾� ü�� : " << player->GetHP() << endl;
    cout << "��� ü�� : " << enemy->GetHP() << endl;

    while (true)
    {
        cout << "���� : ";
        cin >> key;
        switch ((PLAYERSKILL)key)
        {
        case PLAYERSKILL::NONE:
            cout << "�ƹ��͵� ���� �ʴ� �й��ڴ�" << endl;
            break;
        case PLAYERSKILL::POSTION:
            player->SetHP(player->GetHP() + 100);
            cout << "�÷��̾� ü�� �� " << player->GetHP() << endl;
            break;
        case PLAYERSKILL::SKILL:
 
            cout << "�÷��̾ ���̾�� �����Ͽ� ����"<< endl;
            enemy->SetHP(enemy->GetHP() - player->GetAtk());
            cout << "��� ü�� : " << enemy->GetHP() << endl;
            break;
        default:
            break;
        }

    }
}