#include "stdafx.h"
#include "MapManager.h"

HRESULT MapManager::init()
{
	//타일 오브젝트 저장고에 만들어 준다.
	DATAMANAGER->init();

	//타일 맵을 세팅한다.
	_tileMap = new TileMap;
	_tileMap->init();
	_tileMap->SetTileMap(Vector2(100, 50));

	//마우스에 타일맵을 연결해준다.
	MOUSECONTROL->LinkTileMap(_tileMap);
	MOUSECONTROL->Init();

	return S_OK;
}

void MapManager::release()
{
	_tileMap->release();

	delete _tileMap;

}

void MapManager::update()
{
	_tileMap->update();
	MouseControl::GetInstance()->Update();

}

void MapManager::render()
{
	_tileMap->render();
	MouseControl::GetInstance()->Render();

}
