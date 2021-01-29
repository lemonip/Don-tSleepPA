#include "stdafx.h"
#include "DrawC.h"

#include "TransformC.h"
#include "GameObject.h"

void DrawC::Awake()
{
	this->_transform = _object->GetTransform();
}

void DrawC::Init()
{

}

void DrawC::Update()
{
}

void DrawC::Render()
{
	if (!_img) return;
	_img->Render(Vector2(_object->GetTransform()->GetPosition().x, _transform->GetPosition().y), _camera);
}

void DrawC::Render(int frameX, int frameY)
{
	if (!_img) return;
	_img->FrameRender(Vector2(_object->GetTransform()->GetPosition().x, _transform->GetPosition().y), frameX, frameY, _camera);
}
