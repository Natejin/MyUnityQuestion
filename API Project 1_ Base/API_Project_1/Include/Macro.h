#pragma once



//==========================================
//				 ��ũ�� ����
//==========================================
#define WINNAME			(LPTSTR)(TEXT("�������� ������ ����"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1440
#define WINSIZEY		1080
#define	WINSTYLE		WS_CAPTION | WS_SYSMENU


//==========================================
//			���ΰ��� ������� ���
//==========================================
#define SAFE_DELETE(p) if(p) {delete p ; p= NULL;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p= NULL;}
//Singleton patten
