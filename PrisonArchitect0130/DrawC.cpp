#include "stdafx.h"
#include "DrawC.h"

#include "TransformC.h"
#include "GameObject.h"

void DrawC::Awake()
{
	this->_transform = _object->GetTransform();
}

