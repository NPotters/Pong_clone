#include "GameBackground.h"
GameBackground::GameBackground()
{
	Load("./Files/background_Game.png");
	assert(IsLoaded());
}
GameBackground::~GameBackground()
{

}

/*PinkGlow::PinkGlow()
{
	Load("./Files/Glow_Pink.png");
	assert(IsLoaded());
}
PinkGlow::~PinkGlow()
{

}

BlueGlow::BlueGlow()
{
	Load("./Files/Glow_Blue.png");
	assert(IsLoaded());
}
BlueGlow::~BlueGlow()
{

}*/