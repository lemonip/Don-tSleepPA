#pragma once
#include "gameNode.h"
#include "MapManager.h"
#include "Scene.h"
#include "Button.h"

class MapToolScene : public Scene
{
private:
	MapManager* _mapM;

	vector<Character*> _vCharacter;


	vector<BarButtonUI*>	_vUnderBarUI;
	vector<WindowUI*>		_vUnderBarWindowUI;
	BarButtonUI*			_currentUnderBarActive;

public:
	MapToolScene() {};
	~MapToolScene() {};
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	// UI
	void AddUI();
	void updateUI();
	void renderUI();

	void addUnderBarUI(string strName, Vector2 pos, float scale, Image* img, int frameX, int frameY);
	void addUnderBarWindowUI(Vector2 pos, Vector2 size, float scale);
	void addObjectButtonUIInWindowUI(int arrNum, string strName, Vector2 pos, float scale, Image* img);
	void setLinkUnderBarUI(int arrNum, int arrNum2);

	//GETTER
	MapManager* GetMapM() { return _mapM; }

	vector<Character*> GetvCharacter() { return _vCharacter; }

	vector<BarButtonUI*>	GetvUnderBarUI() { return _vUnderBarUI; };
	vector<WindowUI*>		GetvUnderBarWindowUI() { return _vUnderBarWindowUI; }
	BarButtonUI*			GetvurrentUnderBarActive() { return _currentUnderBarActive; }

};

