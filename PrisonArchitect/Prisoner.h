#pragma once
#include "Character.h"

//ÁË¼ö
class Prisoner : public Character
{
private:
	GameObject* _head;	//½ÅÃ¼ÆÄÃ÷
	int _bodNum;		//¸öÅë¹øÈ£
public:
	Prisoner(int bodNum, int headNum);
	~Prisoner();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//ÂøÀÇ ¿©ºÎ ¼¼ÆÃ
	void SetIsNaked(bool isNaked);
};


