#pragma once
#include "Component.h"
class TransformC : public Component
{
private:
	POINT _pos;			//위치
	POINT _size;		//크기
	float _rotation;	//회전
	int _depth;			//렌더 순서

public:
	TransformC() {};
	~TransformC() {};

	//게터
	POINT GetPosition() { return _pos; }

	//세터
	void SetPosition(POINT pos) { _pos = pos; }

	//함수
	virtual void Init();
	virtual void Update();
};

