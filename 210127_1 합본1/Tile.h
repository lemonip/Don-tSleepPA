#pragma once

#include "TileObject.h"
#include "TileArea.h"

class Tile
{
public:
	Vector2 _index;				//인덱스
	RECT _rc;					//렉트

	TileObject* _terrain;		//지형
	
	TileObject* _wall;			//벽
	int			_wallIndex;		//벽 인덱스

	TileObject* _tileObj;		//타일 오브젝트
	
	TileArea* _tileArea;		//타일 구역

public:
	void SetIndex(Vector2 index) { _index = index; }

	Vector2 GetIndex() { return _index; }


};

