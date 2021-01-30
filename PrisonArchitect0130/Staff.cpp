#include "stdafx.h"
#include "Staff.h"

Staff::Staff(STAFFROLE role)
{
	_role = role;
	_torso = CreateObject(this);

	switch (role)
	{
		case STAFFROLE::ACCOUNTANT:
		_torso->AddComponent<ImageC>()->SetImage(IMAGEMANAGER->FindImage("accountant")); break;

		case STAFFROLE::CLEANER:
		{
			string bodImgName;
			bodImgName = "cleaner" + to_string(RND->getInt(4));
			_torso->AddComponent<ImageC>()->SetImage(IMAGEMANAGER->FindImage(bodImgName)); break;
		}
		break;
		case STAFFROLE::COOKER:
		{
			string bodImgName;
			bodImgName = "cooker" + to_string(RND->getInt(4));
			_torso->AddComponent<ImageC>()->SetImage(IMAGEMANAGER->FindImage(bodImgName)); break;
		}
		break;
		case STAFFROLE::DOCTER:
		{
			string bodImgName;
			bodImgName = "docter" + to_string(RND->getInt(4));
			_torso->AddComponent<ImageC>()->SetImage(IMAGEMANAGER->FindImage(bodImgName)); break;
		}
		break;
	}
_torso->GetComponent<ImageC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
_torso->GetTransform()->SetPosition(_transform->GetPosition());
}

HRESULT Staff::init()
{
	return S_OK;
}

void Staff::release()
{
}

void Staff::update()
{
	Character::Update();

}

void Staff::render()
{
	Character::render();
	if (_torso->GetTransform()->GetDirection() == DIRECTION::RIGHT) _torso->GetComponent<ImageC>()->SetReverese(true, false);
	_torso->GetComponent<ImageC>()->SetFrame(Vector2(_info.frameX[(int)_transform->GetDirection()], 0));

}
