#pragma once
#include "UnitStatus.h"
#include "Component.h"
namespace ShopGame {
	class Unit : public Component
	{
	private:
		
	protected:
		UnitStatus* unitStatus;
	public:
		virtual void Initiate() = 0;
		
	};
};



