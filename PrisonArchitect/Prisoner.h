#pragma once
#include "AllEnums.h"
#include "gameNode.h"
#include "GameObject.h"
#include "AllComponents.h"

//중점으로부터 위치잡기위한 보정수치
#define headOffset 10
#define handOffsetY -10
#define handOffsetX 20

//사람기본정보
struct tagPeopleInfo
{
public:
	DIRECTION dest;		 //방향
	int frameX;			 //프레임x
	float moveSpeed;	 //이동속도 
	float actSpeed;		 //행동속도
	bool isSleep;		 //자냐
};

//죄수정보
struct tagConvictInfo : public tagPeopleInfo
{
public:
	//신체파츠
	GameObject* head;
	GameObject* torso;
	GameObject* rightHand;
	GameObject* leftHand;
};

//직원정보
struct tagStaffInfo : public tagPeopleInfo
{
public:
	ROLE role;			//역할
	//신체파츠
	GameObject* torso;	
	GameObject* rightHand;
	GameObject* leftHand;
};


//사람
class Staff : public GameObject
{
private:
	tagStaffInfo _info;
public:
	virtual HRESULT init(ROLE role);
	virtual void release();
	virtual void update();
	virtual void render();
	//============================
	void ChangeFrameX();//클래스를 떼서 만들까 컴포넌트화할까..?
		//이동함수
	void MovePos(float x, float y);

	//\\\\\\\\\\\\\\
	//게터
	tagStaffInfo& GetInfo() { return _info; }


};

//죄수
class Prisoner : public GameObject
{
private:
	tagConvictInfo _info;
public:
	//몸과 얼굴 종류로 초기화
	virtual HRESULT init(int bodNum, int headNum);
	virtual void release();
	virtual void update();
	virtual void render();
	void ChangeFrameX();//방향과 상태에따른 frame번호

	//게터
	tagConvictInfo& GetInfo() { return _info; }

	//이동함수
	void MovePos(float x, float y);
};

