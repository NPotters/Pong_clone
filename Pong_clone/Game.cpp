#include "Game.h"
#include "Startscreen.h"
#include "Menu.h"


void Game::Start()
{
	if (_gameState != Uninitialized)
		return;


	auto dimension = sf::VideoMode(1920, 1080);
	auto title = "Space Pong";

	window.create(dimension, title);
	window.setFramerateLimit(60);

	////////playing state/////////////////////
	_gameState = Game::StartScreen;

	while (!IsExiting()){

		GameLoop();

	}
	window.close();
}


//////test if exiting or playing/////
bool Game::IsExiting(){

		if (_gameState == Game::Exiting)
			return true;
		else
			return false;

	}
/////////Define Gameloop///////////////
void Game::GameLoop(){
	sf::Event event;

	while (window.pollEvent(event)) {

		switch (_gameState) {
			case Game::StartScreen:
			{
				ShowStartScreen();
				break;
			}
			case Game::ShowingMenu:
			{
				ShowMenu();
				break;
			}
			case Game::Playing: 
			{
				sf::CircleShape circle;
				int radius = 100;
				circle.setRadius(radius);
				circle.setFillColor(sf::Color(0, 255, 0));
				circle.setPosition(640, 360);
				circle.setOrigin(radius, radius);
				auto position = sf::Mouse::getPosition(window);
				circle.setPosition(sf::Vector2f(position.x, position.y));
				window.clear();
				window.draw(circle);
				window.display();

					if(event.type==sf::Event::Closed)
					{
						_gameState = Game::Exiting;
					}
					if (event.type == sf::Event::KeyPressed)
					{
						if(event.key.code == sf::Keyboard::Escape)
						{
							ShowMenu();
						}
					}
				break;
			}

		}
	}
}
/////////////////start screen////////////////
void Game::ShowStartScreen()
{
	Startscreen startscreen; // create obj of class
	startscreen.Show(window);
	_gameState = Game::ShowingMenu;
}
void Game::ShowMenu()
{
	Menu Menuscreen; // create obj of class
	Menu::MenuOptions option = Menuscreen.Show(window);
	switch (option)
	{
	case Menu::Exit:
		_gameState = Game::Exiting;
		break;
	case Menu::Play:
		_gameState = Game::Playing;
		break;
	case Menu::Nothing:
		ShowMenu();
		break;
	}
}


	
sf::RenderWindow Game::window;
Game::GameState Game::_gameState = Uninitialized;
 