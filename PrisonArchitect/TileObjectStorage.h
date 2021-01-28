#pragma once
class TileObjectStorage
{

public:
	static TileObjectStorage* GetInstance()
	{
		static TileObjectStorage istance;
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
	void SetStorage();				//창고 세팅

	//GETTER
	mTileObject* GetMTileObject() { return &_mTileObject; }
	TileObject* FindTileObject(string key);
};

