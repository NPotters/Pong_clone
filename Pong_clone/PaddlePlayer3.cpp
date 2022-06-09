#include "PaddlePlayer3.h"
#include "Game.h"
#include "Ball.h"
//default member initializer velocity = 0 and maxVelocity = 600.0f
// use f after value to tell compiler it is a float not a double.
PaddlePlayer3::PaddlePlayer3() : _velocity(0), _maxVelocity(240.0f)
{
	Load("./Files/PaddlePlayer2.png");
	//assert checks if its argument compares equal to zero.
	//If it does, assert outputs implementation-specific diagnostic information on the standard error output and calls std::abort.
	assert(IsLoaded());
	// set origin of sprite to center
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
}

PaddlePlayer3::~PaddlePlayer3()
{

}

void PaddlePlayer3::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

float PaddlePlayer3::GetVelocity()const
{
	return _velocity;
}
// Update is called every frame and is passed the elapesed period since the last frame of graphics was drawn.
void PaddlePlayer3::Update(float elapsedTime)
{// define the speed and direction of the paddle
	//-----------------------------------------------------------------//
	 //                        Define the AI of Paddle                  //
	//-----------------------------------------------------------------//
	const Ball* gameball = static_cast<Ball*>
		(Game::GetGameObjectManager().Get("Ball"));

	sf::Vector2f ballPosition = gameball->GetPosition();
	if ((GetPosition().y  < ballPosition.y)
		&& (GetPosition().y > (Game::SCREEN_HEIGHT - Game::BORDER_OFFSET - (GetSprite().getLocalBounds().height)/2.0f) - 35.0f))
	{
		_velocity = 0.0f;
	}
	else if ((GetPosition().y > ballPosition.y)
		&& (GetPosition().y < (Game::BORDER_OFFSET + (GetSprite().getLocalBounds().height)/2.0f) + 35.0f))
	{
		_velocity = 0.0f;
	}

	else if ((GetPosition().y + (GetSprite().getLocalBounds().height) / 2.0f) < ballPosition.y)
	{
		_velocity += 30.0f;
	}
	else if ((GetPosition().y - (GetSprite().getLocalBounds().height) / 2.0f) > ballPosition.y)
	{
		_velocity -= 30.0f;
	}

	

	else
	{
		_velocity = 0.0f;
	}

	//----------------------------------------------------------------//
	
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_velocity += 30.0f;//pixels per second

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_velocity -= 30.0f;

	}
	//create a "break" for our speeding paddle
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_velocity = 0.0f;

	}

	if (_velocity > _maxVelocity)
	{
		_velocity = _maxVelocity;

	}
	if (_velocity < -_maxVelocity)
	{
		_velocity = -_maxVelocity;

	}*/
	//Set Outer bounds
	sf::Vector2f pos = this->GetPosition();
	if (pos.y < (Game::BORDER_OFFSET + (GetSprite().getLocalBounds().height / 2))
		|| pos.y >(Game::SCREEN_HEIGHT - Game::BORDER_OFFSET - (GetSprite().getLocalBounds().height / 2)))
	{
		_velocity = -_velocity; // Bounce by current velocity in opposite direction

	}
	// add funtion, so the movement is not framerate dependent.
	// velocity= pixels/second and elapsedTime(seconds/updates) is inversed framerate, 
	//thus when multiplying by the framerate one gets the velocity.
	GetSprite().move(0.f, _velocity * elapsedTime);
}
