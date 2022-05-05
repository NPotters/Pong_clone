#include "VisibleGameObjects.h"

VisibleGameObject::VisibleGameObject()
{
	_isLoaded = false;
}

VisibleGameObject::~VisibleGameObject()
{

}

void VisibleGameObject::Load(std::string filename)
{
	if(_texture.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename =  filename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}
//Check if texture has been loaded, if yes draw
void VisibleGameObject::Draw(sf::RenderWindow& window)
{
	if (_isLoaded)
	{
		window.draw(_sprite);
	}
}
//Check if texture has been loaded, if yes set position
void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x,y);
	}
}