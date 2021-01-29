#include "stdafx.h"
#include "MapToolScene.h"
#include "MapToolMouse.h"

HRESULT MapToolScene::init()
{
	//맵 생성 및 초기화
	_mapM = new MapManager;
	_mapM->init();

	//마우스 생성 및 초기화
	_mouse = new MapToolMouse(this);
	_mouse->Init();

	//UI 생성
	AddUI();

	return S_OK;
}

void MapToolScene::release()
{
	Scene::release();

	_mapM->release();
	delete _mapM;
}

void MapToolScene::update()
{
	_mouse->Update();

	_zoom = ((unsigned int)(_wheelMouse)+10) / 10.0f;
	CAMERAMANAGER->GetVCamera()[0]->SetZoom(_zoom);
	_mapM->update();
	updateUI();
}

void MapToolScene::render()
{

	CAMERAMANAGER->GetVCamera()[0]->SetPos(Vector2(_ptMouse.x, _ptMouse.y));
	CAMERAMANAGER->GetVCamera()[1]->SetPos(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	//CAMERAMANAGER->GetVCamera()[0]->SetPos(Vector2(WINSIZEX / 2, WINSIZEY / 2));

	_mapM->render();
	_mouse->Render();

	renderUI();


}

void MapToolScene::AddUI()
{
	addUnderBarUI("기초", Vector2(50, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 0, 0);
	addUnderBarUI("벽 & 문", Vector2(110, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 1, 0);
	addUnderBarUI("방", Vector2(170, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 2, 0);
	addUnderBarUI("물품", Vector2(230, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 3, 0);
	addUnderBarUI("계획", Vector2(290, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 4, 0);
	addUnderBarUI("퀵빌드", Vector2(350, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 5, 0);
	addUnderBarUI("직원", Vector2(410, WINSIZEY - 45), 0.7f, ImageManager::GetInstance()->FindImage("buttonBlue"), 6, 0);

	addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);
	addUnderBarWindowUI(Vector2(100, WINSIZEY - 275), Vector2(200, 400), 0.7f);

	for (int i = 0; i < 7; ++i) setLinkUnderBarUI(i, i);

	addObjectButtonUIInWindowUI(0, "가스레인지", Vector2(25, WINSIZEY / 2 - 90), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
	addObjectButtonUIInWindowUI(0, "배식대", Vector2(75, WINSIZEY / 2 - 90), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
	addObjectButtonUIInWindowUI(0, "벤치", Vector2(125, WINSIZEY / 2 - 90), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
	addObjectButtonUIInWindowUI(0, "wall0", Vector2(175, WINSIZEY / 2 - 90), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
	addObjectButtonUIInWindowUI(0, "wall1", Vector2(25, WINSIZEY / 2 - 40), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
	addObjectButtonUIInWindowUI(0, "사무실책상", Vector2(75, WINSIZEY / 2 - 40), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
	addObjectButtonUIInWindowUI(0, "GRASS2", Vector2(125, WINSIZEY / 2 - 40), 0.6f, ImageManager::GetInstance()->FindImage("buttonBlue"));
}

void MapToolScene::updateUI()
{
	/*
	// 레이어 판단 추가 필욬
	for (BarButtonUI* u : _vUnderBarUI)
	{
		u->update();

		Vector2 pt = Vector2(_ptMouse);
		if (u->getButton()->getRect().PtInRect(pt) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_currentUnderBarActive == u) // 창이 열려있는데 해당 창 버튼을 누르면 해당 창을 끈다
			{
				u->setIsActive(false);
				_currentUnderBarActive = nullptr;
				if (MouseControl::GetInstance()->_mouseObj != NULL) MouseControl::GetInstance()->_mouseObj = NULL; // 현재 오브젝트를 집고 있으면 없앤다
				break;
			}
			else if (_currentUnderBarActive != nullptr) // 현재 켜져있는 창이 있으면 
			{
				_currentUnderBarActive->setIsActive(false); // 현재 창을 끄고
				if (MouseControl::GetInstance()->_mouseObj != NULL) MouseControl::GetInstance()->_mouseObj = NULL; // 현재 오브젝트를 집고 있으면 없앤다
			}
			// 내가 누른 창을 킨다
			u->setIsActive(true);
			_currentUnderBarActive = u;
			break;
		}
	}

	for (WindowUI* w : _vUnderBarWindowUI)
	{
		for (Button* b : w->getVButton())
		{
			Vector2 pt = Vector2(_ptMouse);
			if (b->getRect().PtInRect(pt) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				string name = b->getName();
				MouseControl::GetInstance()->_mouseObj = DATAMANAGER->FindTileObject(name);
				cout << "check" << endl;
			}
		}
	}
	*/


	/////

	
}

void MapToolScene::renderUI()
{
	// 대화 중에는 UI 랜더 없음

	Vector2 vTemp = Vector2(WINSIZEX / 2, WINSIZEY - 10);
	ImageManager::GetInstance()->FindImage("screenEdge")->SetScale(0.7f);
	ImageManager::GetInstance()->FindImage("screenEdge")->SetAlpha(0.8f);
	ImageManager::GetInstance()->FindImage("screenEdge")->Render(vTemp);



	for (BarButtonUI* u : _vUnderBarUI)
	{
		u->render();
	}

	for (WindowUI* u : _vUnderBarWindowUI)
	{
		u->render();
	}
}

void MapToolScene::addUnderBarUI(string strName, Vector2 pos, float scale, Image * img, int frameX, int frameY)
{
	BarButtonUI* temp = new BarButtonUI(strName, pos, scale, img, frameX, frameY);
	temp->setIsRender(true);
	_vUnderBarUI.push_back(temp);
}

void MapToolScene::addUnderBarWindowUI(Vector2 pos, Vector2 size, float scale)
{
	WindowUI* temp = new WindowUI(pos, size, scale);
	_vUnderBarWindowUI.push_back(temp);
}

void MapToolScene::addObjectButtonUIInWindowUI(int arrNum, string strName, Vector2 pos, float scale, Image * img)
{
	_vUnderBarWindowUI[arrNum]->addObjectButtonUI(strName, pos, scale, img);
}

void MapToolScene::setLinkUnderBarUI(int arrNum, int arrNum2)
{
	_vUnderBarUI[arrNum]->setLinkWindowUI(_vUnderBarWindowUI[arrNum2]);
}