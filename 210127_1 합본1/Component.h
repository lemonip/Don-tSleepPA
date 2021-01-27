#pragma once

class GameObject;

class Component abstract
{
protected:
	GameObject* _object;

public:
	virtual void Awake() {};
	virtual void Init() {};
	virtual void Release() { delete this; };
	virtual void Update() {};
	virtual void Render() {};

	//카메라 없어서 잠깐 만들어 둠
	virtual void Render(HDC hdc) {};

	void LinkGameObject(GameObject* obj) { _object = obj; }
	GameObject* GetGameObject() { return _object; }

};

