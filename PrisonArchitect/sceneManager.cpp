#include "stdafx.h"
#include "sceneManager.h"
#include "Scene.h"
#include "TitleScene.h"

SceneManager::SceneManager()
{
	_vScene.push_back(new TitleScene);
}

void SceneManager::ReplaceScene(Scene * scene)
{
	for (Scene* s : _vScene) s->release();
	_vScene.clear();

	_vScene.push_back(scene);
	scene->init();
}

void SceneManager::PushScene(Scene * scene)
{
	_vScene.push_back(scene);
	scene->init();
}

void SceneManager::PopScene(Scene * scene)
{
	_vScene[_vScene.size() - 1]->release();
	_vScene.pop_back();
}
