#pragma once
#include "Component.h"

class TransformC;
class PeopleUtilC : public Component
{
	TransformC* _transform;		//Æ®·£½ºÆû
public:
	PeopleUtilC() {}
	~PeopleUtilC() {}

	virtual void Awake() override;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	void ChangeFrameX();


};

