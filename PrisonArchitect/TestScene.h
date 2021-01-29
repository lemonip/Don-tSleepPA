#pragma once
#include "gameNode.h"
#include "Prisoner.h"
#include "Staff.h"
#include "People.h"
#include "Scene.h"
class TestScene : public Scene
{
	vector<Character*> _vCharacter;
	vector<Staff*> _vStaff;
	vector<People*> _vPeople;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


