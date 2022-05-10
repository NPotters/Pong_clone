#pragma once
#include "VisibleGameObjects.h"
#include "ObjectManager.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Add(std::string name, VisibleGameObject* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& window);
	void UpdateAll();

private:
	// Use map to create a collection of key(std::string) and value(VisibleGameObject) pairs,
	// in order to look up and  and retrieve values based on the key.
	// Meaning each item in the map consits of an identifier and the data.
	// Here the identifier is the std::string and the data is the VisibleGameObject pointer.
	std::map<std::string, VisibleGameObject*> _gameObjects; 
	sf::Clock clock;
	//const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	//sf::Time timeSinceLastUpdate = sf::Time::Zero;

	//The ObjectDeallocator deletes the VisibleGameObject pointer.
	//When the ObjectManager is destroyed or out of scope, it deletes all the memory of the itemns it contains.
	struct ObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*>& p) const // use & p, to reference to an object, here to a const pair.
		{
			delete p.second;//remove second stored value (of the pair), here the VisibleGameObject pointer
		}
	};
};