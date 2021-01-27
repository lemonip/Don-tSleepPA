#pragma once
#include <vector>

class Component;
class TransformC;

class GameObject
{
protected:
	string _name;		//이름
	string _tag;		//태그
	bool _isActive;		//활성화 여부
	
	TransformC* _transform;				//트랜스폼

	vector<Component*> _vComponent;		//컴포넌트 벡터

	GameObject* _parent;				//부모
	vector<GameObject*> _vChild;		//자식 벡터

public:
	GameObject();
	~GameObject() {}

	/* ==================================================
		오브젝트와 클론 생성
	================================================== */

	//오브젝트 만들기
	static GameObject* CreateObject(GameObject* parent = NULL);

	//클론 만들기
	template<typename T>
	T* GetClone();

	/* ==================================================
		컴포넌트 게터 세터
	================================================== */

	//컴포넌트 벡터 게터
	template<typename T>
	vector<T*> GetvComponent();

	//컴포넌트 게터
	template<typename T>
	T * GetComponent();

	//컴포넌트 추가
	template<typename T>
	T * AddComponent();

	//컴포넌트 제거
	void RemoveComponent(Component* component);

	//트랜스폼 게터
	TransformC* GetTransform() { return _transform; };



	/* ==================================================
		부모 자식 설정
	================================================== */

	//부모 설정
	void SetParent(GameObject* parent);
	
	//자식 설정
	void AddChild(GameObject* child);
	
	//자식 제거
	void RemoveChild(GameObject* child);
	

	/* ==================================================
		게터
	================================================== */
	//게터
	GameObject* GetParent() { return _parent; };
	vector<GameObject*> GetChildren() { return _vChild; };
	//GameObject* GetChildByName(string name);


	/* ==================================================
		세터
	================================================== */


	/* ==================================================
		함수
	================================================== */
	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	//카메라 컴포넌트 없어서 임시로 만든 렌더
	virtual void Render(HDC hdc);

};

template<typename T>
inline vector<T*> GameObject::GetvComponent()
{
	vector<T*> componentVector;
	for (auto c : _vComponent)
	{
		if (dynamic_cast<T*>(c)) componentVector.push_back((T*)c);
	}
	return componentVector;
}

//컴포넌트 게터
template<typename T>
inline T * GameObject::GetComponent()
{
	for (Component* c : _vComponent)
	{
		if (dynamic_cast<T*>(c)) return (T*)c;
	}
	return NULL;
}

//컴포넌트 추가
template<typename T>
inline T * GameObject::AddComponent()
{
	Component* component = new T();
	component->LinkGameObject(this);
	_vComponent.push_back(component);
	component->Awake();
	return (T*)component;
}

//클론 만들기
template<typename T>
inline T * GameObject::GetClone()
{
	T* object = new T();
	memmove(object, this, sizeof(T*));
	return object;
}
