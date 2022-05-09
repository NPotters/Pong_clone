#pragma once
#include "stdafx.h"
#include "VisibleGameObjects.h"
//derive class from base class VisibleGameObjects but only using the public members
class PaddlePlayer2 :
	public VisibleGameObject
{
public:
	PaddlePlayer2();
	~PaddlePlayer2();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	// Determine (max)speed and direction of paddles
	float _velocity; // -- is up ++ is down
	float _maxVelocity;
};
