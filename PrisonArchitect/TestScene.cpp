#include "stdafx.h"
#include "TestScene.h"

HRESULT TestScene::init()
{
	Staff* _tempP = new Staff(STAFFROLE::CLEANER);
	_tempP->init();
	_vStaff.push_back(_tempP);
	return S_OK;
}

void TestScene::release()
{
}

void TestScene::update()
{

	//벡터에 있는 사람들
	for (int i = 0; i != _vStaff.size(); i++)
	{
		_vStaff[i]->update();
	}

	//클릭하면 사람을 생성
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		Character* _tempP = new Prisoner(0,0);
		_tempP->init();

		_vCharacter.push_back(_tempP);
	}
}

void TestScene::render()
{
	//사람들 (나중에는 Z-ORDER에 따라 정렬해야 함)
	for (int i = 0; i != _vStaff.size(); i++)
	{
		_vStaff[i]->render();
	}
}
