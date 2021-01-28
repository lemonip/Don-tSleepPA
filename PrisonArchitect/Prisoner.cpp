#include "stdafx.h"
#include "Prisoner.h"

//초기화
HRESULT Prisoner::init(int bodNum, int headNum)
{
	_transform = AddComponent<TransformC>();
	_transform->SetPosition(Vector2(WINSIZEX / 2, WINSIZEY / 2));

	/*
	초기화 위치 보정할 예정!
	_info.x = _ptMouse.x;
	_info.y = _ptMouse.y;*/

	_info.dest = DIRECTION::FRONT;

	//아직은 전체속도 없음 
	_info.moveSpeed = 4.f * _gameSpeed;//*전체속도 를 곱해줘서 이동속도와 액션속도가 바뀔거같음. 
	_info.actSpeed = 1.f * _gameSpeed;//*전체속도 액션속도로 팔움직이고 그런거 하지않을까.. 항상 전체속도 곱해주는것 매우 중요!!

	//파츠 초기화
	{
	//몸통 초기화
	char bodImgName[20];
	sprintf_s(bodImgName, "bod%d", bodNum);
	_info.torso = CreateObject();
	_info.torso->AddComponent<DrawC>();
	_info.torso->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(bodImgName);
	_info.torso->GetTransform()->SetPosition(_transform->GetPosition());

	//머리 초기화
	char headImgName[20];
	sprintf_s(headImgName, "head%d", headNum);
	_info.head = CreateObject();
	_info.head->AddComponent<DrawC>();
	_info.head->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(headImgName);

	_info.head->GetTransform()->SetPosition(Vector2( _transform->GetPosition().x, _transform->GetPosition().y - headOffset ));

	//손초기화
	_info.rightHand = CreateObject();
	_info.leftHand = CreateObject();
	_info.rightHand->AddComponent<DrawC>();
	_info.rightHand->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("hand");
	_info.leftHand->AddComponent<DrawC>();
	_info.leftHand->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("hand");


	_info.rightHand->GetTransform()->SetPosition
	(Vector2( _transform->GetPosition().x - handOffsetX, _transform->GetPosition().y - handOffsetY ));

	_info.leftHand->GetTransform()->SetPosition
	(Vector2( _transform->GetPosition().x + handOffsetX, _transform->GetPosition().y - handOffsetY ));
	
	}

	return S_OK;
}

void Prisoner::release()
{
}

void Prisoner::update()
{
	ChangeFrameX();
	//방향키에따라 방향 바꾸게 해봤음(테스트로..오른쪽은 뒤집기렌더 안되서 눈으로볼땐 차이없음)
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))_info.dest = DIRECTION::LEFT;
	if (KEYMANAGER->isOnceKeyDown(VK_UP))_info.dest = DIRECTION::BACK;
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))_info.dest = DIRECTION::FRONT;
	//이동
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))MovePos(3, 0);

}

void Prisoner::render()
{
	//각 부위별 렌더
	_info.torso->GetComponent<DrawC>()->_img->FrameRender
	(Vector2(_info.torso->GetTransform()->GetPosition()), _info.frameX, 0, CAMERAMANAGER->GetVCamera()[0]);

	_info.head->GetComponent<DrawC>()->_img->FrameRender
	(Vector2(_info.head->GetTransform()->GetPosition()), _info.frameX, 0, CAMERAMANAGER->GetVCamera()[0]);

	_info.rightHand->GetComponent<DrawC>()->_img->Render
	(Vector2(_info.rightHand->GetTransform()->GetPosition()), CAMERAMANAGER->GetVCamera()[0]);

	_info.leftHand->GetComponent<DrawC>()->_img->Render
	(Vector2(_info.leftHand->GetTransform()->GetPosition()), CAMERAMANAGER->GetVCamera()[0]);
}



void Prisoner::ChangeFrameX()
{
	//상태와 방향에 따른 프레임x 변경
	if (_info.isSleep)_info.frameX = 3;
	else
	{
		switch (_info.dest)
		{
		case DIRECTION::RIGHT:
		case DIRECTION::LEFT:
			_info.frameX = 2;
			break;
		case DIRECTION::FRONT: _info.frameX = 0;break;
		case DIRECTION::BACK: _info.frameX = 1; break;
		}
	}
}

//임시 이동함수
void Prisoner::MovePos(float x, float y)
{
	//중점이동
	_transform->SetPosition(Vector2
	(_transform->GetPosition().x + x, _transform->GetPosition().y + y));
	
	//몸통 이동
	_info.torso->GetTransform()->SetPosition(_transform->GetPosition());

	//머리 이동
	_info.head->GetTransform()->SetPosition(Vector2(_transform->GetPosition().x, _transform->GetPosition().y - headOffset));

	//손이동
	_info.rightHand->GetTransform()->SetPosition
	(Vector2(_transform->GetPosition().x - handOffsetX, _transform->GetPosition().y - handOffsetY));

	_info.leftHand->GetTransform()->SetPosition
	(Vector2(_transform->GetPosition().x + handOffsetX, _transform->GetPosition().y - handOffsetY));

}

HRESULT Staff::init(ROLE role)
{
	_transform = AddComponent<TransformC>();
	_transform->SetPosition(Vector2(WINSIZEX / 2, WINSIZEY / 2));

	/*
	초기화 위치 보정할 예정!
	_info.x = _ptMouse.x;
	_info.y = _ptMouse.y;*/

	_info.dest = DIRECTION::FRONT;

	_info.moveSpeed = 4.f * _gameSpeed;//*전체속도 를 곱해줘서 이동속도와 액션속도가 바뀔거같음. 
	_info.actSpeed = 1.f * _gameSpeed;//*전체속도 액션속도로 팔움직이고 그런거 하지않을까.. 항상 전체속도 곱해주는것 매우 중요!!

	_info.role = role;
	//파츠 초기화
	{
		//몸 초기화

		char bodImgName[20];
		sprintf_s(bodImgName, "bod%d", role);

		_info.torso = CreateObject();
		_info.torso->AddComponent<DrawC>();
		_info.torso->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage(bodImgName);
		_info.torso->GetTransform()->SetPosition(_transform->GetPosition());

		//손초기화
		_info.rightHand = CreateObject();
		_info.leftHand = CreateObject();
		_info.rightHand->AddComponent<DrawC>();
		_info.rightHand->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("hand");
		_info.leftHand->AddComponent<DrawC>();
		_info.leftHand->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("hand");


		_info.rightHand->GetTransform()->SetPosition
		(Vector2(_transform->GetPosition().x - handOffsetX, _transform->GetPosition().y - handOffsetY));

		_info.leftHand->GetTransform()->SetPosition
		(Vector2(_transform->GetPosition().x + handOffsetX, _transform->GetPosition().y - handOffsetY));

	}

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
}
