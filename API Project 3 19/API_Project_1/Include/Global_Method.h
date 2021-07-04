#pragma once
#include "Macro.h"
#include <Windows.h>

using namespace std;

//template <typename T>
//void Safe_Delete_VecList(T& p) {
//	T::iterator iter;
//	T::iterator iterEnd = p.end();
//	for (iter = p.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_DELETE((*iter));
//	}
//	p.clear();
//}
//
//template <typename T>
//void Safe_Release_VecList(T& p) {
//	T::iterator iter;
//	T::iterator iterEnd = p.end();
//	for (iter = p.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_RELEASE((*iter));
//	}
//	p.clear();
//}
//
//template <typename T>
//void Safe_Release_map(T& p) {
//	T::iterator iter;
//	T::iterator iterEnd = p.end();
//	for (iter = p.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_RELEASE(iter->second);
//	}
//	p.clear();
//}
//
//template <typename T>
//void Safe_Delete_map(T& p) {
//	T::iterator iter;
//	T::iterator iterEnd = p.end();
//	for (iter = p.begin(); iter != iterEnd; ++iter)
//	{
//		SAFE_DELETE(iter->second);
//	}
//	p.clear();
//}