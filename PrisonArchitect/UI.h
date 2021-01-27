#pragma once

class Button;

class UI
{
private:

	
public:
	UI();
	~UI();

	virtual void release();
	virtual void update();
	virtual void render();
};

class ObjectButtonUI : public UI
{
private:
	Button* _button;



public:
	ObjectButtonUI();
	~ObjectButtonUI();
};


/*=======================================================

						Window UI

=======================================================*/
class WindowUI : public UI
{
private:
	vector<Button*>				_vButton;
	vector<Button*>::iterator	_viButton;

	Vector2 _pos;
	Vector2 _size;

	float _alpha;
	float _scale;
	FloatRect _rc;

	bool isActive;
	bool isRender;
public:
	WindowUI(Vector2 pos, Vector2 size, float scale);
	~WindowUI();

	virtual void release();
	virtual void update();
	virtual void render();

	void addObjectButtonUI(string strName, Vector2 pos, float scale, Image* img);
		
	vector<Button*> getVButton() { return _vButton; }
	void setIsActive(bool active) { isActive = active; }
	void setIsRender(bool render) { isRender = render; }
};

/*=======================================================

					Bar Button UI

=======================================================*/
class BarButtonUI : public UI
{
private:
	Button* _button;
	WindowUI* _windowUI;
	bool isActive;
	bool isRender;
public:
	BarButtonUI(string strName, Vector2 pos, float scale, Image * img, int frameX, int frameY);
	~BarButtonUI();

	virtual void release();
	virtual void update();
	virtual void render();

	Button* getButton() { return _button; }
	void setIsActive(bool active) { isActive = active; }
	void setIsRender(bool render) { isRender = render; }

	void setLinkWindowUI(WindowUI* window) { _windowUI = window; }
};
