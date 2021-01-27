#include "stdafx.h"
#include "TileObject.h"


TileObject::TileObject(TILETERRAIN type)
{
	_type = OBJECTTYPE::TERRAIN;
	_count = Vector2(1, 1);

	_terrainType = type;
}

TileObject::TileObject(TILEWALL type)
{
	_type = OBJECTTYPE::WALL;

	_count = Vector2(1, 1);
	_wallType = type;
	
	switch (type)
	{
		case TILEWALL::WALL0:
			_img = ImageManager::GetInstance()->FindImage("wall0");
		break;
		case TILEWALL::WALL1:
			_img = ImageManager::GetInstance()->FindImage("wall1");
		break;
		case TILEWALL::WALL2:
			_img = ImageManager::GetInstance()->FindImage("wall2");
		break;
		case TILEWALL::WALL3:
			_img = ImageManager::GetInstance()->FindImage("wall3");
		break;
		default:
		break;
	}
}

TileObject::TileObject(TILEOBJECT type, DIRECTION direction = DIRECTION::FRONT)
{
	_type = OBJECTTYPE::OBJECT;
	_objType = type;
	_direction = direction;

	_frame[0] = 0;		//앞
	_frame[1] = 2;		//왼
	_frame[2] = 1;		//뒤
	_frame[3] = 2;		//오

	switch (type)
	{
	case TILEOBJECT::가스레인지:
		_img = ImageManager::GetInstance()->FindImage("가스레인지");
		_count = Vector2(2, 1);
		break;
	case TILEOBJECT::배식대:
		_img = ImageManager::GetInstance()->FindImage("배식대");
		_count = Vector2(5, 1);
		break;
	case TILEOBJECT::벤치:
		_img = ImageManager::GetInstance()->FindImage("벤치");
		_count = Vector2(4, 1);
		break;
	case TILEOBJECT::변기:
		_img = ImageManager::GetInstance()->FindImage("변기");
		_count = Vector2(1, 1);
		break;
	case TILEOBJECT::사무실책상:
		_img = ImageManager::GetInstance()->FindImage("사무실책상");
		_count = Vector2(2, 1);
		break;
	default:
		break;
	}
}

HRESULT TileObject::init()
{
	return S_OK;
}

void TileObject::release()
{
}

void TileObject::update()
{
}

void TileObject::render()
{
}
