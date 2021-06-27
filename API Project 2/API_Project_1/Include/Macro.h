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
#define SAFE_DELETE(p) if(p) {delete p ; p= nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p= nullptr;}

#define GET_SINGLE(Type) Type::GetInst()
#define DESTROY_SINGLE(Type) Type::DestroyInst()

#define DECLARE_SINGLE(Type)	\
protected:\
	static Type* pInstance;\
	Type();\
	~Type();\
public:\
	static Type* GetInst(){\
		if (!pInstance)\
			pInstance = new Type;\
		return pInstance;\
	}\
	static void DestroyInst() {\
		if (pInstance)\
		{\
			delete pInstance; \
			pInstance = nullptr; \
		}\
	}

#define DEFINITION_SINGLE(Type) Type* Type::pInst = nullptr:


