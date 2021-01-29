#pragma once
#include "Character.h"

class People : public Character
{
private:
	PEOPLEROLE _role;

public:
	People(PEOPLEROLE role);

};

