#pragma once
#include "Character.h"

class Warder : public Character
{
public:
	Warder(int num);
	~Warder() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

