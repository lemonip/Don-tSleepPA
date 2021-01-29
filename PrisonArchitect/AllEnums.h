#pragma once
#define TILESIZE 64

//지역
enum class AREATYPE
{
	JAIL,			//감옥
	KITCHEN,		//부엌
	FOODCOURT,		//식당
	SHOWERROOM,		//샤워실
	STORAGE,		//창고
	DUMP,			//쓰레기장
	FIELD,			//운동장
	MEDICAL,		//의무실

	END,			//없음
};

//마우스 상태
enum class MOUSESTATE
{
	ONUI,			//UI 위
	NONE,		//없음

};

//마우스 드래그
enum class MOUSEDRAG
{
	POINT,		//점
	LINE,		//선
	RECT,		//렉트
	END,		//없음
};

//오브젝트 타입
enum class OBJECTTYPE
{
	TERRAIN,	//지형
	WALL,		//벽
	OBJECT,		//물건
	END,		//없음
};

enum class OBJECTSTATE
{
	COMPLETION,
	BUILD,
};

enum class DIRECTION
{
	FRONT,		//앞
	LEFT,		//왼
	BACK,		//뒤
	RIGHT,		//오
};

enum class TILETERRAIN
{
	GRASS1,
	GRASS2,
	GRASS3,
	GROUND,
	CONCRETE1,
	CONCRETE2,
	CONCRETE3,
	FLOOR,
	ROAD,
	ASPHALT,
	MUD,
	BRICK,
	ROCK,
	MOON,
	FLOOR2,
	FLOWER,
	CRACK,
	TILE,
	CARPET,
	MONO,
	END,
};

enum class TILEWALL
{
	WALL0,	 WALL1, WALL2,	WALL3,	WALL4,
	WALL5,	WALL6,	WALL7,	WALL8,	WALL9,
	WALL10, WALL11, WALL12, WALL13, WALL14,
	WALL15, WALL16, WALL17, WALL18, WALL19,
	WALL20, WALL21, WALL22, WALL23, WALL24,
	WALL25, WALL26, WALL27, WALL28, WALL29,
	END,
};

enum class TILEOBJECT
{
	가스레인지,
	배식대,
	벤치,
	변기,
	사무실책상,
	END,
};

//스탭 역할
enum class STAFFROLE
{
	ACCOUNTANT,
	CLEANER,
	COOKER,
	DOCTER,
	END,
};

enum class PEOPLEROLE
{
	BITALIA,
	BOSS,
	NICO,
	END,
};