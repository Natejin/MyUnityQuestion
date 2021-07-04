#pragma once
enum class TAG {
	NONE,
	DEFAULT,

//¿Ø¥÷
	Unit,
	Player,
	Enemy,
	NPC,

//≈ıªÁ√º
	Projectile,

	UI
};

enum SCENE_CREATE {

	SCENE_CURRENT,
	SCENE_NEXT
};

enum class COLOR {
	RED

};

enum class MOVE_DIR {
	BACK = -1,
	STAY = 0,
	FRONT = 1

};