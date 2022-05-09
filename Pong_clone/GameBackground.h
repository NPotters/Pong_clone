#pragma once
#include "VisibleGameObjects.h"
//subclass of the public VisibleGameObject
class GameBackground :
	public VisibleGameObject
{
public:
	GameBackground();
	virtual ~GameBackground();
};