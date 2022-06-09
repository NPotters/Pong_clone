#pragma once
#include "stdafx.h"
#include "ObjectManager.h"

class Game
{

public:
    Game();
    ~Game();
    static void Start();
    const static ObjectManager& GetGameObjectManager();
    //const static sf::Event& GetInput();
    static sf::RenderWindow& GetWindow();
    const static int SCREEN_WIDTH = 1920;
    const static int SCREEN_HEIGHT = 1080;
    const static int BORDER_OFFSET = 30;
    const static int OFFSET_Paddle = 100;
    float currentTime = 0.f;
 


private:
    static bool IsExiting();
    static bool Pause();
    static void GameLoop();
    static void GameUpdate(float deltaTime);

    static void ShowStartScreen();
    static void ShowWinScreen();
    static void ShowMenu();
    static void ShowPauseMenu();
    static void ShowPlayMenu();
    static void render();
    static const sf::Time TimePerFrame;
   // int _updateN;
   // int _updateP;
    
    
    enum GameState {
        Uninitialized, StartScreen, Paused,
        ShowingMenu, GameMode, Playing, Playing2, Exiting
    };
    static sf::Clock clock;
    static sf::Time timeSinceLastUpdate;
    static GameState _gameState;
    static sf::RenderWindow _window;
    static ObjectManager _ObjectManager;
};