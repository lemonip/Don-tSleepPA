#pragma once
#include "MapToolMouse.h"

template<typename T>
void MapToolMouse::OnCollisionEnter(T * obj)
{
	obj->MouseEnter();
}

template<typename T>
void MapToolMouse::OnCollisionExit(T * obj)
{
	obj->MouseExit();
}

template<typename T>
void MapToolMouse::OnCollisionStay(T * obj)
{
	obj->MouseStay();
}
