#include <Windows.h>





// 운영체제
HINSTANCE m_hInstance;

// 윈도우 핸들러
HWND m_hWnd; 

// 좌상단의 타이틀 텍스트
LPTSTR m_lpszClass = TEXT("열렸다 참깨"); 

// 콜백함수
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


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
    wndClass.lpfnWndProc = (WNDPROC)WndProc;

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


   

    m_hWnd = CreateWindow(
        m_lpszClass,
        m_lpszClass,
        WS_OVERLAPPEDWINDOW,
        //윈도우 좌표 x
        100,

        //윈도우 좌표 y
        100,

        //x 크기
        1024, 
        
        //y 크기
        768,
        NULL,

        (HMENU)NULL,

        hInstance,

        NULL);

    //윈도우를 보여줌
    ShowWindow(m_hWnd, nCmdShow);

    //운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
    MSG message;

    //대기상태
    while (GetMessage(&message, 0,0,0))
    {
        //키보드 입력을 처리 담당
        TranslateMessage(&message);

        //윈도우 프로시저에 전달된 메세지를 실제 윈도우에 전달
        DispatchMessage(&message);
        return message.wParam;
    }

    return message.wParam;
}




//wndProc 행동
LRESULT CALLBACK WndProc(HWND m_hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {

    //GDI 화면출력과 그래픽 담당
    //HDC 출력에 필요한 정보를 가지는 구조체 (좌표, 굵기 ,컬러 등)
    HDC hdc;

    //윈도우 클라이언트 영역을 그리기 위한 구조체
    PAINTSTRUCT ps;




    static BOOL ELLIPSE = FALSE;
    static HWND b2, c1;
    static BOOL MYSELLECT = FALSE;


    switch (iMessage)
    {
        //윈도우가 실행될떄 딱한번 호출
    case WM_CREATE:
    {
        //hbr1 = CreateSolidBrush(RGB(255, 0, 0));
        //hbr2 = CreateSolidBrush(RGB(0, 0, 255));

        //// load player icons
        //hIcon1 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_CROSS));
        //hIcon2 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_CIRCLE));

        //CreateWindow(TEXT("button"), TEXT("Click Me"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        //    20, 20, 100, 25, hWnd, (HMENU)0, hInst, NULL);
        //b2 = CreateWindow(TEXT("button"), TEXT("TextOut"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        //    20, 50, 100, 25, hWnd, (HMENU)1, hInst, NULL);
    }
    break;
    
    case WM_COMMAND:
    {
        //int wmId = LOWORD(wParam);
        //// Parse the menu selections:
        //switch (wmId)
        //{
        //case IDM_ABOUT:
        //    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
        //    break;
        //case IDM_EXIT:
        //    DestroyWindow(hWnd);
        //    break;
        //default:
        //    return DefWindowProc(hWnd, message, wParam, lParam);
        //}
    }
    break;
    //마우스 왼쪽 버튼 클릭시
    case WM_LBUTTONDOWN:
    {
        //int xPos = GET_X_LPARAM(lParam);
        //int yPos = GET_Y_LPARAM(lParam);

        //int ret = MessageBox(hWnd, L"Are you sure u want to start a new game?", L"New Game", MB_YESNO | MB_ICONQUESTION);
        //if (IDYES == ret)
        //{
        //    //// reset and start new game
        //    //playerTurn = 1;
        //    //winner = 0;
        //    //ZeroMemory(gameBoard, sizeof(gameBoard));

        //    //// force a paint message
        //    //InvalidateRect(hWnd, NULL, TRUE);	// post WM_PAINT to our WindowsProc. it gets queued in our msg queue
        //    //UpdateWindow(hWnd);					// forces immediate handling of WM_PAINT
        //}
    }

    break;
    //그림 그리는곳 (작업영역이 손실됬을때 실행됨
    case WM_PAINT:
    {
        //그리기시작
        hdc = BeginPaint(m_hWnd, &ps);

        for (size_t i =200; i < 600; i++)
        {
            for (size_t y = 200; y < 600; y++)
            {
                SetPixel(hdc, i, y, RGB(255, 0, 255));
            }
         
        }



        //그리기 끝
        EndPaint(m_hWnd, &ps);


        //int xPos = GET_X_LPARAM(lParam);
        //int yPos = GET_Y_LPARAM(lParam);
        //PAINTSTRUCT ps;
        //HDC hdc = BeginPaint(hWnd, &ps);

        ////int myIntValue = 20;
        //wchar_t num_charX[10];

        //swprintf_s(num_charX, L"%d", xPos);


        ////wstring name(L"Steve Nash");
        ////const wchar_t* szName = name.c_str();




        ////const WCHAR szPlayer1[] = L"반동분자";

        //TextOutW(hdc, 16, 16, num_charX, ARRAYSIZE(num_charX));
        //// TODO: Add any drawing code that uses hdc here...
        //EndPaint(hWnd, &ps);
    }
    break;
    //윈도우 파괴
    case WM_DESTROY:
  
        //꺼버리기
        PostQuitMessage(0);
        return 0;
       /* DeleteObject(hbr1);
        DeleteObject(hbr2);

        DestroyIcon(hIcon1);
        DestroyIcon(hIcon2);


        PostQuitMessage(0);*/
    default:
        return DefWindowProc(m_hWnd, iMessage, wParam, lParam);
    }
    return DefWindowProc(m_hWnd, iMessage, wParam, lParam);
}

//등록할 윈도우 클래스를 전달