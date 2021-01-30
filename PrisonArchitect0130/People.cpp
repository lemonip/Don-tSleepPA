#include "stdafx.h"
#include "People.h"

People::People(PEOPLEROLE role)
{
	_role = role;
	_torso = CreateObject(this);

	switch (role)
	{
	case PEOPLEROLE::BITALIA:
		_torso->AddComponent<ImageC>()->SetImage(IMAGEMANAGER->FindImage("bitalia")); break;
	case PEOPLEROLE::BOSS:
		_torso->AddComponent<ImageC>()->SetImage(IMAGEMANAGER->FindImage("boss")); break;
	case PEOPLEROLE::NICO:
		_torso->AddComponent<ImageC>()->SetImage(IMAGEMANAGER->FindImage("nico")); break;
	}
	_torso->GetComponent<ImageC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
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
	Character::update();

}

void People::render()
{
	Character::render();
	if (_torso->GetTransform()->GetDirection() == DIRECTION::RIGHT) _torso->GetComponent<ImageC>()->SetReverese(true, false);
	_torso->GetComponent<ImageC>()->SetFrame(Vector2(_info.frameX[(int)_transform->GetDirection()], 0));


}
