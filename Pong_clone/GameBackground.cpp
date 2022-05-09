#include "GameBackground.h"
GameBackground::GameBackground()
{
	Load("./Files/background_Game.png");
	assert(IsLoaded());
}
GameBackground::~GameBackground()
{

}