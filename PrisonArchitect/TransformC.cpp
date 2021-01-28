#include "stdafx.h"
#include "TransformC.h"

void TransformC::SetPosition(Vector2 pos)
{
	_pos = pos;
}

void TransformC::Translate(Vector2 delta)
{
	//자식 이동
	for (GameObject* c : _object->GetvChild())
		c->GetTransform()->Translate(delta);

	//본인 이동
	SetPosition(_pos + delta);

	if (delta.x < 0)	SetDirection(DIRECTION::LEFT);
	if (delta.x > 0)	SetDirection(DIRECTION::RIGHT);
	if (delta.y < 0)	SetDirection(DIRECTION::BACK);
	if (delta.y > 0)	SetDirection(DIRECTION::FRONT);
}

void TransformC::Init()
{

}

void TransformC::Update()
{

}
