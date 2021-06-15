#include <windows.h>
#include <stdio.h>
#include "resource.h"

void OnTimer(HWND hWnd);  // 타이머 시작
void OnPaint(HWND hWnd);  // 페인트 시작

HINSTANCE g_hInst;

typedef struct ObjectTag
{
    int x; // x좌표
    int y; // y좌표
    int bLife; // 살아 있는지 체크
}Object;

#define MAX 1

Object hero; // 나의 비행기 오브젝트
Object bullet[MAX]; // 미사일 오브젝트
Object enemy; // 적군 비행기 오브젝트
Object bong; // 폭파 장면의 오브젝트

void Init(HWND hWnd); // 초기화 함수
void GetKeyInput(HWND hWnd); // 키보드 처리 함수
void Bullet(HWND hWnd); // 총알


LRESULT CALLBACK WndProc(HWND hWnd,  // 골백 함수 프로시저
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,     // 윈 메인 함수
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    g_hInst = hInstance;
    char szTitleName[] = "게임좀 만들자구요";   // 게임 타이틀 명

    HWND hWnd;
    MSG msg;
    WNDCLASSEX wnd;

    wnd.cbSize = sizeof(wnd);
    wnd.style = CS_HREDRAW | CS_VREDRAW;
    wnd.lpfnWndProc = WndProc;
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    wnd.hInstance = hInstance;
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 백그라운드는 하얀색
    wnd.lpszClassName = szTitleName;
    wnd.lpszMenuName = NULL;

    RegisterClassEx(&wnd);

    hWnd = CreateWindow(szTitleName, szTitleName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
        CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL); // 비디오 모드

    ShowWindow(hWnd, nCmdShow);  // 쇼윈도우 함수 발동
    UpdateWindow(hWnd);  //   업테이트 윈도우 발동   

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);  // 운반 메세지
        DispatchMessage(&msg);  // 메세지 발송
    }

    return msg.wParam;
}

HBITMAP hBMBuf, hBMStage, hBMBullet;  // 버프 화면 ,스타트 화면 , 미사일 화면
HBITMAP hBMMyShap[3];  // 아군 3개 화면
HBITMAP hBMEnemy[3];  // 적군 3개 화면
HBITMAP hBMBong[6];  //폭발화면 6개

