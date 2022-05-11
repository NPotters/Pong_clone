#include "Ball.h"
Ball::Ball() : _velocity(230.0f), _elapsedTimeSinceStart(0.0f)
{
	Load("./Files/Ball_Start.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
	/* initialize random seed: */
	//srand(time(NULL));
	// random number between 1 and 360
	float random_float = (float)(std::rand() % 360 + 1);
	_angle = random_float;
}
Ball::~Ball()
{

}

void Ball::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;

	// Delay Game from starting imediatly
	if (_elapsedTimeSinceStart < 3.0f)
	{
		return;
	}
	
	float Displacement = _velocity * elapsedTime;


	float DisplacementX = LinearVelocityX(_angle) * Displacement;
	float DisplacementY = LinearVelocityY(_angle) * Displacement;

	//if the ball collides with the upper or bottom border, bounce.
	if(GetPosition().y + DisplacementY <= Game::BORDER_OFFSET + (GetHeight() / 2)
		|| GetPosition().y + DisplacementY >= Game::SCREEN_HEIGHT - Game::BORDER_OFFSET - (GetHeight()/2))
	{
		//Bounce angle
		_angle = 180.0f - _angle;
		// assure that the ball does not get stuck.
		//if (_angle > 260.0f && _angle < 280.0f) _angle += 20.0f;
		if (_angle > 80.0f && _angle < 100.0f) _angle += 20.0f;
		// Bounce Direction
		DisplacementY = -DisplacementY;
	}

	////////Bounce wall x
	if (GetPosition().x + DisplacementX >=  Game::SCREEN_WIDTH - Game::BORDER_OFFSET - (GetWidth() / 2))
	{
		_angle = 360 - _angle;
		DisplacementX = -DisplacementX;
	}
	///Ball out of bounds
	if (GetPosition().x + DisplacementX <= Game::BORDER_OFFSET + (GetWidth() / 2))
	{
		//move ball to midlle
		GetSprite().setPosition((Game::SCREEN_WIDTH / 2), (Game::SCREEN_HEIGHT / 2));
		_angle = (float)((rand()%360)+1);
		_velocity = 230.0f;
		_elapsedTimeSinceStart = 0.0f;
		
	}

	////Interaction PlayerPaddle1
	// use dynamic cast to return a pointer to our game PlayerPaddle object
	//We call Get() on our GameObjectManager looking for a VisibleGameObject named “Paddle1”. 
	//If dynamic_cast<> not able to cast, it will return NULL
	PaddlePlayer* player1 = dynamic_cast<PaddlePlayer*>(Game::GetGameObjectManager().Get("Paddle1"));
	if (player1 != NULL)
	{
		sf::Rect<float> p1Bound = player1->GetBoundingRect();
		//check intersection of two rectangles
		if (p1Bound.intersects(GetBoundingRect()))
		{
			_angle = 180.0f - (_angle - 180.0f);
			if (_angle > 360.0f) _angle -= 360.0f;

			DisplacementX = -DisplacementX;

			///Make sure ball is not inside paddle
			if (GetBoundingRect().left < (player1->GetBoundingRect().left + player1->GetBoundingRect().width))
			{
				SetPosition(player1->GetBoundingRect().left + player1->GetBoundingRect().width + (GetWidth() / 2) + 1.0f, GetPosition().y);
			}
			//Addvelocity when hit by paddle
			float VelocityPaddle1 = player1->GetVelocity();
			if (VelocityPaddle1 < 0)
			{
				//moving up
				_angle -= 10.0f; // add angle due to movement
				if (_angle < 0) _angle = 360.0f - _angle;
			}
			else if (VelocityPaddle1 > 0)
			{
				_angle += 10.0f;
				if (_angle > 360.0f) _angle -= 360.0f;
			}
			//add Velocity inficted by paddle
			_velocity += 50.0f;
		}
		
	}


	////Interaction PlayerPaddle2
	// use dynamic cast to return a pointer to our game PlayerPaddle object
	//We call Get() on our GameObjectManager looking for a VisibleGameObject named “Paddle2”. 
	//If dynamic_cast<> not able to cast, it will return NULL
	PaddlePlayer2* player2 = dynamic_cast<PaddlePlayer2*>(Game::GetGameObjectManager().Get("Paddle2"));
	if (player2 != NULL)
	{
		sf::Rect<float> p2Bound = player2->GetBoundingRect();
		//check intersection of two rectangles
		if (p2Bound.intersects(GetBoundingRect()))
		{
			_angle = 180.0f - (_angle - 180.0f);
			if (_angle > 360.0f) _angle -= 360.0f;

			DisplacementX = -DisplacementX;

			///Make sure ball is not inside paddle
			if ((GetBoundingRect().left + GetBoundingRect().width) < (player2->GetBoundingRect().left))
			{
				SetPosition(player2->GetBoundingRect().left - (GetWidth() / 2) - 1.0f, GetPosition().y);
			}
			//Add angle when paddle hits ball
			float VelocityPaddle2 = player2->GetVelocity();
			if (VelocityPaddle2 > 0)
			{
				//moving up
				_angle -= 10.0f; // add angle due to movement
				if (_angle < 0) _angle = 360.0f - _angle;
			}
			else if (VelocityPaddle2 < 0)
			{
				_angle += 10.0f;
				if (_angle > 360.0f) _angle -= 360.0f;
			}
			//add Velocity inficted by paddle
			_velocity += 50.0f;
		}

	}
	
	GetSprite().move(DisplacementX, DisplacementY);

}
float Ball::LinearVelocityX(float angle)
{
	angle -= 90;
	// ensure the value is always within the 360 range
	if (angle < 0) angle = 360 + angle;
	return (float)std::cos(angle * (pi / 180.0f));

}
float Ball::LinearVelocityY(float angle)
{
	angle -= 90;
	// ensure the value is always within the 360 range
	if (angle < 0) angle = 360 + angle;
	return (float)std::sin(angle * (pi / 180.0f));

}