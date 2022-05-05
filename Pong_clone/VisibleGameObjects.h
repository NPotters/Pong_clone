#pragma once
#include "stdafx.h"

class VisibleGameObject
{
public:
	VisibleGameObject(); //Constructor
	virtual ~VisibleGameObject(); //Destructor, is called when an object is deleted.

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow& window);
	virtual void SetPosition(float x,float y);

private:
	sf::Sprite _sprite; // hold the SFML Sprite class
	sf::Texture _texture; // hold the SFML Texture class
	std::string _filename; //store name of loaded image
	bool _isLoaded; //boolian set true when data Image has been loaded
};