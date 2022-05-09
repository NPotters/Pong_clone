#pragma once
#include "stdafx.h"
#include "VisibleGameObjects.h"
//derive class from base class VisibleGameObjects but only using the public members
class PaddlePlayer :
	public VisibleGameObject
{
public:
	PaddlePlayer();
	~PaddlePlayer();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	// Determine (max)speed and direction of paddles
	float _velocity = 0.0f; // -- is up ++ is down
	float _maxVelocity = 120.0f;
};