LRESULT CALLBACK WndProc(HWND hWnd,  // 골백 함수 호출
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:   // 더불유엠 크레이트 함수 발동 첫 화면 출력후에 메시지 처리
        SetTimer(hWnd, 1, 1, NULL);  // 타이머를 살린다
        Init(hWnd);  // 시작 핸들

        hBMStage = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_STAGE)); // 스타트 배경화면

        hBMMyShap[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MyShap1)); // 주인공 비행기 비트맵1
        hBMMyShap[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MyShap2)); // 주인공 비행기 비트맵2
        hBMMyShap[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MyShap3)); // 주인공 비행기 비트맵3

        hBMBullet = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Bullet)); // 아군이 쏘는 미사일 비트맵 

        hBMEnemy[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Enemy1)); // 적군 비행기 비트맵1
        hBMEnemy[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Enemy2)); // 적군 비행기 비트맵2
        hBMEnemy[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Enemy3)); // 적군 비행기 비트맵3

        hBMBong[0] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG1)); // 적군의 폭발 비트맵 1
        hBMBong[1] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG2)); // 적군의 폭발 비트맵 2
        hBMBong[2] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG3)); // 적군의 폭발 비트맵 3
        hBMBong[3] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG4)); // 적군의 폭발 비트맵 4
        hBMBong[4] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG5)); // 적군의 폭발 비트맵 5
        hBMBong[5] = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BONG6)); // 적군의 폭발 비트맵 6
        return FALSE;
    case WM_TIMER: //SetTimer 함수의 보조 역할로 타이머를 설치했을 경우 지정한 시간 간격으로
     // 이 메시지가 반복적으로 큐에 붙여진다
        OnTimer(hWnd);   // OnTimer(HWND hWnd)값을 살린다
        return FALSE;
    case WM_PAINT:
        OnPaint(hWnd);   // OnPaint(HWND hWnd)값을 살린다
        return FALSE;
    case WM_DESTROY:    // 메세지 루프 종료 메세지
        KillTimer(hWnd, 1);  // 타이머를 죽인다
        DeleteObject(hBMStage);  // hBMStage 즉 배경 스타트 화면을 삭제한다
        DeleteObject(hBMBuf);    // 버프를 삭제한다
        PostQuitMessage(0);    // 더이상 메세지 실행하지 않음
        break;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void OnTimer(HWND hWnd)
{
    Sleep(30);  // 타이머를 30동안 잠재운다
    RECT crt;
    GetClientRect(hWnd, &crt);
    HDC hDC = GetDC(hWnd);
    HDC hBufDC, hStageDC;

    HBITMAP hBMOldBuf, hBMOldStage;

    static BOOL bStop = FALSE;
    static int nStage = 6531 - crt.bottom;
    static int nSWMyShap = 0;  // 아군기
    static int nSWEnemy = 0;   // 적군기
    static int bBong = 0;      // 폭발장면

    if (hBMBuf == NULL)
    {
        hBMBuf = CreateCompatibleBitmap(hDC, crt.right, crt.bottom);
    }

    hBufDC = CreateCompatibleDC(hDC);
    hBMOldBuf = (HBITMAP)SelectObject(hBufDC, hBMBuf);

    // 배경 출력
    hStageDC = CreateCompatibleDC(hDC);
    hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMStage);

    BitBlt(hBufDC, 0, 0, crt.right, crt.bottom,
        hStageDC, 0, nStage, SRCCOPY);
    //  스테이지의 끝에 도달하면
    if (bStop == FALSE)  // 만약 그릇되게 멈추면
    {
        nStage -= 3;  // 3의 속도로 세로로 스코롤 시켜라(만약 여기 속도가 0이면 화면이 멈춘다)
        if (nStage <= 0)  // 만약 속도가 0보다 작으면 아래 명령에 따른다
        {
            bStop = TRUE;   // 이경우에 스탑되더라도 참값으로 계속 진행하라
        }

    }

    // 키보드 처리
    GetKeyInput(hWnd);  // 키보드 핸들 생성, 이함수 없으면 키보드 키 작동 안됨 

    // 미사일
    Bullet(hWnd);    // 미사일 핸들로써 미사일을 움직이게 만드는 함수

    // 적 비행기
    if (enemy.bLife == TRUE)
    {
        switch (nSWEnemy)
        {
        case 0:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMEnemy[0]);
            TransparentBlt(hBufDC, enemy.x, enemy.y, 32, 31,
                hStageDC, 0, 0, 32, 31, RGB(0, 255, 0));
            nSWEnemy = 1;
            break;
        case 1:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMEnemy[1]);
            TransparentBlt(hBufDC, enemy.x, enemy.y, 32, 31,
                hStageDC, 0, 0, 32, 31, RGB(0, 255, 0));
            nSWEnemy = 2;
            break;
        case 2:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMEnemy[2]);
            TransparentBlt(hBufDC, enemy.x, enemy.y, 32, 31,
                hStageDC, 0, 0, 32, 31, RGB(0, 255, 0));
            nSWEnemy = 0;
            break;
        }
    }

    // 미사일

    hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBullet);

    for (int i = 0; i < MAX; i++)
    {
        TransparentBlt(hBufDC, bullet[i].x, bullet[i].y, 17, 15,
            hStageDC, 0, 0, 17, 15, RGB(0, 0, 0));
    }

    // 폭파
    if (bong.bLife == TRUE)
    {
        switch (bBong)
        {
        case 0:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[0]);
            TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
                hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
            bBong = 1;
            break;
        case 1:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[1]);
            TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
                hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
            bBong = 2;
            break;
        case 2:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[2]);
            TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
                hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
            bBong = 3;
            break;
        case 3:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[3]);
            TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
                hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
            bBong = 4;
            break;
        case 4:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[4]);
            TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
                hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
            bBong = 5;
            break;
        case 5:
            hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMBong[5]);
            TransparentBlt(hBufDC, bong.x, bong.y, 28, 26,
                hStageDC, 0, 0, 28, 26, RGB(0, 255, 0));
            bBong = 0;
            bong.bLife = FALSE;
            enemy.bLife = TRUE;
            break;
        }
    }
    // 나의 비행기 출력
    switch (nSWMyShap)
    {
    case 0:
        hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMMyShap[0]);
        TransparentBlt(hBufDC, hero.x, hero.y, 57, 42, hStageDC, 0, 0, 57, 42, RGB(0, 255, 0));
        nSWMyShap = 1;
        break;
    case 1:
        hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMMyShap[1]);
        TransparentBlt(hBufDC, hero.x, hero.y, 57, 42, hStageDC, 0, 0, 57, 42, RGB(0, 255, 0));
        nSWMyShap = 2;
        break;
    case 2:
        hBMOldStage = (HBITMAP)SelectObject(hStageDC, hBMMyShap[2]);
        TransparentBlt(hBufDC, hero.x, hero.y, 57, 42, hStageDC, 0, 0, 57, 42, RGB(0, 255, 0));
        nSWMyShap = 0;
        break;
    }

    SelectObject(hStageDC, hBMOldStage);
    SelectObject(hBufDC, hBMOldBuf);

    DeleteDC(hStageDC);
    DeleteDC(hBufDC);

    ReleaseDC(hWnd, hDC);

    InvalidateRect(hWnd, NULL, FALSE);
}

