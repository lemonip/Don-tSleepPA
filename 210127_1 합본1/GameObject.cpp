#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"
#include "TransformC.h"

GameObject::GameObject()
{

}

GameObject * GameObject::CreateObject(GameObject * parent)
{
	GameObject* object = new GameObject();
	object->_transform = object->AddComponent<TransformC>();
	return object;
}

void GameObject::SetParent(GameObject * parent)
{
	_parent = parent;
	_parent->_vChild.push_back(this);
}

void GameObject::AddChild(GameObject * child)
{
	_vChild.push_back(child);
	child->_parent->RemoveChild(child);
	child->_parent = this;
}

void GameObject::RemoveChild(GameObject * child)
{
	for (int i = 0; i < _vChild.size(); i++)
	{
		if (_vChild[i] != child) continue;
		_vChild.erase(_vChild.begin() + i);
		break;
	}
}

void GameObject::RemoveComponent(Component * component)
{
}

void GameObject::Init()
{
	for (GameObject* c : _vChild)
		c->Init();


	for (Component* c : _vComponent)
		c->Init();

}

void GameObject::Release()
{
}

void GameObject::Update()
{
	for (GameObject* c : _vChild)
		c->Update();


	for (Component* c : _vComponent)
		c->Update();
}

void GameObject::Render()
{
	for (GameObject* c : _vChild)
		c->Render();


	for (Component* c : _vComponent)
		c->Render();
}

void GameObject::Render(HDC hdc)
{

	for (GameObject* c : _vChild)
		c->Render(hdc);


	for (Component* c : _vComponent)
		c->Render(hdc);
}
