#include "stdafx.h"
#include "Worker.h"
#include "AllComponents.h"

Worker::Worker(int num)
{

	//ÆÄÃ÷ ÃÊ±âÈ­
	{
		//¸ö ÃÊ±âÈ­
		char bodImgName[20];
		sprintf_s(bodImgName, "worker%d", num);
		_torso = CreateObject();
		_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(bodImgName);
		_torso->GetComponent<DrawC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
		_torso->GetTransform()->SetPosition(_transform->GetPosition());
	}
}

HRESULT Worker::init()
{
	return S_OK;
}

void Worker::release()
{
}

void Worker::update()
{
	Character::update();
}

void Worker::render()
{
}
