#pragma once
#define N 4
class Algoritsm
{
private:
	int FindXPosition(int puzzle[N][N]);
	int GetInvCount(int arr[]);
public:
	bool IsSolvable(int puzzle[N][N]);
};

