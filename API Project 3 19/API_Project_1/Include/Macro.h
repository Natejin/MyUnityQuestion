#pragma once



//==========================================
//				 매크로 설정
//==========================================
#define WINNAME			(LPTSTR)(TEXT("지옥으로 떠나는 여행"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1440
#define WINSIZEY		1080
#define	WINSTYLE		WS_CAPTION | WS_SYSMENU
#define DEFAULT_ANGLE   0.f
#define DEFAULT_SPEED   100


//// define
//#define WINNAME (LPTSTR)(TEXT("APIFrameWork"))
//#define WINSTARTX 25
//#define WINSTARTY 25
//#define WINSIZEX 1024
//#define WINSIZEY 768
//#define WINSTYLE WS_CAPTION | WS_SYSMENU


//==========================================
//			메인게임 릴리즈에서 사용
//==========================================
#define SAFE_DELETE(p) if(p) {delete p ; p= NULL;}
#define SAFE_DELETE_ARRAY(p) if(p) {delete[] p; p= NULL;}
#define SAFE_RELEASE(p) if(p) {p->Release(); p = NULL; }

#define GET_SINGLE(Type) Type::GetSingleton()
#define DESTROY_SINGLE(Type) Type::ReleaseSingleton()

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

#define SAFE_DELETE_VECLIST(T, val)\
	T::iterator iter;\
	T::iterator iterEnd = val.end();\
	for (iter = val.begin(); iter != iterEnd; ++iter){\
		SAFE_DELETE((*iter));\
	}\
	val.clear();\

#define SAFE_RELEASE_VECLIST(T, val)\
	T::iterator iter;\
	T::iterator iterEnd = val.end();\
	for (iter = val.begin(); iter != iterEnd; ++iter){\
		SAFE_RELEASE((*iter));\
	}\
	val.clear();\



