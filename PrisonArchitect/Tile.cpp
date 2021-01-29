#include "stdafx.h"
#include "Tile.h"

TileObject * Tile::MouseEnter()
{
	cout << "타일을 선택했다" << endl;
	if(_tileObj)		return _tileObj;
	else if(_wall)		return _wall;

	cout << "아무것도 없음" << endl;
	return NULL;
}

TileObject * Tile::MouseStay()
{
	return NULL;
}

TileObject * Tile::MouseExit()
{
	cout << "타일을 놓아줬다!" << endl;

	return NULL;
}
