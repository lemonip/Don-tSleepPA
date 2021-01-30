#pragma once
#include "Character.h"

//ÁË¼ö
class Prisoner : public Character
{
private:
	GameObject* _head;	//½ÅÃ¼ÆÄÃ÷

public:
	Prisoner(int bodNum, int headNum);
	~Prisoner();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


