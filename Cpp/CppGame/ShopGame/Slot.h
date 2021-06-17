#pragma once

namespace ShopGame {

	class Slot
	{
	private:
		int index;
		bool isEmpty;
	public:
		Slot() :index(-1), isEmpty(true) {};
		~Slot() {};
		Slot(int index) : index(index) { isEmpty = true; }
		bool CheckEmpty() { return isEmpty; }
	};

}