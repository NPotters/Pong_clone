#include "ObjectManager.h"
#include "Game.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{	//use std::for_each using two iterators, where one represents where to start and one where to end.
	// The third parameter is the function which is aplied once to each element in the range
	std::for_each(_gameObjects.begin(), _gameObjects.end(), ObjectDeallocator());
	//ObjectDeallocator() is a function object (functor). It can be called as if it were an function
}

void ObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
	//use map::insert to add one pair, containing the name and the  VisibleGameObject pointer (the gameobject)
	_gameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void ObjectManager::Remove(std::string name)
{ // search/iterate over the elements within a map to find a key with the defined name 
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	// if that name is in the map container before reachin the end of the iteration
	// in other words if the map contains the key, then delete.
	if (results != _gameObjects.end())
	{
		delete results->second; // deletes deletes the pointer to the VisibleGameObject* 
		_gameObjects.erase(results); //erasing by itarator, deletes the key
	}
}

VisibleGameObject* ObjectManager::Get(std::string name) const
{	// search/iterate over the elements within a map to find a key with the defined name 
	// use const_iterators when possible, due to the fact that they can not change the values that they point to
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	// see if the results iterator is equal to the end of file
	// when yes then it indicates that the iterator does not point to anything, so return NULL
	if (results == _gameObjects.end())
	{
		return NULL;
	}
	// when whithin the iteration a key with the name is found and points to something valid,
	// get the pair and return the VisibleGameObject pointer.
	return results->second;
}

int ObjectManager::GetObjectCount() const
{
	return _gameObjects.size(); // return number of elements in the map container.
}

void ObjectManager::DrawAll(sf::RenderWindow& window)
{	// loop over all the elements in the map container
	// while the end of the container is not reached, call the VisibleGameObject Draw method
	// Draws all the availble items.
	std::map<std::string, VisibleGameObject*>::const_iterator it = _gameObjects.begin();
	while (it != _gameObjects.end())
	{
		it->second->Draw(window);
		it++;
	}
}

void ObjectManager::UpdateAll()
{	// loop over all the elements in the map container
	// while the end of the container is not reached, call the VisibleGameObject Update method
	// Updates all the availble items every frame and returns the frametime.
	std::map<std::string, VisibleGameObject*>::const_iterator it = _gameObjects.begin();
	float DeltaT = clock.restart().asSeconds();

	while (it != _gameObjects.end())
	{
		it->second->Update(DeltaT);
		it++;
	}
}