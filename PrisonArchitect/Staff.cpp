#include "stdafx.h"
#include "Staff.h"

Staff::Staff(STAFFROLE role)
{
	_role = role;

	switch (role)
	{
		case STAFFROLE::ACCOUNTANT:

		break;
		case STAFFROLE::CLEANER:

		break;
		case STAFFROLE::COOKER:

		break;
		case STAFFROLE::DOCTER:

		break;
	}
}

HRESULT Staff::init()
{
	return S_OK;
}

void Staff::release()
{
}

void Staff::update()
{
}

void Staff::render()
{
}
