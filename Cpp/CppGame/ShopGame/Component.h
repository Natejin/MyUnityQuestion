#pragma once
#include "Base.h"

namespace ShopGame {
	class Component
	{
	protected:
		//Ư���� ��Ģ�� ��� �����Ѵ�
		//�� 
		//���� 10000����,
		//������ 20000���� ���
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