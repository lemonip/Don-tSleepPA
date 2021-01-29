#include "stdafx.h"
#include "Scene.h"

HRESULT Scene::init()
{
	//_mouse->Init();
	return S_OK;
}

void Scene::release()
{
	_mouse->Release();
}

void Scene::update()
{
	_mouse->Update();
}

void Scene::render()
{
	_mouse->Render();
}
