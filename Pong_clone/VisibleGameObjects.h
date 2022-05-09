#pragma once
#include "stdafx.h"

class VisibleGameObject
{
public:
	VisibleGameObject(); //Constructor
	virtual ~VisibleGameObject(); //Destructor, is called when an object is deleted.

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow& window);
	virtual void Update(float elapsedTime);

	virtual void SetPosition(float x,float y);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded() const;

protected: //inacessable outside the class, can be accessed by a subclass(derived class)of the class
	// Here GetSprite can be accesed by VisibleGmaeObjects and subclass objects like PaddlePlayer. 
	sf::Sprite& GetSprite(); //Subclasses can access to the inhereted private _sprite member.

private:
	sf::Sprite _sprite; // hold the SFML Sprite class
	sf::Texture _texture; // hold the SFML Texture class
	std::string _filename; //store name of loaded image
	bool _isLoaded; //boolian set true when data Texture has been loaded
};