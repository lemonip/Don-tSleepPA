#include "stdafx.h"
#include "TileObjectStorage.h"

void TileObjectStorage::SetStorage()
{
	_terrainImg = IMAGEMANAGER->FindImage("terrain");

	//지형 추가
	for (int i = 0; i < (int)TILETERRAIN::END; i++)
	{
		TileObject* obj = new TileObject((TILETERRAIN)i);
		obj->_img = _terrainImg;
		_mTileObject.insert(make_pair(obj->_key, obj));
	}

	//벽 추가
	for (int i = 0; i < (int)TILEWALL::END; i++)
	{
		TileObject* obj = new TileObject((TILEWALL)i);
		_mTileObject.insert(make_pair(obj->_key, obj));
	}

	//오브젝트 추가
	for (int i = 0; i < (int)TILEOBJECT::END; i++)
	{
		TileObject* obj = new TileObject((TILEOBJECT)i);
		_mTileObject.insert(make_pair(obj->_key, obj));
	}
}

TileObject * TileObjectStorage::FindTileObject(string key)
{
	//오브젝트 찾기
	miTileObject _miTileObject = _mTileObject.find(key);
	if (_miTileObject != _mTileObject.end()) return _miTileObject->second;

	//벽 찾기
	_miTileObject = _mWall.find(key);
	if (_miTileObject != _mWall.end()) return _miTileObject->second;

	//지형 찾기
	_miTileObject = _mTerrain.find(key);
	if (_miTileObject != _mTerrain.end()) return _miTileObject->second;

	return nullptr;
}
