#include "stdafx.h"
#include "UI.h"
#include "Button.h"



UI::UI()
{
}

UI::~UI()
{

}


void UI::update()
{

}

void UI::release()
{
}

void UI::render()
{

}


/*=======================================================

						Window UI

=======================================================*/

WindowUI::WindowUI(Vector2 pos, Vector2 size, float scale) : UI()
{
	_pos = pos;
	_size = size;
	_scale = scale;
	_rc = FloatRect(_pos, _size, Pivot::Center);


	isActive = false;
	isRender = false;
}

WindowUI::~WindowUI()
{

}

void WindowUI::release()
{
	for (int i = 0; i < _vButton.size(); ++i)
	{
		SAFE_DELETE(_vButton[i]);
	}
}

void WindowUI::update()
{
}

void WindowUI::render()
{
	if (isRender)
	{
		D2DRenderer::GetInstance()->FillRectangle(_rc, D2D1::ColorF::Gray, 0.8f);
		D2DRenderer::GetInstance()->DrawRectangle(_rc, D2DRenderer::DefaultBrush::Black, 2.0f);
		for (int i = 0; i < _vButton.size(); ++i)
		{
			_vButton[i]->render();
		}
	}
}

void WindowUI::addObjectButtonUI(string strName, Vector2 pos, float scale, Image * img)
{
	Button* bt = new Button(strName, pos, scale, img);
	_vButton.push_back(bt);
}


/*=======================================================

					Bar Button UI

=======================================================*/

BarButtonUI::BarButtonUI(string strName, Vector2 pos, float scale, Image * img, int frameX, int frameY) : UI()
{
	_button = new Button(strName, pos, scale, img, frameX, frameY);

	isActive = false;
	isRender = false;
}

BarButtonUI::~BarButtonUI()
{
}

void BarButtonUI::release()
{
	SAFE_DELETE(_button);
}

void BarButtonUI::update()
{
	if (isActive) _windowUI->setIsRender(true);
	else _windowUI->setIsRender(false);
}

void BarButtonUI::render()
{
	if (isRender) _button->render();
}


