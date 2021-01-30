#include "stdafx.h"
#include "TitleScene.h"
#include "MapToolScene.h"
HRESULT TitleScene::init()
{

	return S_OK;
}

void TitleScene::release()
{
}

void TitleScene::update()
{
	if (KEYMANAGER->isOnceKeyUp(VK_RETURN))
	{
		SCENEMANAGER->ReplaceScene(new MapToolScene);
	}

}

void TitleScene::render()
{
	D2DRenderer::GetInstance()->RenderText(_ptMouse.x, _ptMouse.y, L"우왕 이게 왜 안될까", 4, D2D1::ColorF::Red, DWRITE_TEXT_ALIGNMENT_CENTER);
}
