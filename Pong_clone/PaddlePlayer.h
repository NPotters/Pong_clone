#pragma once
#include "VisibleGameObjects.h"
//derive class from base class VisibleGameObjects but only using the public members
class PaddlePlayer :
	public VisibleGameObject
{
public:
	PaddlePlayer();
	~PaddlePlayer();
};