#include "Game.h"
#include "Startscreen.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "PlayMenu.h"
#include "Winscreen.h"
#include "GameBackground.h"

#include "PaddlePlayer.h"
#include "PaddlePlayer3.h"
#include "PaddlePlayer2.h"
#include "Ball.h"
#include "Score.h"


//#include "VisibleGameObjects.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
{

}
Game::~Game()
{

}
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

	/////////Object Manager///////////////////
	_ObjectManager.Add("Background",background);
	
	
	////////playing state/////////////////////
	_gameState = Game::StartScreen;

	timeSinceLastUpdate = sf::Time::Zero;

	while (!IsExiting()) {
		
			timeSinceLastUpdate = clock.getElapsedTime();
			float timeSinceLastUpdate_sec = timeSinceLastUpdate.asSeconds();

			//while (timeSinceLastUpdate > TimePerFrame)
			//{
				//timeSinceLastUpdate -= TimePerFrame;
				//float  TimeUpdate_sec = timeSinceLastUpdate.asSeconds();
				float  TimePerFrame_sec = TimePerFrame.asSeconds();
				//float fps = 1.f / TimePerFrame_sec;
				//std::cout << TimePerFrame_sec << std::endl;

				GameLoop();
				if (!Pause()) {
					GameUpdate(TimePerFrame_sec);
				}
			//}
			render();
			//std::cout << timeSinceLastUpdate_sec << std::endl;
	}
	_window.close();
}

void Game::render()
{
	switch (_gameState) {
		case Game::ShowingMenu:
		{
		
			_ObjectManager.Remove("Score");
			_ObjectManager.Remove("ScoreN");
			_ObjectManager.Remove("Paddle2");
			_ObjectManager.Remove("Paddle3");
			_ObjectManager.Remove("Paddle1");
			_ObjectManager.Remove("Ball");
			break;
		}
		case Game::GameMode:
		{
			//// Score////////////////
			Score* score = new Score();
			ScoreN* scoreN = new ScoreN();

			//Ball /////
			Ball* ball = new Ball();
			ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));

			///Paddle Player//////
			PaddlePlayer* player1 = new PaddlePlayer();
			player1->SetPosition(OFFSET_Paddle, SCREEN_HEIGHT / 2);
			PaddlePlayer2* player2 = new PaddlePlayer2();
			player2->SetPosition((SCREEN_WIDTH - OFFSET_Paddle), SCREEN_HEIGHT / 2);

			//Paddle AI////
			PaddlePlayer3* player3 = new PaddlePlayer3();
			player3->SetPosition((SCREEN_WIDTH - OFFSET_Paddle), SCREEN_HEIGHT / 2);


			

			_ObjectManager.Add("Score", score);
			_ObjectManager.Add("ScoreN", scoreN);

			_ObjectManager.Add("Ball", ball);

			_ObjectManager.Add("Paddle1", player1);
			_ObjectManager.Add("Paddle3", player3);
			_ObjectManager.Add("Paddle2", player2);
			
			
			
			break;
		}
		case Game::Playing:
		{
			_ObjectManager.Remove("Paddle2");
			_window.clear();
			_ObjectManager.DrawAll(_window);
			_window.display();
			break;
		}
		case Game::Playing2:
		{
			_ObjectManager.Remove("Paddle3");
			_window.clear();
			_ObjectManager.DrawAll(_window);
			_window.display();
			break;
		}
	}
}
void Game::GameUpdate(float deltaTime)
{
	switch (_gameState) {
		case Game::ShowingMenu:
		{
			//_ObjectManager.UpdateAll(0.0f);
			//timeSinceLastUpdate = sf::Time::Zero;
			//_ObjectManager.UpdateAll(deltaTime);
			
			break;
		}
		case Game::GameMode:
		{
			//timeSinceLastUpdate = sf::Time::Zero;
			//_ObjectManager.UpdateAll(0.0f);
			//_ObjectManager.UpdateAll(deltaTime);
			//timeSinceLastUpdate = clock.restart();
			break;
		}
		case Game::Paused:
		{
			//timeSinceLastUpdate = sf::Time::Zero;
			//_ObjectManager.UpdateAll(0.0f);
			//_ObjectManager.UpdateAll(deltaTime);
			//timeSinceLastUpdate = clock.restart();
			break;
		}
		case Game::Playing:
		{
			
			_ObjectManager.UpdateAll(deltaTime);
			if (_n == 10 || _p == 10)
			{
				ShowWinScreen();
			}
			break;
		}
		case Game::Playing2:
		{
			_ObjectManager.UpdateAll(deltaTime);
			if (_n == 10 || _p == 10)
			{
				ShowWinScreen();
			}
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
bool Game::Pause() {

	if (_gameState == Game::Paused)
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
	//int _updateN = _n;
	//int _updateP = _p;
	
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
			case Game::Paused:
			{
				ShowPauseMenu();
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
					if (event.key.code == sf::Keyboard::Space)
					{
						ShowPauseMenu();
					}

				}
				if (_n == 10 || _p == 10)
				{
					ShowWinScreen();
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
				if (event.key.code == sf::Keyboard::Space)
				{
					ShowPauseMenu();
				}

			}
			if (_n == 10 || _p == 10)
			{
				ShowWinScreen();
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
/////////////////Win screen////////////////
void Game::ShowWinScreen()
{
	Winscreen winscreen; // create obj of class
	winscreen.Show(_window);
	_gameState = Game::Exiting;
}
void Game::ShowMenu()
{
	//PinkGlow* glowpink = new PinkGlow();
	//BlueGlow* glowblue = new BlueGlow();

	/////////Object Manager///////////////////
	
	//VisibleGameObject _load;
	Menu Menuscreen; // create obj of class
	Menu::MenuOptions option = Menuscreen.Show(_window);
	switch (option)
	{
	case Menu::Exit:
		//_ObjectManager.Remove("Glowblue");
		_gameState = Game::Exiting;
		break;
	case Menu::Play:
		//_ObjectManager.Remove("Glowpink");
		_gameState = Game::GameMode;
		break;
	case Menu::Nothing:
		//_ObjectManager.Remove("Glowpink");
		//_ObjectManager.Remove("Glowblue");
		ShowMenu();
		break;

	/*case Menu::LoadPlay:
		//_ObjectManager.Add("Glowpink", glowpink);

		//_load.Load("./Files/Pause_Menu.png");
		//_load.Draw();
		break;
	case Menu::LoadExit:
		//_ObjectManager.Add("Glowblue", glowblue);

		//_load.Load("./Files/Pause_Menu.png");
		break;*/

	}
}
void Game::ShowPauseMenu()
{
	PauseMenu PauseMenuscreen; // create obj of class
	PauseMenu::PauseMenuOptions Pauseoption = PauseMenuscreen.Show(_window);
	switch (Pauseoption)
	{
	case PauseMenu::Return:
		if (Game::GetGameObjectManager().Get("Paddle2") != NULL)
		{
			_gameState = Game::Playing2;
		}
		//if (Game::GetGameObjectManager().Get("AIPaddle") != NULL)
		else
		{
			_gameState = Game::Playing;
		}
		break;
	case PauseMenu::Nothing:
		ShowPauseMenu();
		break;
	case PauseMenu::Exit:
		_gameState = Game::Exiting;
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

sf::Time Game::timeSinceLastUpdate;
sf::Clock Game::clock;
sf::RenderWindow Game::_window;
Game::GameState Game::_gameState = Uninitialized;
ObjectManager Game::_ObjectManager;
 