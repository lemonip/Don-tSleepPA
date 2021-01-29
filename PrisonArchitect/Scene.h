#pragma once
#include "gameNode.h"
#include "Prisoner.h"

class Scene : public gameNode
{

protected:
	bool willRelease;


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

