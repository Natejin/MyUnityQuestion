#include "GameManager.h"

namespace WallNamPong {


	int main() {
		srand((int)time(NULL));
		GameManager* gm = new GameManager();
		gm->GameStart();
	}
}