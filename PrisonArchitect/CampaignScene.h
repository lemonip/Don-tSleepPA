#pragma once
#include "Scene.h"
#include "People.h"

class CampaignScene : public Scene
{
	vector<People*> _vPeople;
private:
	Image* _d;
	GameObject* _f;
	Vector2 _cameraPos;
	float _cameraZoom;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

