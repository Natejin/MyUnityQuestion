#pragma once
#include <iostream>

namespace WallNamPong {
	using namespace std;
	enum class Symbol {
		Heart, Spade,
		clover, Diamond
	};
	static const char* symbolStr[] =
	{ "Heart", "Spade", "clover", "Diamond" };

	class CardData {


	public:
		Symbol symbol;
		int num;
		CardData(int symbol, int num) {
			this->symbol = (Symbol)symbol;
			this->num = num;
		}

		bool operator==(CardData& unit) {
			return num == unit.num ? true : false;
		}

		bool operator!=(CardData& unit) {
			return num != unit.num ? true : false;
		}
		bool operator>=(CardData& unit) {
			return num >= unit.num ? true : false;
		}
		bool operator<=(CardData& unit) {
			return num <= unit.num ? true : false;
		}
		bool operator<(CardData& unit) {
			return num < unit.num ? true : false;
		}
		bool operator>(CardData& unit) {
			return num > unit.num ? true : false;
		}
	};
}