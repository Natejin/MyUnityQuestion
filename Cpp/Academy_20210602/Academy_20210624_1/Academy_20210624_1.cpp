// Academy_20210624_1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Academy_20210624_1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ACADEMY202106241, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ACADEMY202106241));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ACADEMY202106241));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR strMouse[64] = {};
    static RECT rc = { 25,25,50,50 };
    static bool mouseInRect = false;
    static vector<Rect*> rects;
    static Rect* rcCurrent;

    static int posX = 0;
    static int posY = 0;
    static HPEN pen, pen1;
    

    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, 0, 10, NULL);
        mousePoint = MouseDragArea();

        break;
    case WM_TIMER:


        break;

    case WM_LBUTTONDOWN:
        if (mousePoint.isButtonUpBoth())
        {

              mousePoint.ptStart.x = mousePoint.ptEnd.x = LOWORD(lParam);
             mousePoint.ptStart.y = mousePoint.ptEnd.y = HIWORD(lParam);
            rcCurrent = new Rect(mousePoint);
            mousePoint.mouseDownLeft = true;

            InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_MOUSEMOVE:
        mousePoint.ptEnd.x = LOWORD(lParam);
        mousePoint.ptEnd.y = HIWORD(lParam);
        if (mousePoint.mouseDownLeft)
        {
            rcCurrent->CreatingRect(mousePoint);
        }
        else if (mousePoint.mouseDownRight)
        {
            if (rcCurrent!= nullptr)
            {
                rcCurrent->TranslateTo(mousePoint);
            }
           
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_LBUTTONUP:
        if (mousePoint.mouseDownLeft)
        {
            mousePoint.mouseDownLeft = false;
            rcCurrent->CreatedRect(mousePoint);
            rects.push_back(rcCurrent);
            InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_RBUTTONDOWN:

        if (mousePoint.isButtonUpBoth())
        {
            for (size_t i = 0; i < rects.size(); i++)
            {
                if (PtInRect(rects[i]->rect, mousePoint.ptEnd))
                {
                    rcCurrent = rects[i];
                    int lastIndex = rects.size() - 1;
                    if (i != lastIndex)
                    {
                        auto temp = rects[lastIndex];
                        rects[lastIndex] = rects[i];
                        rects[i] = temp;

                    }
                    rcCurrent->TranslateBegin(mousePoint);
                    InvalidateRect(hWnd, NULL, true);
                    break;
                }
            }
            mousePoint.mouseDownRight = true;
            InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_RBUTTONUP:
        if (mousePoint.mouseDownRight)
        {
            rcCurrent = nullptr;
            mousePoint.mouseDownRight = false;

            InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //pen = CreateSolidBrush((RGB(0, 200, 0)));

            for (size_t i = 0; i < rects.size(); i++)
            {

                Rectangle(hdc, rects[i]->rect->left, rects[i]->rect->top, rects[i]->rect->right, rects[i]->rect->bottom);
                if (rects[i]->rect->left <= mousePoint.ptEnd.x && mousePoint.ptEnd.x <= rects[i]->rect->right
                    && rects[i]->rect->top <= mousePoint.ptEnd.y && mousePoint.ptEnd.y <= rects[i]->rect->bottom)
                {

                    wsprintf(strMouse, TEXT("안에 있다 상자 : %d"), i + 1);
                    TextOut(hdc, (rects[i]->rect->left + rects[i]->rect->right) *0.5,
                        (rects[i]->rect->top + rects[i]->rect->bottom) * 0.5, strMouse, lstrlen(strMouse));
                }
            }

            Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

            if (mousePoint.mouseDownLeft)
            {
                Rectangle(hdc, rcCurrent->rect->left, rcCurrent->rect->top, rcCurrent->rect->right, rcCurrent->rect->bottom);
            }
  
            if (rcCurrent !=nullptr)
            {
                wsprintf(strMouse, TEXT("Previous x : %d y: %d"), rcCurrent->previousPos.x, rcCurrent->previousPos.y);
                TextOut(hdc, 600, 30, strMouse, lstrlen(strMouse));

                wsprintf(strMouse, TEXT("x : %d y: %d"), rcCurrent->x, rcCurrent->y);
                TextOut(hdc, 600, 60, strMouse, lstrlen(strMouse));

            }
      
            wsprintf(strMouse, TEXT("mouse x : %d y: %d"), mousePoint.ptStart.x, mousePoint.ptStart.y);
            TextOut(hdc, 600, 90, strMouse, lstrlen(strMouse));


          
            if (rc.left <= mousePoint.ptEnd.x && mousePoint.ptEnd.x <= rc.right
                && rc.top <= mousePoint.ptEnd.y && mousePoint.ptEnd.y <= rc.bottom)
            {
                wsprintf(strMouse, TEXT("안에 있다 상자"));
                TextOut(hdc, 500, 100, strMouse, lstrlen(strMouse));
            }
            //wsprintf(strMouse, TEXT("x : %d y: %d"), tagArea.ptEnd.x, tagArea.ptEnd.y);
            //TextOut(hdc, 600, 60, strMouse, lstrlen(strMouse));
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
        
    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_RIGHT:
    
           
            break;
        case VK_LEFT:
            
            break;
        case VK_RETURN:
            for (size_t i = 0; i < rects.size(); i++)
            {
                delete rects[i];
            }
            rects.clear();
            break;
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
