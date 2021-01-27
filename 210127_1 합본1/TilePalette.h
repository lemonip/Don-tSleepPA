#pragma once
#include "TileObject.h"
class TilePalette
{
private:
	vector<TileObject*> _vTileObj;
	int _size;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SetTileMap(Vector2 count);

};

