#include "stdafx.h"
#include "Character.h"

Character::Character()
{
	//방향에 따른 프레임 설정
	_info.frameX[0] = 0;	//앞
	_info.frameX[1] = 2;	//옆
	_info.frameX[2] = 1;	//뒤
	_info.frameX[4] = 3;	//잠

	//트랜스 폼 컴포넌트와 기본 설정
	{
		_transform = AddComponent<TransformC>();
		_transform->SetPosition(Vector2(WINSIZEX / 2, WINSIZEY / 2));
		_transform->SetDirection(DIRECTION::FRONT);

		//아직은 전체속도 없음 
		_info.moveSpeed = 4.f * _gameSpeed;	//*전체속도 를 곱해줘서 이동속도와 액션속도가 바뀔거같음. 
		_info.actSpeed = 1.f * _gameSpeed;	//*전체속도 액션속도로 팔움직이고 그런거 하지않을까.. 항상 전체속도 곱해주는것 매우 중요!!
	}

	//신체 부위 - 손
	{
		//오른손 초기화
		_rightHand = CreateObject(this);
		_rightHand->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("hand");
		_rightHand->GetComponent<DrawC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
		_rightHand->GetTransform()->SetPosition
		(Vector2(_transform->GetPosition().x - HANDOFFSETX, _transform->GetPosition().y - HANDOFFSETY));

		//왼손 초기화
		_leftHand = CreateObject(this);
		_leftHand->AddComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("hand");
		_leftHand->GetComponent<DrawC>()->SetCamera(CAMERAMANAGER->GetVCamera()[0]);
		_leftHand->GetTransform()->SetPosition
		(Vector2(_transform->GetPosition().x + HANDOFFSETX, _transform->GetPosition().y - HANDOFFSETY));
	}
}

HRESULT Character::init()
{
	return S_OK;
}

void Character::release()
{
}

void Character::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _transform->Translate(Vector2(_info.moveSpeed, 0.0f));
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))	 _transform->Translate(Vector2(-_info.moveSpeed, 0.0f));
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))	 _transform->Translate(Vector2(0.0f, _info.moveSpeed));
	if (KEYMANAGER->isStayKeyDown(VK_UP))	 _transform->Translate(Vector2(0.0f, -_info.moveSpeed));

	if (KEYMANAGER->isStayKeyDown(VK_SPACE)) _transform->Translate(Vector2(RND->getFromFloatTo(-_info.moveSpeed, _info.moveSpeed), RND->getFromFloatTo(-_info.moveSpeed, _info.moveSpeed)));
}

void Character::render()
{
}
