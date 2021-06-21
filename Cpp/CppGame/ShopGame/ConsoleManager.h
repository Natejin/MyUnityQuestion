#pragma once

#include "Manager.h"


namespace ShopGame {
	class GameManager;
	
	class ConsoleManager
	{
	private:
		queue<ErrorCode>* errorCodeQueue;
		vector<string>* errorCodeQueueStr;

	public:
		ConsoleManager();
		~ConsoleManager();

		void ErrorCodePush(ErrorCode errorcode) { errorCodeQueue->push(errorcode); }
		queue<ErrorCode>* GetErrorCodeQueue() { return errorCodeQueue; }


		void PrintAll() {
			while (!errorCodeQueue->empty())
			{
				cout << errorCodeQueueStr->at((int)errorCodeQueue->front()) << endl;
				errorCodeQueue->pop();
			}
		}
	};
}