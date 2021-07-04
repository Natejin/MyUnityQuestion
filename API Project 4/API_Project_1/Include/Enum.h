#pragma once

enum class LAYER {
	BACKGROUND,
	DEFAULT,
	UI
};

enum class TAG {
	NONE,
	DEFAULT,


//����
	Unit,
	Player,
	Enemy,
	NPC,

//����ü
	Projectile,


//���
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
	LOAD_RESOURCE = 0,	//���ҽ� �ε�
	LOAD_FILE,			//���Ϸε�
	LOAD_EMPTY,
	LOAD_END
};