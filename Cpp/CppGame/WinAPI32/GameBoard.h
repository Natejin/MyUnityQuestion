#include <vector>
#include "Position.h"

using namespace std;

enum class MAPDATA
{
	EMPTY,
	SNAKE,
	WALL,
	FOOD
};

class GameBoard
{
private:
	vector<Position> snake;
	int frameTime;
	MAPDATA map[20][20];
	//State NextBehavior(int newPosX, int newPosY);
	//string text = "방향키를 입력하세요";
	bool hasFood;
	int currentSize;
	int currentLevel;
	vector<int> nextSize = { 4,5,6,8,10,12,15,18,21,25,29,34,39,44,50,56,62 };
	vector<int> nextSpeed = { 100,90,80,70,60,50,45,40,35,30,25,20,15,10 };


};