#include "stdafx.h"
#include "TransformC.h"

void TransformC::SetPosition(Vector2 pos)
{
	Vector2 differ;
	differ = _prePos - _pos;

	_pos = pos;

	if (differ.x > 0)	SetDirection(DIRECTION::LEFT);
	if(differ.x < 0)	SetDirection(DIRECTION::RIGHT);
	if (differ.y > 0)	SetDirection(DIRECTION::BACK);
	if (differ.y < 0)	SetDirection(DIRECTION::FRONT);

	_prePos = _pos;
}

void TransformC::SetWorldPosition(Vector2 pos)
{
	GameObject* parent = _object->GetParent();
	Vector2 minusPosition;

	while (parent != nullptr)
	{
		minusPosition.x += parent->GetTransform()->GetPosition().x;
		minusPosition.y += parent->GetTransform()->GetPosition().y;
		parent = parent->GetParent();
	}

	SetPosition(_pos - minusPosition);
}

void TransformC::Translate(Vector2 delta)
{
	SetPosition(_pos + delta);
}

void TransformC::WorldTranslate(Vector2 delta)
{
	SetWorldPosition(_pos + delta);
}

void TransformC::Init()
{

}

void TransformC::Update()
{

}
