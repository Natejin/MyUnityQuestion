#include "GameManager.h"

int main() {
	srand((int)time(NULL));
	GameManager* gm = new GameManager();
	gm->GameStart();
}