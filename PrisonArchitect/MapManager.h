#pragma once
#include "TileMap.h"
#include "TileObjectStorage.h"

class MapManager
{
private:
	TileMap* _tileMap;
	TileObjectStorage* _tileObjectStorage;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

