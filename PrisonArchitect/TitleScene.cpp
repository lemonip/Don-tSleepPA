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
}
