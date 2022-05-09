#include "PaddlePlayer2.h"
#include "Game.h"
//default member initializer velocity = 0 and maxVelocity = 600.0f
// use f after value to tell compiler it is a float not a double.
PaddlePlayer2::PaddlePlayer2() : _velocity(0), _maxVelocity(120.0f)
{
	Load("./Files/PaddlePlayer2.png");
	//assert checks if its argument compares equal to zero.
	//If it does, assert outputs implementation-specific diagnostic information on the standard error output and calls std::abort.
	assert(IsLoaded());
	// set origin of sprite to center
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
}

PaddlePlayer2::~PaddlePlayer2()
{

}

void PaddlePlayer2::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

float PaddlePlayer2::GetVelocity()const
{
	return _velocity;
}
// Update is called every frame and is passed the elapesed period since the last frame of graphics was drawn.
void PaddlePlayer2::Update(float elapsedTime)
{// define the speed and direction of the paddle
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity += 3.0f;//pixels per second
		GetSprite().move(0, _velocity * elapsedTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_velocity -= 3.0f;
		GetSprite().move(0, _velocity * elapsedTime);
	}
	//create a "break" for our speeding paddle
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_velocity = 0.0f;
		GetSprite().move(0, _velocity * elapsedTime);
	}

	if (_velocity > _maxVelocity)
	{
		_velocity = _maxVelocity;
		GetSprite().move(0, _velocity * elapsedTime);
	}
	if (_velocity < -_maxVelocity)
	{
		_velocity = -_maxVelocity;
		GetSprite().move(0, _velocity * elapsedTime);
	}
	//Set Outer bounds
	sf::Vector2f pos = this->GetPosition();
	if (pos.y < (Game::BORDER_OFFSET + (GetSprite().getLocalBounds().height / 2))
		|| pos.y >(Game::SCREEN_HEIGHT - Game::BORDER_OFFSET - (GetSprite().getLocalBounds().height / 2)))
	{
		_velocity = -_velocity; // Bounce by current velocity in opposite direction
		GetSprite().move(0, _velocity * elapsedTime);
	}
	// add funtion, so the movement is not framerate dependent.
	// velocity= pixels/second and elapsedTime(seconds/updates) is inversed framerate, 
	//thus when multiplying by the framerate one gets the velocity.
	
}