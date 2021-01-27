#pragma once
#include "TileMap.h"
#include "TilePalette.h"

class MapManager
{
private:
	TileMap* _tileMap;
	TilePalette* _paletteMap;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

