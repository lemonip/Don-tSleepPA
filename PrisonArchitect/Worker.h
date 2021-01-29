#pragma once
#include "Character.h"

//¿Œ∫Œ
class Worker : public Character
{
private:

public:
	Worker(int num);
	~Worker(){}

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

