#pragma once
#include <iostream>
#include <map>
#include <vector>

using namespace std;

namespace ShopGame {
	class Database
	{
	public:
		virtual void InitiateDatabase() = 0;
	}; 
}
