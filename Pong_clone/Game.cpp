#include "Game.h"
#include "Startscreen.h"
#include "Menu.h"


void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;


	auto dimension = sf::VideoMode(1920, 1080);
	auto title = "Space Pong";

	window.create(dimension, title);
	window.setFramerateLimit(60);

	// Use PaddlePlayer is created dynamically and passed to _gameObjectManager to manage using the .Add() function
	//
	///Background///////
	PaddlePlayer* background = new PaddlePlayer();
	background->Load("./Files/background_Game.png");
	///Paddle Player//////
	PaddlePlayer* player1 = new PaddlePlayer();
	player1->Load("./Files/PaddlePlayer1.png");
	player1->SetPosition( 100, 100 );
	PaddlePlayer* player2 = new PaddlePlayer();
	player2->Load("./Files/PaddlePlayer2.png");
	player2->SetPosition(1772, 707);

	/////////Object Manager///////////////////
	_ObjectManager.Add("Background",background);
	_ObjectManager.Add("Paddle1", player1);
	_ObjectManager.Add("Paddle2", player2);
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
				float radius = 100.0;
				circle.setRadius(radius);
				circle.setFillColor(sf::Color(0, 255, 0));
				circle.setPosition(640, 360);
				circle.setOrigin(radius, radius);
				auto position = sf::Mouse::getPosition(window);
				circle.setPosition(sf::Vector2f(position.x, position.y));
				window.clear();
				_ObjectManager.DrawAll(window);
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
ObjectManager Game::_ObjectManager;
 