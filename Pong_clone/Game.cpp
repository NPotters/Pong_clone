#include "Game.h"
#include "Startscreen.h"
#include "Menu.h"
#include "PlayMenu.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;


	auto dimension = sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT,32);
	auto title = "Space Pong";

	_window.create(dimension, title);
	_window.setFramerateLimit(60);


	
	///Background///////
	GameBackground* background = new GameBackground();

	//Ball /////
	Ball* ball = new Ball();
	ball->SetPosition((SCREEN_WIDTH/2), (SCREEN_HEIGHT / 2));

	///Paddle Player//////
	PaddlePlayer* player1 = new PaddlePlayer();
	player1->SetPosition( OFFSET_Paddle, SCREEN_HEIGHT/2);
	
	
	/////////Object Manager///////////////////
	_ObjectManager.Add("Background",background);
	_ObjectManager.Add("Ball", ball);
	_ObjectManager.Add("Paddle1", player1);
	
	
	////////playing state/////////////////////
	_gameState = Game::StartScreen;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	

	while (!IsExiting()){

		timeSinceLastUpdate += clock.restart();
		//float timeSinceLastUpdate_sec = timeSinceLastUpdate.asSeconds();
		
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			float  TimePerFrame_sec = TimePerFrame.asSeconds();
			//float fps = 1.f / TimePerFrame_sec;
			//std::cout << fps<< std::endl;
			GameLoop();
			GameUpdate(TimePerFrame_sec);
		}
		render();
		
	}
	_window.close();
}

void Game::render()
{
	switch (_gameState) {
		case Game::Playing:
		{

			_window.clear();
			_ObjectManager.Remove("Paddle2");
			_ObjectManager.DrawAll(_window);

			_window.display();
			break;
		}
		case Game::Playing2:
		{
			PaddlePlayer2* player2 = new PaddlePlayer2();
			player2->SetPosition((SCREEN_WIDTH - OFFSET_Paddle), SCREEN_HEIGHT / 2);
			_window.clear();
			_ObjectManager.Add("Paddle2", player2);
			_ObjectManager.DrawAll(_window);

			_window.display();
			break;
		}
	}
}
void Game::GameUpdate(float deltaTime)
{
	switch (_gameState) {
		case Game::Playing:
		{
			_ObjectManager.UpdateAll(deltaTime);
			break;
		}
		case Game::Playing2:
		{
			_ObjectManager.UpdateAll(deltaTime);
			break;
		}
	}
	
}

//////test if exiting or playing/////
bool Game::IsExiting(){

		if (_gameState == Game::Exiting)
			return true;
		else
			return false;

	}
/*///// input function/////
const sf::Event& Game::GetInput()
{
	sf::Event currentEvent;
	window.pollEvent(currentEvent);
	return currentEvent;
}*/

const ObjectManager& Game::GetGameObjectManager()
{
	return Game::_ObjectManager;
}


sf::RenderWindow& Game::GetWindow()
{
	return _window;
}


/////////Define Gameloop///////////////
//sf::Clock mainclock;
void Game::GameLoop()
{
	sf::Event event;

	while (_window.pollEvent(event)) 
	{

		switch (_gameState) 
		{
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
			case Game::GameMode:
			{
				ShowPlayMenu();
				break;
			}
			case Game::Playing:
			{

				

				if (event.type == sf::Event::Closed)
				{
				_gameState = Game::Exiting;
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
					ShowMenu();
					}
				}
				break;
			}
			case Game::Playing2:
			{

				if (event.type == sf::Event::Closed)
				{
					_gameState = Game::Exiting;
				}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
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
	startscreen.Show(_window);
	_gameState = Game::ShowingMenu;
}
void Game::ShowMenu()
{
	Menu Menuscreen; // create obj of class
	Menu::MenuOptions option = Menuscreen.Show(_window);
	switch (option)
	{
	case Menu::Exit:
		_gameState = Game::Exiting;
		break;
	case Menu::Play:
		_gameState = Game::GameMode;
		break;
	case Menu::Nothing:
		ShowMenu();
		break;
	}
}
void Game::ShowPlayMenu()
{
	PlayMenu PlayMenuscreen; // create obj of class
	PlayMenu::PlayMenuOptions Playoption = PlayMenuscreen.Show(_window);
	switch (Playoption)
	{
	case PlayMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case PlayMenu::GoBack:
		_gameState = Game::ShowingMenu;
		break;
	case PlayMenu::Play2:
		_gameState = Game::Playing2;
		break;
	case PlayMenu::Play1:
		_gameState = Game::Playing;
		break;
	case PlayMenu::Nothing:
		ShowPlayMenu();
		break;
	}
}


	
sf::RenderWindow Game::_window;
Game::GameState Game::_gameState = Uninitialized;
ObjectManager Game::_ObjectManager;
 