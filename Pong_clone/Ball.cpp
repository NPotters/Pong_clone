#include "Ball.h"
Ball::Ball() 
{
	Load("./Files/Ball_Start.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
}
Ball::~Ball()
{

}