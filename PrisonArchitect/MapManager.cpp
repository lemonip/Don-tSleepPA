#include "stdafx.h"
#include "MapManager.h"

HRESULT MapManager::init()
{
	TILEMAP->init();
	TILEMAP->SetTileMap(Vector2(100, 100));

	return S_OK;
}

void MapManager::release()
{
	TILEMAP->release();
	delete _tileMap;

}

void MapManager::update()
{
	TILEMAP->update();

}

void MapManager::render()
{
	TILEMAP->render();

}
