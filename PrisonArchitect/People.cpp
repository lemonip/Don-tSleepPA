#include "stdafx.h"
#include "People.h"

People::People(PEOPLEROLE role)
{
	_role = role;
	_torso = CreateObject(this);

	switch (role)//역할에 따른 이미지 등록
	{
	case PEOPLEROLE::BITALIA:
		_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("bitalia"); break;
	case PEOPLEROLE::BOSS:
		_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("boss"); break;
	case PEOPLEROLE::NICO:
		_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("nico"); break;
	}
	_torso->GetComponent<DrawC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
	_torso->GetTransform()->SetPosition(_transform->GetPosition());
}

HRESULT People::init()
{

	return S_OK;
}

void People::release()
{
}

void People::update()
{
}

void People::render()
{
	//각 부위별 렌더
	if (_torso->GetTransform()->GetDirection() == DIRECTION::RIGHT) _torso->GetComponent<DrawC>()->_img->SetReverseX(true);
	_torso->GetComponent<DrawC>()->Render(_info.frameX[(int)_transform->GetDirection()], 0);

}
