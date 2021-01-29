#pragma once
#include "gameNode.h"
#include "MapManager.h"
#include "Scene.h"
#include "Button.h"

class MapToolScene : public Scene
{
private:
	MapManager* _mapM;
	float _zoom;

	vector<BarButtonUI*>	_vUnderBarUI;
	vector<WindowUI*>		_vUnderBarWindowUI;
	BarButtonUI*			_currentUnderBarActive;

public:

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


};

