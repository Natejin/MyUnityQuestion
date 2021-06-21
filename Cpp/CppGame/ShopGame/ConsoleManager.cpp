#include "ConsoleManager.h"

namespace ShopGame {
	ConsoleManager::ConsoleManager()
	{
		errorCodeQueue = new queue<ErrorCode>();
		errorCodeQueueStr = new vector<string>();
		errorCodeQueueStr->push_back("NON_ERROR");
		errorCodeQueueStr->push_back("ERROR_Inventory_IsFull");
		errorCodeQueueStr->push_back("ERROR_Inventory_IsMissing");
		errorCodeQueueStr->push_back("ERROR_Inventory_ItemCountMoreThanInventorySize");
		errorCodeQueueStr->push_back("ERROR_Inventory_Unknown");
		errorCodeQueueStr->push_back("ERROR_Inventory_SlotItemIsMissing");
		errorCodeQueueStr->push_back("ERROR_Equipment_ClassDoesNotMatch");
		
	}

	ConsoleManager::~ConsoleManager()
	{
		delete errorCodeQueue;
		delete errorCodeQueueStr;
	}

}
