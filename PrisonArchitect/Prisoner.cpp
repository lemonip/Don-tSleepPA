#include "stdafx.h"
#include "Prisoner.h"

//생성자
Prisoner::Prisoner(int bodNum, int headNum)
{
	//신체 부위
	{
		//몸통 초기화
		char bodImgName[20];
		sprintf_s(bodImgName, "bod%d", bodNum);
		_torso = CreateObject(this);
		_torso->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(bodImgName);
		_torso->GetComponent<DrawC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
		_torso->GetTransform()->SetPosition(_transform->GetPosition());

		//머리 초기화
		char headImgName[20];
		sprintf_s(headImgName, "head%d", headNum);
		_head = CreateObject(this);
		_head->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(headImgName);
		_head->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y - HEADOFFSET));
		_head->GetComponent<DrawC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);

	}
}
//소멸자
Prisoner::~Prisoner()
{
}

HRESULT Prisoner::init()
{
	return S_OK;
}

void Prisoner::release()
{
}

void Prisoner::update()
{
	Character::update();
}

void Prisoner::render()
{
	//각 부위별 렌더
	if (_torso->GetTransform()->GetDirection() == DIRECTION::RIGHT) _torso->GetComponent<DrawC>()->_img->SetReverseX(true);
	_torso->GetComponent<DrawC>()->Render(_info.frameX[(int)_transform->GetDirection()], 0);

	if (_head->GetTransform()->GetDirection() == DIRECTION::RIGHT) _head->GetComponent<DrawC>()->_img->SetReverseX(true);
	_head->GetComponent<DrawC>()->Render(_info.frameX[(int)_transform->GetDirection()], 0);

	_rightHand->GetComponent<DrawC>()->Render();
	_leftHand->GetComponent<DrawC>()->Render();
}

