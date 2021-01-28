#include "stdafx.h"
#include "ComponentTest.h"

HRESULT ComponentTest::init()
{
	_character = GameObject::CreateObject();


	//인부가 0,1,2,3,4
	// 인부0 12,3,1

	/*
	_worker0 =  GameObject::CreateObject(_worker0);
	_worker1 =  GameObject::CreateObject(_worker0);
	_worker2 =  GameObject::CreateObject(_worker0);
	_worker3 =  GameObject::CreateObject(_worker0);
	
	*/

	_character->GetTransform()->SetPosition(Vector2( WINSIZEX/2, WINSIZEY/2 ));

	_character->AddComponent<DrawC>();
	//->_img = IMAGEMANAGER->FindImage("accountant");
	_character->GetComponent<DrawC>()->_img = IMAGEMANAGER->FindImage("accountant");

	_character->Init();

	return S_OK;
}

void ComponentTest::release()
{
}

void ComponentTest::update()
{ 
	_zoom = ((unsigned int)(_wheelMouse)+10) / 10.0f;
	CAMERAMANAGER->GetVCamera()[0]->SetZoom(_zoom);

	if (_character)_character->Update();

	/*if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		_character->GetTransform()->SetPosition({ _character->GetTransform()->GetPosition().x + 10, _character->GetTransform()->GetPosition().y });

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		_character->GetTransform()->SetPosition({ _character->GetTransform()->GetPosition().x - 10, _character->GetTransform()->GetPosition().y });

	if (KEYMANAGER->isStayKeyDown(VK_UP))
		_character->GetTransform()->SetPosition({ _character->GetTransform()->GetPosition().x, _character->GetTransform()->GetPosition().y - 10 });

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		_character->GetTransform()->SetPosition({ _character->GetTransform()->GetPosition().x, _character->GetTransform()->GetPosition().y + 10 });
*/
}

void ComponentTest::render()
{
	// if (_character)_character->Render();
	//if (_character)_character->Render(getMemDC());

	_character->GetComponent<DrawC>()->_img->FrameRender(Vector2(_character->GetTransform()->GetPosition()), 0,0, CAMERAMANAGER->GetVCamera()[0]);
	
	//for (int i = 0; i < X * Y; i++)
	//TextOut(getMemDC(), 200 + i% X * 50, 200 + i/ X *50, to_string(i).c_str(), strlen(to_string(i).c_str()));

}
