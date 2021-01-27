#pragma once
#include "singletonBase.h"
#include "UI.h"

class UIManager : public singletonBase<UIManager>
{
private:
	vector<BarButtonUI*> _underBar;
	vector<WindowUI*> _underBarWindowUI;


	BarButtonUI* currentUnderBarActive;
public:
	UIManager();
	~UIManager();


	HRESULT init();
	void release();
	void update();
	void render();

	void addUnderBarUI(string strName, Vector2 pos, float scale, Image* img, int frameX, int frameY);
	void addUnderBarWindowUI(Vector2 pos, Vector2 size, float scale);
	void addObjectButtonUIInWindowUI(int arrNum, string strName, Vector2 pos, float scale, Image* img);
	
	void addWindowUI(Vector2 pos, Vector2 size, float scale);
	

	void setLinkUnderBarUI(int arrNum, int arrNum2);


	vector<BarButtonUI*> getVUnderBar() { return _underBar; }
	vector<WindowUI*> getVUnderBarWindowUI() { return _underBarWindowUI; }
};

