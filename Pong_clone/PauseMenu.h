#pragma once
#include "stdafx.h"
class PauseMenu
{
public:
	enum PauseMenuOptions { Nothing, Return, Exit};

	struct PauseMenuItem //define individual menu items
	{
	public:

		sf::Rect<int> rect; // Utility class for manipulating 2D axis aligned rectangles
		PauseMenuOptions action; // return if item is clicked
	};

	PauseMenuOptions Show(sf::RenderWindow& window);
private:
	PauseMenuOptions GetMenuResponse(sf::RenderWindow& window);
	std::list<PauseMenuItem> _pausemenuItems; //list of menuitems
};