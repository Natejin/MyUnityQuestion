#pragma once






// ���� ���� ��ũ��
#define MAKE_NO_COPY(CLASSNAME)                                  \
        private:                                                 \
            CLASSNAME(const CLASSNAME&);                         \
            CLASSNAME& operator=(const CLASSNAME&);



// ��Ŭ�� ���� ���� ��ũ��
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

