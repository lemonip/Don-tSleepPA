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
	_logoImg->SetScale(0.7f);
	_logoImg->Render(Vector2(WINSIZEX / 2, WINSIZEY*0.2));
}
