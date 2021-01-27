#pragma once
#include "Scene.h"
class StartScene : public Scene
{

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

