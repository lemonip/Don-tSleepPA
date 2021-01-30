#include "stdafx.h"
#include "ImageC.h"

#include "TransformC.h"
#include "GameObject.h"

void ImageC::Awake()
{
	DrawC::Awake();
}

void ImageC::Init()
{
}

void ImageC::Update()
{
}

void ImageC::Render()
{
	if (!_img) return;
	if (_img->GetIsFrameImage()) _img->FrameRender(Vector2(_transform->GetPosition().x, _transform->GetPosition().y), _frame.x, _frame.y, _camera);
	else _img->Render(Vector2(_transform->GetPosition().x, _transform->GetPosition().y), _camera);

}
