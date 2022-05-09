#pragma once
#include "VisibleGameObjects.h"
//subclass of the public VisibleGameObject
class Ball :
	public VisibleGameObject
{
public:
	Ball();
	virtual ~Ball();
};