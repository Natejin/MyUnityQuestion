// WinAPI32.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WinAPI32.h"
#include <windowsx.h>
#include <iostream>

using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HBRUSH hbr1, hbr2;
HICON hIcon1, hIcon2;

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI32, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI32));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI32));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPI32);
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
   hInst = hInstance; // Store instance handle in our global variable

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
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;

    static BOOL ELLIPSE = FALSE;
    static HWND b2, c1;
    static BOOL MYSELLECT = FALSE;
    PAINTSTRUCT ps;

    switch (message)
    {
    case WM_CREATE:
    {
        hbr1 = CreateSolidBrush(RGB(255, 0, 0));
        hbr2 = CreateSolidBrush(RGB(0, 0, 255));

        // load player icons
        hIcon1 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_CROSS));
        hIcon2 = LoadIcon(hInst, MAKEINTRESOURCE(IDI_CIRCLE));

        CreateWindow(TEXT("button"), TEXT("Click Me"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            20, 20, 100, 25, hWnd, (HMENU)0, hInst, NULL);
        b2 = CreateWindow(TEXT("button"), TEXT("TextOut"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            20, 50, 100, 25, hWnd, (HMENU)1, hInst, NULL);
    }
    break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_LBUTTONDOWN: 
    {
        int xPos = GET_X_LPARAM(lParam);
        int yPos = GET_Y_LPARAM(lParam);

        int ret = MessageBox(hWnd, L"Are you sure u want to start a new game?", L"New Game", MB_YESNO | MB_ICONQUESTION);
        if (IDYES == ret)
        {
            //// reset and start new game
            //playerTurn = 1;
            //winner = 0;
            //ZeroMemory(gameBoard, sizeof(gameBoard));

            //// force a paint message
            //InvalidateRect(hWnd, NULL, TRUE);	// post WM_PAINT to our WindowsProc. it gets queued in our msg queue
            //UpdateWindow(hWnd);					// forces immediate handling of WM_PAINT
        }
    }
        
        break;
    case WM_PAINT:
        {
        int xPos = GET_X_LPARAM(lParam);
        int yPos = GET_Y_LPARAM(lParam);
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        //int myIntValue = 20;
        wchar_t num_charX[10];

        swprintf_s(num_charX, L"%d", xPos);


        //wstring name(L"Steve Nash");
        //const wchar_t* szName = name.c_str();




        //const WCHAR szPlayer1[] = L"반동분자";

        TextOutW(hdc, 16, 16, num_charX, ARRAYSIZE(num_charX));
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        DeleteObject(hbr1);
        DeleteObject(hbr2);

        DestroyIcon(hIcon1);
        DestroyIcon(hIcon2);


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
