#pragma once

class TileObject;

class DataManager
{

public:
	static DataManager* GetInstance()
	{
		static DataManager istance;
		return &istance;
	}

private:
	typedef map<string, TileObject*> mTileObject;
	typedef map<string, TileObject*>::iterator miTileObject;

	Image* _terrainImg;				//지형 이미지

	mTileObject _mTerrain;			//지형을 담은 맵
	mTileObject _mWall;				//벽을 담은 맵
	mTileObject _mTileObject;		//타일 오브젝트를 담은 맵

public:
	void init();					//초기화

	//GETTER
	mTileObject* GetMTileObject() { return &_mTileObject; }
	TileObject* FindTileObject(string key);
};

