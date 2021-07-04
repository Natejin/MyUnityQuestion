#pragma once

enum class LAYER {
	BACKGROUND,
	DEFAULT,
	UI
};

enum class TAG {
	NONE,
	DEFAULT,


//유닛
	Unit,
	Player,
	Enemy,
	NPC,

//투사체
	Projectile,


//배경
	Background,
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

enum class IMAGE_LOAD_KIND
{
	LOAD_RESOURCE = 0,	//리소스 로딩
	LOAD_FILE,			//파일로딩
	LOAD_EMPTY,
	LOAD_END
};