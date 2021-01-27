#pragma once
#define TILESIZE 64


enum class AREATYPE
{
	NONE,			//없음

	JAIL,			//감옥
	KITCHEN,		//부엌
	FOODCOURT,		//식당
	SHOWERROOM,		//샤워실
	STORAGE,		//창고
	DUMP,			//쓰레기장
	FIELD,			//운동장
	MEDICAL,		//의무실
};

enum class MOUSESTATE
{
	NONE,		//없음
	SELECT,		//선택
	BUILD,		//설치
};

enum class MOUSEDRAG
{
	NONE,		//없음
	POINT,		//점
	LINE,		//선
	RECT,		//렉트
};

enum class OBJECTTYPE
{
	NONE,		//없음
	TERRAIN,	//지형
	WALL,		//벽
	OBJECT,		//물건
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
};

enum class TILEWALL
{
	WALL0,
	WALL1,
	WALL2,
	WALL3,
};

enum class TILEOBJECT
{
	가스레인지,
	배식대,
	벤치,
	변기,
	사무실책상,
};