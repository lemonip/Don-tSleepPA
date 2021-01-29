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
	virtual void Render(int frameX, int frameY);

	void SetCamera(Camera* camera) { _camera = camera; }

};

