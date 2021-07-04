#pragma once
#include "../Game.h"
#include "Singleton.h"
class FileManager : public Singleton<FileManager>
{

	//FileManager();
public:
	bool Init();
	bool CreatePath(const string& strKey,
		const wchar_t* pPath,
		const string& strBaseKey = ROOT_PATH);

	const wchar_t* FindPath(const string& strKey);
private:
	unordered_map<string, wstring> pathMap;
};

