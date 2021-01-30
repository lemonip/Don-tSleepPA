#pragma once
#include "Component.h"

class TransformC : public Component
{
private:
	Vector2 _pos;			//위치

	DIRECTION _direction;	//방향

	Vector2 _size;		//크기
	FloatRect _rc;	//렉트

	Camera* _camera;

	//float _rotation;	//회전
	//int _depth;		//렌더 순서

public:
	TransformC() {};
	~TransformC() {};

	//게터
	Vector2 GetPosition() { return _pos; }
	DIRECTION GetDirection() { return _direction; }

	//세터
	void SetPosition(Vector2 pos);
	void SetDirection(DIRECTION direction) { _direction = direction; }
	void SetSize(Vector2 size) { _size = size; }

	void SetCamera(Camera* camera) { _camera = camera; }

	RECT GetRect();
	FloatRect GetFloatRect() { return _rc; }

	//함수
	virtual void Init();
	virtual void Update();

	void Translate(Vector2 delta);
	void SetRect();

};