void OnPaint(HWND hWnd)
{
    RECT crt;
    GetClientRect(hWnd, &crt);
    PAINTSTRUCT ps;
    HDC hDC = BeginPaint(hWnd, &ps);
    HDC hMemDC;
    HBITMAP hOldBit;


    hMemDC = CreateCompatibleDC(hDC);
    hOldBit = (HBITMAP)SelectObject(hMemDC, hBMBuf);
    BitBlt(hDC, 0, 0, crt.right, crt.bottom, hMemDC, 0, 0, SRCCOPY);
    SelectObject(hMemDC, hOldBit);
    DeleteDC(hMemDC);
    EndPaint(hWnd, &ps);

}

void Init(HWND hWnd)
{
    // 나의 비행기 초기화
    RECT crt;
    GetClientRect(hWnd, &crt);

    hero.x = (crt.right / 2) - (57 / 2);
    hero.y = crt.bottom - 100;
    hero.bLife = 3;

    // 총알
    for (int i = 0; i < MAX; i++)
    {
        bullet[i].bLife = FALSE;
        bullet[i].y = -20;
        bullet[i].x = 10;
    }

    // 적 비행기
    enemy.bLife = TRUE;
    enemy.x = 0;
    enemy.y = 50;

    // 뻥
    bong.bLife = FALSE;

}

void GetKeyInput(HWND hWnd)  // 키보드 입력 처리
{
    RECT ctr;
    GetClientRect(hWnd, &ctr);
    static int i = 0;

    if (GetAsyncKeyState(VK_LEFT))   // 왼쪽 키보드키
    {
        hero.x -= 7;  // x축으로 7만큼의 속도로 이동한다

        if (hero.x <= 0)
            hero.x = 0;
    }

    if (GetAsyncKeyState(VK_RIGHT)) // 오른쪽 키보드키
    {
        hero.x += 7;   // x축으로 7만큼의 속도로 이동한다

        if (hero.x >= ctr.right - 57)
            hero.x = ctr.right - 57;
    }

    if (GetAsyncKeyState(VK_UP))  // 위방향 키보드키
    {
        hero.y -= 7;   // v축으로 7만큼의 속도로 이동한다

        if (hero.y <= 0)
            hero.y = 0;
    }

    if (GetAsyncKeyState(VK_DOWN))  //아래 방향 키보드키
    {
        hero.y += 7;  // y축으로 7만큼의 속도로 이동한다

        if (hero.y >= ctr.bottom - 42)
            hero.y = ctr.bottom - 42;
    }

    if (GetAsyncKeyState(VK_SPACE))   // 스페이스바 키보드 키
    {
        if (bullet[i].bLife == FALSE)    // 만약 미사일이 거짓이 되고 살지 못한다
        {
            bullet[i].bLife = TRUE;  // 미사일이 참값으로 발사된다
            bullet[i].x = hero.x + 20; // 미사일이 x축으로 플러스 20해서 발사된다
            bullet[i].y = hero.y;    // 미사일이 v축으로 발사된다
        }
        if (i++ > MAX)
            i = 0;
    }


}

void Bullet(HWND hWnd)
{
    static int nSw = 0;
    if (nSw == 0)
    {
        enemy.x += 7;

        if (enemy.x >= 640 - 32)
        {
            nSw = 1;
        }
    }
    if (nSw == 1)
    {
        enemy.x -= 7;

        if (enemy.x <= 0)
        {
            nSw = 0;
        }
    }



    for (int i = 0; i < MAX; i++)
    {
        bullet[i].y -= 30;   // 미사일의 속도를 수치로 입력

        // 미사일이 화면 밖으로 나가면
        if (bullet[i].y < -15)
            bullet[i].bLife = FALSE; // 거짓으로 정상작동되지 않는다

           // 충돌체크
        if ((bullet[i].y < enemy.y + 31) && (bullet[i].y > enemy.y))
            // 미사일 i가 적군기와 v축으로 31안에 도달했을때 충돌하라
        {
            if ((bullet[i].x > enemy.x) && (bullet[i].x < enemy.x + 32))
                // 미사일 i가 적군기와 x축으로 32안에 도달했을때 충돌하라
            {
                bullet[i].bLife = FALSE;   // 미사일이 i값이면 생명은 거짓으로 죽는다
                enemy.bLife = FALSE;       // 적군기가 죽는다.
                bong.bLife = TRUE;         // 폭발화면이 발생하며 화면에 나타난다 
                bong.x = enemy.x;          // 폭발화면은 적군기의 x축에서 발생하라
                bong.y = enemy.y;          // 폭발화면은 적군기의 v축에서 발생하라
            }
        }

    }
}