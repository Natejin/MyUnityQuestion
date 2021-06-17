#pragma once
namespace ShopGame {
	class Object
	{
		int code;
	public:
		Object() :code(-1) {};
		~Object() {};
		Object(const int& code) { this->code = code; };
		int GetCode() { return code; }
	};

}