#include "stdafx.h"
#include "TestScene.h"

HRESULT TestScene::init()
{
	cout << "¿ì";

	_Prisoner = new Prisoner;
	_Prisoner->init(0, 0);

	return S_OK;
}

void TestScene::release()
{
}

void TestScene::update()
{
	_Prisoner->update();
}

void TestScene::render()
{
	_Prisoner->render();

}
