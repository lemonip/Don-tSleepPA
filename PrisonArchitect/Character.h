#pragma once
#include "GameObject.h"
#include "AllComponents.h"

//중점으로부터 위치잡기위한 보정수치
#define HEADOFFSET 10
#define HANDOFFSETY -10
#define HANDOFFSETX 20

//사람기본정보
struct tagCharacterInfo
{
public:
	int frameX[4];		//프레임 번호
	float moveSpeed;	//이동 속도 
	float actSpeed;		//행동 속도
	bool isSleep;		//취침 여부
};

//사람
class Character : public GameObject
{
protected:
	//신체 파츠
	GameObject* _torso;			//몸통
	GameObject* _rightHand;		//오른손
	GameObject* _leftHand;		//왼손

	tagCharacterInfo _info;		//정보

public:
	Character();
	~Character() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//게터
	tagCharacterInfo& GetInfo() { return _info; }
};