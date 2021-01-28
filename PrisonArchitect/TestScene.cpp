#include "stdafx.h"
#include "TestScene.h"

HRESULT TestScene::init()
{
	//임시로 걍 한개 꺼내놓은것..
	_Prisoner = new Prisoner;
	_Prisoner->init(0, 0);

	return S_OK;
}

void TestScene::release()
{
}

void TestScene::update()
{
	//임시로 꺼내놓은애
	_Prisoner->update();

	//벡터에 있는 사람들
	for (int i = 0; i != _vPrisoner.size(); i++)
	{
		_vPrisoner[i]->update();
	}

	//클릭하면 사람을 생성
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		Prisoner* _tempP;
		_tempP = new Prisoner;
		_tempP->init(0, 0);

		_vPrisoner.push_back(_tempP);
	}
	

	
}

void TestScene::render()
{
	//임시로 꺼내놓은애
	_Prisoner->render();

	//사람들
	for (int i = 0; i != _vPrisoner.size(); i++)
	{
		_vPrisoner[i]->render();
	}
}
