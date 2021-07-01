#pragma once

//==========================================
//				 매크로 설정
//==========================================
#define WINNAME			(LPTSTR)(TEXT("카드뒤집기"))
#define WINSTARTX		100
#define WINSTARTY		100
#define WINSIZEX		1024
#define WINSIZEY		768
#define	WINSTYLE		WS_CAPTION | WS_SYSMENU



#define SAFE_DELETE(p) {if(p) {delete p; (p)=NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->Release(); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[] (p); (p)=NULL;}}


// 복사 금지 매크로
#define MAKE_NO_COPY(CLASSNAME)                                  \
        private:                                                 \
            CLASSNAME(const CLASSNAME&);                         \
            CLASSNAME& operator=(const CLASSNAME&);



// 싱클톤 패턴 생성 매크로
#define DECLARE_SINGLETONE(CLASSNAME)                            \
MAKE_NO_COPY(CLASSNAME)                                          \
        private:                                                 \
    CLASSNAME() {}                                               \
    static CLASSNAME* Instance;                                  \
        public:                                                  \
    static CLASSNAME& GetInstance();

#define IMPLEMENT_SINGLETON(CLASSNAME)                          \
CLASSNAME* CLASSNAME::Instance = 0;                             \
CLASSNAME& CLASSNAME::GetInstance() {                           \
        if (Instance == 0)                                      \
            Instance = new CLASSNAME;                           \
            return *Instance;                                   \
}

