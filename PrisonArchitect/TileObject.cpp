#include "stdafx.h"
#include "TileObject.h"


TileObject::TileObject(TILETERRAIN type)
{
	_type = OBJECTTYPE::TERRAIN;
	_count = Vector2(1, 1);
	_terrainType = type;

	switch (type)
	{
	case TILETERRAIN::GRASS1:
		_key = "GRASS1";
		break;
	case TILETERRAIN::GRASS2:
		_key = "GRASS2";
		break;
	case TILETERRAIN::GRASS3:
		_key = "GRASS3";
		break;
	case TILETERRAIN::GROUND:
		_key = "GROUND";
		break;
	case TILETERRAIN::CONCRETE1:
		_key = "CONCRETE1";
		break;
	case TILETERRAIN::CONCRETE2:
		_key = "CONCRETE2";
		break;
	case TILETERRAIN::CONCRETE3:
		_key = "CONCRETE3";
		break;
	case TILETERRAIN::FLOOR:
		_key = "FLOOR";
		break;
	case TILETERRAIN::ROAD:
		_key = "ROAD";
		break;
	case TILETERRAIN::ASPHALT:
		_key = "ASPHALT";
		break;
	case TILETERRAIN::MUD:
		_key = "MUD";
		break;
	case TILETERRAIN::BRICK:
		_key = "BRICK";
		break;
	case TILETERRAIN::ROCK:
		_key = "ROCK";
		break;
	case TILETERRAIN::MOON:
		_key = "MOON";
		break;
	case TILETERRAIN::FLOOR2:
		_key = "FLOOR2";
		break;
	case TILETERRAIN::FLOWER:
		_key = "FLOWER";
		break;
	case TILETERRAIN::CRACK:
		_key = "CRACK";
		break;
	case TILETERRAIN::TILE:
		_key = "TILE";
		break;
	case TILETERRAIN::CARPET:
		_key = "CARPET";
		break;
	case TILETERRAIN::MONO:
		_key = "MONO";
		break;
	case TILETERRAIN::END:
		break;
	default:
		break;
	}
}

TileObject::TileObject(TILEWALL type)
{
	_type = OBJECTTYPE::WALL;
	_count = Vector2(1, 1);
	_wallType = type;

	_key = "wall" + to_string((int)_wallType);
	_img = ImageManager::GetInstance()->FindImage(_key);
	_name = _key;

	switch (type)
	{
		case TILEWALL::WALL0:
			_price = 50;
		break;
		case TILEWALL::WALL1:
			_price = 70;
		break;
		case TILEWALL::WALL2:

		break;
		case TILEWALL::WALL3:

		break;
		default:
		break;
	}
}

TileObject::TileObject(TILEOBJECT type)
{
	_type = OBJECTTYPE::OBJECT;
	_objType = type;
	_direction = DIRECTION::FRONT;

	_frame[0] = 0;		//앞
	_frame[1] = 2;		//왼
	_frame[2] = 1;		//뒤
	_frame[3] = 2;		//오

	switch (type)
	{
	case TILEOBJECT::가스레인지:
		_key = "가스레인지";
		_name = "가스레인지";
		_count = Vector2(2, 1);
		break;
	case TILEOBJECT::배식대:
		_key = "배식대";
		_name = "배식대";
		_count = Vector2(5, 1);
		break;
	case TILEOBJECT::벤치:
		_key = "벤치";
		_name = "벤치";
		_count = Vector2(4, 1);
		break;
	case TILEOBJECT::변기:
		_key = "변기";
		_name = "변기";
		_count = Vector2(1, 1);
		break;
	case TILEOBJECT::사무실책상:
		_key = "사무실책상";
		_name = "사무실 책상";
		_count = Vector2(2, 1);
		break;
	default:
		break;
	}
	_img = ImageManager::GetInstance()->FindImage(_key);

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
