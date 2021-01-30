#pragma once
#include "gameNode.h"
#include "Prisoner.h"
#include "Scene.h"
class TestScene : public Scene
{
	vector<Character*> _vCharacter;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


