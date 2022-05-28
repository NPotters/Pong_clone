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

/*class PinkGlow :
	public VisibleGameObject
{
public:
	PinkGlow();
	virtual ~PinkGlow();
};

class BlueGlow :
	public VisibleGameObject
{
public:
	BlueGlow();
	virtual ~BlueGlow();
};*/