#pragma once
#include "Scene.h"
#include "People.h"

class CampaignScene : public Scene
{
	vector<People*> _vPeople;
private:

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

