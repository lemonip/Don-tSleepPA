#include "stdafx.h"
#include "MapManager.h"

HRESULT MapManager::init()
{
	TILEMAP->init();
	TILEMAP->SetTileMap(Vector2(50, 30));

	_paletteMap = new TilePalette;
	_paletteMap->init();

	return S_OK;
}

void MapManager::release()
{
	TILEMAP->release();
	delete _tileMap;

	_paletteMap->release();
	delete _paletteMap;
}

void MapManager::update()
{
	TILEMAP->update();

}

void MapManager::render()
{
	TILEMAP->render();

}
