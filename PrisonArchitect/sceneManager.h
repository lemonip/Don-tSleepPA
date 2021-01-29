#pragma once
#include "singletonBase.h"
#include <stack>
class Scene;

class SceneManager : public singletonBase<SceneManager>
{
public:
	typedef map<string, Scene*>			 mapSceneList;
	typedef map<string, Scene*>::iterator mapSceneIter;

	typedef stack<Scene*>	sScene;

private:
	static Scene* _currentScene;
	mapSceneList _mSceneList;

	//sScene _sScene;		//스택에 담긴 씬

public:
	SceneManager();
	~SceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	Scene* addScene(string sceneName, Scene* scene);

	HRESULT changeScene(string sceneName);

	Scene* GetCurrentScene() { return _currentScene; }

};

