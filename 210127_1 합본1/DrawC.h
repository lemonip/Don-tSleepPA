#pragma once
#include "Component.h"

class TransformC;

class DrawC : public Component
{
public:
	TransformC* _transform;		//트랜스폼
	Camera* _camera;			//카메라

	Image* _img;
public:
	DrawC() {}
	~DrawC() {}

	virtual void Awake() override;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	//카메라 없어서 잠깐 만들어 둠.
	virtual void Render(HDC hdc) override;

};

