#pragma once
#include "MouseControl.h"

template<typename T>
void MouseControl::OnCollisionEnter(T * obj)
{
	obj->MouseEnter();
}

template<typename T>
void MouseControl::OnCollisionExit(T * obj)
{
	obj->MouseExit();
}

template<typename T>
void MouseControl::OnCollisionStay(T * obj)
{
	obj->MouseStay();
}
