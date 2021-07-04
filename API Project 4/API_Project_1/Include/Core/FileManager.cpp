#include "FileManager.h"


bool FileManager::Init()
{
	wchar_t strPath[MAX_PATH] = {};

	////���� ����ǰ��ִ� ��� ��������
	////������: ���־� ��Ʃ����� ����׽���� Include������
	////������� �������� ����
	////�����̸��� �ٲ�� �ν��� �����
	//GetCurrentDirectory

	GetModuleFileName(NULL, strPath, MAX_PATH);
	for (size_t i = lstrlenW(strPath)- 1; i >= 0; --i)
	{
		if (strPath[i] == '/' || strPath[i] == '\\')
		{
			memset(strPath + (i + (size_t)1), 0, sizeof(wchar_t)*
				(MAX_PATH-(i+ (size_t)1)));
				break;
		}
	}


	pathMap.insert(make_pair(ROOT_PATH, strPath));

	//Texture ��� ����
	if (!CreatePath(TEXTURE_PATH, L"Texture\\"))
	{
		return false;
	}
	return true;
}

bool FileManager::CreatePath(const string& strKey, const wchar_t* pPath, const string& strBaseKey)
{

	const wchar_t* pBasePath = FindPath(strBaseKey);
	wstring strPath;
	if (pBasePath)
	{
		strPath = pBasePath;
	}
	strPath += pPath;
	pathMap.insert(make_pair(strKey, strPath));

	return true;
}


const wchar_t* FileManager::FindPath(const string& strKey)
{
	unordered_map<string, wstring>::iterator iter = pathMap.find(strKey);
	if (iter == pathMap.end()) 
		return NULL;


	return iter->second.c_str();
}
