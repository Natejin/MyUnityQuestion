// Academy_20210623_1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Academy_20210623_1.h"
#include "commonMacroFunction.h"

#include<Windows.h>


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInstance;                          // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HWND hWnd;
POINT m_ptMouse = { 0,0 };
//LPTSTR m_lpszClass = ("지옥의 사과");
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ACADEMY202106231, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ACADEMY202106231));

    MSG msg;

    // Main message loop:
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


//RECT rc;
//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ACADEMY202106231));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ACADEMY202106231);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//



BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInstance = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindowW(szWindowClass, szTitle,  WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   //hWnd = CreateWindow(WINNAME, WINNAME, WS_OVERLAPPEDWINDOW, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY,  NULL, (HMENU)NULL, hInstance, NULL);
   if (!hWnd)
   {
      return FALSE;
   }
   setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
//const wchar_t* c= TEXT("2");
//char* pc = "sada";


LPCWSTR str = TEXT("집에 보내줘");
LPCWSTR strs[6] = {
   TEXT("\t종류\t원산지\t가격\t설명"),
   TEXT("광어초밥\t초밥\t국내산\t3000원\t맛있다"),
   TEXT("연어초밥\t초밥\t국내산\t3000원\t부드럽다"),
   TEXT("김치롤 \t롤\t국내산\t2500원\t배부르다"),
   TEXT("유부초밥\t초밥\t국내산\t1500원\t별로다"),
};
 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static RECT rc = RectMake(0, 0, 100, 100);
    static HDC hdc;
    static int speed = 5;
    static int index = 2;
    static bool drawText = false;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            WCHAR szTitle1[MAX_LOADSTRING];
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

            RECT rc1 = RectMakeCenter(100, 100, 100, 100);
            Rectangle(hdc, rc1.left, rc1.top, rc1.right, rc1.bottom);

            RECT rc2 = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 300, 100);
            Rectangle(hdc, rc2.left, rc2.top, rc2.right, rc2.bottom);
            ElllipseMakeCenter(hdc, WINSIZEX / 2, WINSIZEY / 2, 200, 200);

            for (size_t i = 0; i < 100; i++)
            {
                for (size_t j = 0; j < 100; j++)
                {
                    SetPixel(hdc, i, j, RGB(255, 0, 255));
                }
            }

            LineMake(hdc, 300,300,500,500);

            wsprintf(szTitle1, TEXT("오른쪽 마우스 버튼을 클릭시 다음단으로 넘어갑니다."));
            TextOut(hdc, 500, 100, szTitle1, lstrlen(szTitle1));
            wsprintf(szTitle1, TEXT("왼쪽 마우스 버튼을 클릭시 이전단으로 넘어갑니다."));
            TextOut(hdc, 500, 150, szTitle1, lstrlen(szTitle1));
            wsprintf(szTitle1, TEXT("엔터를 누르면 구구단이 보이거나 감출수 있습니다."));
            TextOut(hdc, 500, 200, szTitle1, lstrlen(szTitle1));
            if (drawText)
            {
                /*LPCWSTR str_grade = TEXT("wow");*/
                //LPCSTR str = WCHAR[strlen(str_grade)]
                //LPCTSTR portvalue = new TCHAR[100];
          
                //wchar_t a = L"Hello, world!";
                //sprintf_s(str,)
                //isprint(str_grade, "%d 단", i + 1);
                for (size_t i = 1; i < 10; i++)
                {
                    wsprintf(szTitle1, TEXT("%d * %d = %d"), index, i, index * i);
                    TextOut(hdc, 100, 100 + i* 20, szTitle1, lstrlen(szTitle1));
                }
            }
     
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_LBUTTONDOWN:

        //hdc = GetDC(hWnd);

        //SetTextColor(hdc, RGB(0, 0, 255));
  
        //TextOut(hdc, 100, 100, strs[index], lstrlen(strs[index]));
        //
        //ReleaseDC(hWnd, hdc);

        drawText = true;
        if (index < 9)
        {
            index++;
        }
     
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_RBUTTONDOWN:

        //hdc = GetDC(hWnd);

        //SetTextColor(hdc, RGB(0, 0, 255));

        //TextOut(hdc, 100, 100, TEXT("집에 보내줘"), lstrlen(strs[index]));

        //ReleaseDC(hWnd, hdc);
        drawText = true;
        if (index > 2)
        {
         
            index--;
        }
    
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_RETURN:
            drawText = false;
            break;
        case VK_RIGHT:
            rc.left += speed;
            rc.right += speed;
            break;
        case VK_LEFT:
            rc.left -= speed;
            rc.right -= speed;
            break;
        case VK_DOWN:
            rc.bottom += speed;
            rc.top += speed;
            break;
        case VK_UP:
            rc.bottom -= speed;
            rc.top -= speed;
            break;
        default:
            break;
        }
        //InvalidateRect 변경된부분만 지우고 다시 그려줌
        //HWND 갱신되어야할 윈도우를 넣음 (NULL일경우 윈도우 전체를 인식함)
        //Null 넣어줌
        //true를 넣어주면 paint를 호출할떄 무효화영역을 지우고하고
        //false일경우 무효화 영역은 그대로 놔둔채 한다.
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

// Message handler for about box.
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

//윈도우 크기 조정
//클라이언트 영역 사이즈 잡는곳.
void setWindowSize(int x, int y, int width, int height)
{
    RECT rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = width;
    rc.bottom = height;

    //위 RECT정보로 윈도우 사이즈 셋팅
    SetWindowPos(hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}