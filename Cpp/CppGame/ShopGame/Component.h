#pragma once
#include "Base.h"

namespace ShopGame {
	class Component
	{
	protected:
		//특수한 규칙을 지어서 구별한다
		//예 
		//유닛 10000번대,
		//아이템 20000번대 등등
		unsigned int code;
		string name;
		string description;
	public:
		Component() :code(0), name(NullString), description(NullString) {};
		Component(const unsigned int& code, const string& name, const string& description):code(code), name(name), description(description){}
		unsigned int GetCode() { return code; }
		string GetName() { return name; }
		string GetDescription() { return description; }
	};

}