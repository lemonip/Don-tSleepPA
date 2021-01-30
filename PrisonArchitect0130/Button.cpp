#include "stdafx.h"
#include "Button.h"

Button::Button(string strName, Vector2 pos, float scale, Image * img)
{
	_name = strName;
	_img = img;
	_scale = scale;
	_img->SetScale(_scale);
	_pos = pos;
	_size = _img->GetFrameSize();
	_rc = FloatRect(_pos, _size * _scale * _scale, Pivot::Center);


	_frameX = 0;
	_frameY = 0;
}

Button::Button(string strName, Vector2 pos, float scale, Image* img, int frameX, int frameY)
{
	_name = strName;
	_img = img;
	_scale = scale;
	_img->SetScale(_scale);
	_pos = pos;
	_size = _img->GetFrameSize();
	_rc = FloatRect(_pos, _size * _scale * _scale, Pivot::Center);


	_frameX = frameX;
	_frameY = frameY;
}

Button::~Button()
{
}

void Button::render()
{
#if true // Debug

	//µð¹ö±ë¿ë ·ºÆ® ·»´õ
	if (KEYMANAGER->isToggleKey(VK_SHIFT))
	{
		D2DRenderer::GetInstance()->DrawRectangle(_rc, D2DRenderer::DefaultBrush::Blue, 1.0f);
	}

#endif // Debug
	_img->SetScale(_scale);
	_img->FrameRender(_pos, _frameX, _frameY);
}
