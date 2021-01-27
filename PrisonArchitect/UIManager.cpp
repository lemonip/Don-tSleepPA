#include "stdafx.h"
#include "UIManager.h"
#include "Button.h"

UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}

HRESULT UIManager::init()
{
	return S_OK;
}

void UIManager::release()
{
}

void UIManager::update()
{
	for (BarButtonUI* u : _underBar)
	{
		u->update();

		Vector2 pt = Vector2(_ptMouse);
		if (u->getButton()->getRect().PtInRect(pt) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (currentUnderBarActive == u) // 창이 열려있는데 해당 창 버튼을 누르면
			{
				u->setIsActive(false);
				currentUnderBarActive = nullptr;
				break;
			}
			else if (currentUnderBarActive != nullptr)
			{
				currentUnderBarActive->setIsActive(false);
			}
			u->setIsActive(true);
			currentUnderBarActive = u;
			break;
		}
	}

	for (WindowUI* w : _underBarWindowUI)
	{
		for (Button* b : w->getVButton())
		{
			Vector2 pt = Vector2(_ptMouse);
			if (b->getRect().PtInRect(pt) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				cout << "check" << endl;
			}
		}
	}
}

void UIManager::render()
{
	// 대화 중에는 UI 랜더 없음

	Vector2 vTemp = Vector2(WINSIZEX / 2, WINSIZEY - 10);
	ImageManager::GetInstance()->FindImage("screenEdge")->SetScale(0.7f);
	ImageManager::GetInstance()->FindImage("screenEdge")->SetAlpha(0.8f);
	ImageManager::GetInstance()->FindImage("screenEdge")->Render(vTemp);

	

	for (BarButtonUI* u : _underBar)
	{
		u->render();
	}

	for (WindowUI* u : _underBarWindowUI)
	{
		u->render();
	}
}

void UIManager::addUnderBarUI(string strName, Vector2 pos, float scale, Image * img, int frameX, int frameY)
{
	BarButtonUI* temp = new BarButtonUI(strName, pos, scale, img, frameX, frameY);
	temp->setIsRender(true);
	_underBar.push_back(temp);

}

void UIManager::addUnderBarWindowUI(Vector2 pos, Vector2 size, float scale)
{
	WindowUI* temp = new WindowUI(pos, size, scale);
	_underBarWindowUI.push_back(temp);
}

void UIManager::addObjectButtonUIInWindowUI(int arrNum, string strName, Vector2 pos, float scale, Image* img)
{
	_underBarWindowUI[arrNum]->addObjectButtonUI(strName, pos, scale, img);
}

void UIManager::setLinkUnderBarUI(int arrNum, int arrNum2)
{
	_underBar[arrNum]->setLinkWindowUI(_underBarWindowUI[arrNum2]);
}
