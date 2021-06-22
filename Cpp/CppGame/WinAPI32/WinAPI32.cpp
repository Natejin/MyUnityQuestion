#pragma comment(lib, "winmm.lib")


#include<Windows.h>
#include <string>
#include <windef.h>
#include <stdint.h>
#include <vector>
using namespace std;

// 운영체제
HINSTANCE m_hInstance;

// 윈도우 핸들러
HWND m_hWnd;

// 좌상단의 타이틀 텍스트
LPTSTR m_lpszClass = TEXT("안녕");
int oh = 0;


// 콜백함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void DrawAppleLogo(HDC& hdc, const HWND& hWnd, PAINTSTRUCT& ps);

// 인스턴스 핸들 이전 인스턴스 핸들, 명령으로 이루어진 , 프로그램이 시작될 행동
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdParam, int nCmdShow)
{
    m_hInstance = hInstance;

    //윈도우창의 구조를 저장하는 클래스
    WNDCLASS wndClass;

    //윈도우에서 사용하는 데이터단위를 바이트로 지정
    wndClass.cbClsExtra = 0;

    //개별메모리에서 사용하는 여분의 메모리
    wndClass.cbWndExtra = 0;

    //윈도우 작업영역에 칠한 배경 브러쉬
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

    //커서 지정
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

    //타이틀바의 좌상단 아이콘, 최소화 아이콘
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    // 응용프로그램의 인스턴스 핸들러
    wndClass.hInstance = hInstance;

    // 메세지 처리하는 함수
    wndClass.lpfnWndProc = (WNDPROC)WndProc;

    //등록하고자하는 윈도우스 이름
    wndClass.lpszClassName = m_lpszClass;

    //윈도우 클래스 지정
    wndClass.lpszMenuName = NULL;

    // 윈도우 스타일 지정
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // 윈도우 클래스 지정
    RegisterClass(&wndClass);




    m_hWnd = CreateWindow(m_lpszClass, m_lpszClass, WS_OVERLAPPEDWINDOW,
        100, 100, 1024, 768, NULL, NULL, hInstance, NULL);

    ShowWindow(m_hWnd, nCmdShow);

    // 운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
    MSG message;

    //GetMessage: 대기상태
    while (GetMessage(&message, 0, 0, 0))
    {
        // 키보드 입력 메세지 처리담당
        TranslateMessage(&message);
        // 원도우 프로시져에 전달된 메세지를 실제 윈도우에 전달
        DispatchMessage(&message);
    }

    return message.wParam;
}

static RECT rcHead = { 25,25,50,50 };
int dir[4] = { 0, 0, 1, 1 };
vector<RECT> rc;
//메세지 번호, 키보드 조합키,  마우스 관련
//원도우 프로시져 : 메세지를 운영체제에 전달한다. 강제로 운영체제가 호출
//hWnd : 윈도우가 발생한 메세지인지 구분
//imessage : 메세지 구분 번호

//wParam : 마우스 버튼의 상태, 키보드 조합키의 상태를 전달한다.
//iParam : 마우스 클릭좌표 상태를 전달한다.



LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    //DC : device context ->출력에 관한 옵션을 디폴트로 설정

    //DC 를 사용하기 위해 HDC, DC의 핸들 이용

    //GDI 모듈에 의해 관리

    //GDI 화면 처리와 그래픽 출력을 한다.

    //HDC 출력에 필요한 정보를 가지는 데이터 구조체 (좌표,굵기 색등등 필요한 모든정보를 가지고 있다)


    // 출력에 관한 정보를 갖는 데이터의 구조체 좌표 굵기 색 등
    //HDC hdc;

    //PAINTSTRUCT : 윈도우 클라이언트 영역을 그리기 위한 정보를 저장한 구조체
 /*   PAINTSTRUCT ps;*/


    
    PAINTSTRUCT ps;
    HDC hdc;
    float speed = 1;
    static int time = 0;
    char* szTime[128];
    static float m_fStartTime = 0;
    float NowTime = 0;

    //루프 
    
    //int StartTick
   
    //rc.top += speed * 1;
    //rc.bottom += speed * 1;
    switch (iMessage)
    {
        // 윈도우 만들어질때 한번 호출되는 메세지
    case WM_CREATE:
        //시작부분
        //m_fStartTime = (float)timeGetTime() * 0.001f;   //초단위로 바꿔줌
        SetTimer(hWnd, 0, 1000, NULL);


        break;
    case WM_TIMER:
        time++;
       //NowTime = (float)timeGetTime() * 0.001f;    //초단위로 바꿔줌

       // if (NowTime - m_fStartTime >= 0.01f)   // 여기서 0.1 은 0.1초마다 실행을 의미
       // {

       //     if (rcHead.left + speed * dir[1] > 0 &&
       //         rcHead.right + speed * dir[0] < 500 &&
       //         rcHead.top + speed * dir[2] > 0 &&
       //         rcHead.bottom + speed * dir[3] < 500)
       //     {
       //         rcHead.left += speed * dir[1];
       //         rcHead.right += speed * dir[0];
       //         rcHead.top += speed * dir[2];
       //         rcHead.bottom += speed * dir[3];
       //     }
       // }

       // m_fStartTime = NowTime;
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_RIGHT:
            dir[0] = 1;
            dir[1] = 1;
            dir[2] = 0;
            dir[3] = 0;
            break;
        case VK_LEFT:
            dir[0] = -1;
            dir[1] = -1;
            dir[2] = 0;
            dir[3] = 0;
            break;
        case VK_DOWN:
            dir[2] = 1;
            dir[3] = 1;
            dir[1] = 0;
            dir[0] = 0;
            break;
        case VK_UP:
            dir[2] = -1;
            dir[3] = -1;
            dir[1] = 0;
            dir[0] = 0;
            break;
        case VK_RETURN:

            break;
        default:
            break;
        }
        break;
    case WM_PAINT: // 그림그리는 곳
        ////DrawAppleLogo(hdc, hWnd, ps);
        hdc = BeginPaint(hWnd, &ps);
        //sprintf(szTime, "%d 초 지났습니다.", time);

        //TextOut(hdc, 100, 100, szTime, strlen(szTime));

        //Rectangle(hdc, rcHead.left, rcHead.top, rcHead.right, rcHead.bottom);
        EndPaint(hWnd, &ps);


        break;
        // 왼쪽 마우스 클릭시
    case WM_LBUTTONDOWN:

        rcHead.left += 50;



        break;
    case WM_DESTROY: // 윈도우 종료시 
        KillTimer(hWnd, 1);

        PostQuitMessage(0);
        return 0;
    }
    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}






void DrawAppleLogo(HDC& hdc, const HWND& hWnd, PAINTSTRUCT& ps)
{
    HBRUSH brush, oBrush;


    POINT pt = { 100,100 };
    POINT pline1[14] = {
100,170,
380,170,
377,178,
374,186,
371,194,
368,202,
365,210,
362,218,
88,218,
90,210,
92,202,
94,194,
96,186,
98,178
    };
    Polygon(hdc, pline1, 14);
    brush = CreateSolidBrush(RGB(255, 255, 0));
    oBrush = (HBRUSH)SelectObject(hdc, brush);
    SelectObject(hdc, oBrush);
    DeleteObject(brush);



    ////텍스트
    //TextOut(hdc, 300, 500, L"야이자식아!!", lstrlen(L"야이자식아!!"));

    //색깔
    //SetTextColor(hdc, RGB(255, 0, 0));
    //TextOut(hdc, 100, 100, L"뭔데 이것아!!", lstrlen(L"뭔데 이것아!!"));

    EndPaint(hWnd, &ps);
}

//
//
//
//void UpdateFPS()
//{
//
//    static DWORD frameCount = 0;            //프레임 카운트수
//    static float timeElapsed = 0.0f;            //흐른 시간
//    static DWORD lastTime = timeGetTime();   //마지막 시간(temp변수)
//
//    DWORD curTime = timeGetTime();      //현재 시간
//    float timeDelta = (curTime - lastTime) * 0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.
//
//    timeElapsed += timeDelta;
//
//    frameCount++;
//
//    if (timeElapsed >= 1.0f)         //흐른시간이 1초이상이면 내가 하고싶은것 처리
//    {
//        float fps = (float)frameCount / timeElapsed;
//        sprintf_s(pFPS, sizeof(pFPS), TEXT("게임속도 FPS: %f"), fps);     //FPS출력 하는 소스
//
//        frameCount = 0;
//        timeElapsed = 0.0f;
//    }
//    else
//    {
//        //흐른 시간이 1초가 안되면 생략함  
//        //Sleep() 해도되고 안해도 되구~ 
//    }
//
//
//    lastTime = curTime;
//}