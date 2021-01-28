#pragma once
#include "AllEnums.h"
#include "gameNode.h"
#include "GameObject.h"
#include "AllComponents.h"

//중점으로부터 위치잡기위한 보정수치
#define HEADOFFSET 10
#define HANDOFFSETY -10
#define HANDOFFSETX 20

//사람기본정보
struct tagPeopleInfo
{
public:
	int frameX;			 //프레임x
	float moveSpeed;	 //이동속도 
	float actSpeed;		 //행동속도
	bool isSleep;		 //자냐
};

//사람
class People : public GameObject
{
protected:
	//신체 파츠
	GameObject* _torso;
	GameObject* _rightHand;
	GameObject* _leftHand;
	//정보
	tagPeopleInfo _info;

public:
	People();
	~People() {}

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	//방향과 상태에따른 frame번호
	void ChangeFrameX();
	//이동함수(임시)
	void MovePos(float x, float y);
	//게터
	tagPeopleInfo& GetInfo() { return _info; }
};

//직원
class Staff : public People
{
private:
	PEOPLEROLE _role;			//역할

public:
	Staff(PEOPLEROLE role);
	~Staff();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

//죄수
class Prisoner : public People
{
private:
	GameObject* _head;	//신체파츠
public:
	Prisoner(int bodNum, int headNum);
	~Prisoner();
	//몸과 얼굴 종류로 초기화
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


