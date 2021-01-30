#include "stdafx.h"
#include "TitleScene.h"
#include "MapToolScene.h"

HRESULT TitleScene::init()
{
	_logoImg = IMAGEMANAGER->FindImage("PAlogo");

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
	_logoImg->SetScale(0.7f);
	_logoImg->Render(Vector2(WINSIZEX / 2, WINSIZEY/2), CAMERAMANAGER->GetVCamera()[1]);
}
