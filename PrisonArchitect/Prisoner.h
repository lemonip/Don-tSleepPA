#pragma once
#include "AllEnums.h"
#include "gameNode.h"
#include "GameObject.h"
#include "AllComponents.h"

#define headOffset 10
#define handOffsetY -10
#define handOffsetX 20

//죄수정보
struct tagConvictInfo 
{
public:
	DIRECTION dest;		//방향
	int frameX;			 //프레임x
	float moveSpeed;	 //이동속도 (두 속도는 게임속도라는 전체속도에 연산하여 결정되야할듯!)
	float actSpeed;		 //행동속도
	bool isSleep;		 //자냐

	GameObject* head;
	GameObject* torso;
	GameObject* rightHand;
	GameObject* leftHand;
};

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

