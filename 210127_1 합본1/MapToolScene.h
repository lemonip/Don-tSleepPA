#pragma once
#include "gameNode.h"
#include "MapManager.h"
#include "Scene.h"

class MapToolScene : public Scene
{
private:
	MapManager* _mapM;
	float _zoom;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void AddUI();
};

