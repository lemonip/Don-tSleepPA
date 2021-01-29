#pragma once
#include "Scene.h"
class ScenarioScene : public Scene
{

private:

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

