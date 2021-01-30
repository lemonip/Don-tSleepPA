#pragma once
#include "TileMap.h"

class MapManager
{
private:
	TileMap* _tileMap;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	TileMap* GetTileMap() { return _tileMap; }

};

