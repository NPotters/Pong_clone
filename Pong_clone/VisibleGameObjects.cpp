#include "VisibleGameObjects.h"
//Constructo is invoked  when initialization takes place, and they are selected according to the rules of initialization
// Here the initialization rule or the  default member initializer is  _isLoaded(flase)
VisibleGameObject::VisibleGameObject() : _isLoaded(false)
{

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
void VisibleGameObject::Update(float elapsedTime)
{

}

//Check if texture has been loaded, if yes set position
void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x,y);
	}
}
//Check if texture has been loaded, if yes get position
sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}
//allow subclasses get access to the _sprite sf::Sprite object.
sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}