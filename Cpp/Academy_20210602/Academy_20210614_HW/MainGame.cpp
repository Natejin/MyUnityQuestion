#include "..\Academy_20210625\MainGame.h"
#include "..\Academy_20210625\MainGame.h"
#include "..\Academy_20210625\MainGame.h"
#include "..\Academy_20210625\MainGame.h"
#include "MainGame.h"

using namespace std;

MainGameMaster::MainGameMaster() :key(0)
{
    enemy = new Enemy(100);
    player = new Player(100);
}

MainGameMaster::~MainGameMaster()
{
    delete enemy;
    delete player;

}

HRESULT MainGameMaster::Init()
{
    return E_NOTIMPL;
}

void MainGameMaster::Release()
{
}

void MainGameMaster::Update()
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

void MainGameMaster::Render(HDC hdc)
{
}

LRESULT MainGameMaster::MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return LRESULT();
}
