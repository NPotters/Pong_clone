#pragma once
#include "stdafx.h"
class PlayMenu
{
public:
	enum PlayMenuOptions { Nothing, Play1, Play2 , Exit, GoBack};

	struct PlayMenuItem //define individual menu items
	{
	public:

		sf::Rect<int> rect; // Utility class for manipulating 2D axis aligned rectangles
		PlayMenuOptions action; // return if item is clicked
	};

	PlayMenuOptions Show(sf::RenderWindow& window);
private:
	PlayMenuOptions GetMenuResponse(sf::RenderWindow& window);
	PlayMenuOptions Handleclick(int x, int y);
	std::list<PlayMenuItem> _playMenuItems; //list of menuitems
};