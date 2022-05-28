#pragma once
#include "stdafx.h"
#include "Game.h"
#include "VisibleGameObjects.h"

//subclass of the public VisibleGameObject
class Ball :
	public VisibleGameObject
{
public:
	Ball();
	virtual ~Ball();
	//override Update of VisibleGameObject
	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);
	//int _n;
	//int _p;

private:
	float _velocity;
	float _angle;
	float _elapsedTimeSinceStart;
	const float pi = 3.14159265358979323846f;


	float LinearVelocityX(float angle);
	float LinearVelocityY(float angle);
};