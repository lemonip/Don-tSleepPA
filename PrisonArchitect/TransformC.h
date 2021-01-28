#pragma once
#include "Component.h"
class TransformC : public Component
{
private:
	Vector2 _pos;		//위치
	float _rotation;	//회전
	int _depth;			//렌더 순서

public:
	TransformC() {};
	~TransformC() {};

	//게터
	Vector2 GetPosition() { return _pos; }
	int GetDepth() { return _depth; }
	//세터
	void SetDepth(int depth) { _depth = depth; }
	void SetPosition(Vector2 pos) { _pos = pos; }

	//함수
	virtual void Init();
	virtual void Update();
};

