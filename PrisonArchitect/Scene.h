#pragma once
#include "gameNode.h"
#include "Prisoner.h"
#include "Mouse.h"

class Scene : public gameNode
{

protected:
	Mouse* _mouse;
	float _zoom;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

