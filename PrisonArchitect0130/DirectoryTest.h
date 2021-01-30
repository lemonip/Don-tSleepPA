#pragma once
#include "gameNode.h"


class DirectoryTest : public gameNode
{
public:
	virtual HRESULT init();
	virtual void release() {}
	virtual void update() {}
	virtual void render() {}
};

