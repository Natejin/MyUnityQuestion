// WinAPI_3.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WinAPI_3.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

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
    LoadStringW(hInstance, IDC_WINAPI3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
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
            if (rcCurrent != nullptr)
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
                TextOut(hdc, (rects[i]->rect->left + rects[i]->rect->right) * 0.5,
                    (rects[i]->rect->top + rects[i]->rect->bottom) * 0.5, strMouse, lstrlen(strMouse));
            }
        }

        Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

        if (mousePoint.mouseDownLeft)
        {
            Rectangle(hdc, rcCurrent->rect->left, rcCurrent->rect->top, rcCurrent->rect->right, rcCurrent->rect->bottom);
        }

        if (rcCurrent != nullptr)
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
