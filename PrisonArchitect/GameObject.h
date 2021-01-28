#pragma once
#include <vector>

class Component;
class TransformC;

class GameObject
{
protected://모르겠는 변수들,,=====================================
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
	//이게뭐지... creato라는 이름의 함수고... 여기에 init해서 생성한애를 넣는건가?
	// 눌은 왜해..?
	//인자값은 몰라도 트랜스폼컴포넌트를 무조건 넣구 만드네...근데 자료형에 뭘 ?
	//넣어야해?????? 쓰지도 않는데?
	static GameObject* CreateObject(GameObject* parent = NULL);

	//클론 만들기
	template<typename T>
	T* GetClone();

	/* ==================================================
		컴포넌트 게터 세터
	================================================== */

	//컴포넌트 벡터 게터
	//자유로운 타입으로 만들어진 벡터를 가져오내///
	template<typename T>
	vector<T*> GetvComponent();

	//컴포넌트 게터
	//?????? 벡터에 든 컴포넌트가 몇번째껀줄알고..???
	template<typename T>
	T * GetComponent();

	//컴포넌트 추가
	//컴포넌트가 무슨컴포넌튼줄알고..?
	//게다가 반환하잖아..???
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
	// int* getcom() if <int>컴포 라면..int 로 형변환해서 c를 ??
	//t랑 자료형이 값은 컴포가 있으면내뱉는다느거야? 아니 근데 t가 뭔줄알고?
	// : 가 뭐야
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
