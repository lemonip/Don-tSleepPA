#pragma once
class Mouse
{
protected:
	MOUSESTATE _state;			//마우스 스테이트
	bool _isOnUI;				//UI위에 있는지
public:

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	void SetState(MOUSESTATE state) { _state = state; };

};

