#include "stdafx.h"
#include "Staff.h"

Staff::Staff(STAFFROLE role)
{
	_role = role;
	_torso = CreateObject(this);

	switch (role)//역할에 따른 이미지 등록
	{
		case STAFFROLE::ACCOUNTANT:
		{
			_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("accountant");
		}
		break;
		case STAFFROLE::CLEANER:
		{
			string bodImgName;
			bodImgName = "cleaner" + to_string(RND->getInt(4));
			_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(bodImgName);
		}
		break;
		case STAFFROLE::COOKER:
		{
			string bodImgName;
			bodImgName = "cooker" + to_string(RND->getInt(4));
			_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(bodImgName);
		}
		break;
		case STAFFROLE::DOCTER:
		{
			string bodImgName;
			bodImgName = "docter" + to_string(RND->getInt(4));
			_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(bodImgName);
		}
		break;
	}

	_torso->GetComponent<DrawC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
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
}

void Staff::render()
{
	//각 부위별 렌더
	if (_torso->GetTransform()->GetDirection() == DIRECTION::RIGHT) _torso->GetComponent<DrawC>()->_img->SetReverseX(true);
	_torso->GetComponent<DrawC>()->Render(_info.frameX[(int)_transform->GetDirection()], 0);

	_rightHand->GetComponent<DrawC>()->Render();
	_leftHand->GetComponent<DrawC>()->Render();
}
