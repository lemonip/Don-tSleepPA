#include "stdafx.h"
#include "CampaignScene.h"

HRESULT CampaignScene::init()
{
	People* _tempP = new People(PEOPLEROLE::BITALIA);
	_tempP->init();
	_vPeople.push_back(_tempP);
	_cameraPos.x = WINSIZEX / 2;
	_cameraPos.y = WINSIZEY / 2;
	_cameraZoom = 1.f;
	return S_OK;
}

void CampaignScene::release()
{
	//벡터에 있는 사람들
	for (int i = 0; i != _vPeople.size(); i++)
	{
		_vPeople[i]->update();
	}
}

void CampaignScene::update()
{

	if (KEYMANAGER->isOnceKeyUp(VK_RETURN))
	{
		SCENEMANAGER->PopScene(this);
	}
	_cameraPos.y++;
	_cameraZoom += 0.1f;
}

void CampaignScene::render()
{
	IMAGEMANAGER->FindImage("temp")->Render(Vector2(0,0), CAMERAMANAGER->GetVCamera()[0]);
	IMAGEMANAGER->FindImage("dialogWindow")->Render(Vector2(0,0), CAMERAMANAGER->GetVCamera()[1]);

	CAMERAMANAGER->GetVCamera()[0]->SetPos(_cameraPos);
	CAMERAMANAGER->GetVCamera()[0]->SetZoom(_cameraZoom);

	for (int i = 0; i != _vPeople.size(); i++)
	{
		_vPeople[i]->render();
	}
}
