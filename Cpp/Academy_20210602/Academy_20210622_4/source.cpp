#include <Windows.h>





// �ü��
HINSTANCE m_hInstance;

// ������ �ڵ鷯
HWND m_hWnd; 

// �»���� Ÿ��Ʋ �ؽ�Ʈ
LPTSTR m_lpszClass = TEXT("���ȴ� ����"); 

// �ݹ��Լ�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpszCmdParam, int nCmdShow)
{
    m_hInstance = hInstance;

    //������â�� ������ �����ϴ� Ŭ����
    WNDCLASS wndClass;

    //�����쿡�� ����ϴ� �����ʹ����� ����Ʈ�� ����
    wndClass.cbClsExtra = 0;

    //�����޸𸮿��� ����ϴ� ������ �޸�
    wndClass.cbWndExtra = 0;

    //������ �۾������� ĥ�� ��� �귯��
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

     //Ŀ�� ����
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

    //Ÿ��Ʋ���� �»�� ������, �ּ�ȭ ������
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

    // �������α׷��� �ν��Ͻ� �ڵ鷯
    wndClass.lpfnWndProc = (WNDPROC)WndProc;

    // �޼��� ó���ϴ� �Լ�
    wndClass.lpfnWndProc = (WNDPROC)WndProc;

    //����ϰ����ϴ� �����콺 �̸�
    wndClass.lpszClassName = m_lpszClass;

    //������ Ŭ���� ����
    wndClass.lpszMenuName = NULL;

    // ������ ��Ÿ�� ����
    wndClass.style = CS_HREDRAW | CS_VREDRAW;

    // ������ Ŭ���� ����
    RegisterClass(&wndClass);


   

    m_hWnd = CreateWindow(
        m_lpszClass,
        m_lpszClass,
        WS_OVERLAPPEDWINDOW,
        //������ ��ǥ x
        100,

        //������ ��ǥ y
        100,

        //x ũ��
        1024, 
        
        //y ũ��
        768,
        NULL,

        (HMENU)NULL,

        hInstance,

        NULL);

    //�����츦 ������
    ShowWindow(m_hWnd, nCmdShow);

    //�ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
    MSG message;

    //������
    while (GetMessage(&message, 0,0,0))
    {
        //Ű���� �Է��� ó�� ���
        TranslateMessage(&message);

        //������ ���ν����� ���޵� �޼����� ���� �����쿡 ����
        DispatchMessage(&message);
        return message.wParam;
    }

    return message.wParam;
}




//wndProc �ൿ
LRESULT CALLBACK WndProc(HWND m_hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {

    //GDI ȭ����°� �׷��� ���
    //HDC ��¿� �ʿ��� ������ ������ ����ü (��ǥ, ���� ,�÷� ��)
    HDC hdc;

    //������ Ŭ���̾�Ʈ ������ �׸��� ���� ����ü
    PAINTSTRUCT ps;




    static BOOL ELLIPSE = FALSE;
    static HWND b2, c1;
    static BOOL MYSELLECT = FALSE;


    switch (iMessage)
    {
        //�����찡 ����ɋ� ���ѹ� ȣ��
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
    //���콺 ���� ��ư Ŭ����
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
    //�׸� �׸��°� (�۾������� �սǉ����� �����
    case WM_PAINT:
    {
        //�׸������
        hdc = BeginPaint(m_hWnd, &ps);

        for (size_t i =200; i < 600; i++)
        {
            for (size_t y = 200; y < 600; y++)
            {
                SetPixel(hdc, i, y, RGB(255, 0, 255));
            }
         
        }



        //�׸��� ��
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




        ////const WCHAR szPlayer1[] = L"�ݵ�����";

        //TextOutW(hdc, 16, 16, num_charX, ARRAYSIZE(num_charX));
        //// TODO: Add any drawing code that uses hdc here...
        //EndPaint(hWnd, &ps);
    }
    break;
    //������ �ı�
    case WM_DESTROY:
  
        //��������
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

//����� ������ Ŭ������ ����