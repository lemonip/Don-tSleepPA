#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
private:
	Image* _logoImg;
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

