#pragma once
#include "stdafx.h"
class Menu
{
public:
	enum MenuOptions {Nothing, Exit, Play};

	struct MenuItem //define individual menu items
		{
		public:

		sf::Rect<int> rect; // Utility class for manipulating 2D axis aligned rectangles
		MenuOptions action; // return if item is clicked
		};

	MenuOptions Show(sf::RenderWindow& window);
private:
	MenuOptions GetMenuResponse(sf::RenderWindow& window);
	MenuOptions Handleclick(int x, int y);
	std::list<MenuItem> _menuItems; //list of menuitems
};