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
	//_img->render(_camera->_dc->getMemDC(), _object->GetTransform()->GetPosition().x, _transform->GetPosition().y);
}

void DrawC::Render(HDC hdc)
{
	if (!_img) return;
	//_img->render(hdc, _transform->GetPosition().x, _transform->GetPosition().y);
}
