#include "stdafx.h"
#include "MapToolScene.h"

HRESULT MapToolScene::init()
{
	_mapM = new MapManager;
	_mapM->init();
	AddUI();
	return S_OK;
}

void MapToolScene::release()
{
	_mapM->release();
	delete _mapM;
}

void MapToolScene::update()
{
	_zoom = ((unsigned int)(_wheelMouse)+10) / 10.0f;
	CAMERAMANAGER->GetVCamera()[0]->SetZoom(_zoom);
	_mapM->update();
}

void MapToolScene::render()
{
	CAMERAMANAGER->GetVCamera()[0]->SetPos(Vector2(_ptMouse.x, _ptMouse.y));
	CAMERAMANAGER->GetVCamera()[1]->SetPos(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	//CAMERAMANAGER->GetVCamera()[0]->SetPos(Vector2(WINSIZEX / 2, WINSIZEY / 2));

	_mapM->render();
}

void MapToolScene::AddUI()
{
	UIMANAGER->addUnderBarUI("기초", Vector2(50, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 0, 0);
	UIMANAGER->addUnderBarUI("벽 & 문", Vector2(110, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 1, 0);
	UIMANAGER->addUnderBarUI("방", Vector2(170, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 2, 0);
	UIMANAGER->addUnderBarUI("물품", Vector2(230, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 3, 0);
	UIMANAGER->addUnderBarUI("계획", Vector2(290, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 4, 0);
	UIMANAGER->addUnderBarUI("퀵빌드", Vector2(350, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 5, 0);
	UIMANAGER->addUnderBarUI("직원", Vector2(410, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 6, 0);

	UIMANAGER->addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	UIMANAGER->addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	UIMANAGER->addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	UIMANAGER->addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	UIMANAGER->addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	UIMANAGER->addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	UIMANAGER->addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);

	for (int i = 0; i < 7; ++i)
	{
		UIMANAGER->setLinkUnderBarUI(i, i);
	}

	UIMANAGER->addObjectButtonUIInWindowUI(0, "테스트", Vector2(50, WINSIZEY - 300), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
	UIMANAGER->addObjectButtonUIInWindowUI(0, "테스트", Vector2(100, WINSIZEY - 300), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
}
