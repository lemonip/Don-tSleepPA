#pragma once
#include "Component.h"

class TransformC : public Component
{
private:
	Vector2 _pos;				//위치
	Vector2 _prePos;			//이전 위치

	DIRECTION _direction;	//방향

	//POINT _size;		//크기
	//FloatRect _rc;	//렉트

	//float _rotation;	//회전
	//int _depth;		//렌더 순서

public:
	TransformC() {};
	~TransformC() {};

	//게터
	Vector2 GetPosition() { return _pos; }

	//세터
	void SetPosition(Vector2 pos);
	void SetWorldPosition(Vector2 pos);

	void SetDirection(DIRECTION direction) { _direction = direction; }

	//함수
	virtual void Init();
	virtual void Update();

	void Translate(Vector2 delta);
	void WorldTranslate(Vector2 delta);

};

