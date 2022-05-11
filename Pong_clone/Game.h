#pragma once
#include "stdafx.h"
#include "GameBackground.h"
#include "PaddlePlayer.h"
#include "PaddlePlayer2.h"
#include "ObjectManager.h"
#include "Ball.h"

class Game
{

public:
    static void Start();
    //const static sf::Event& GetInput();
    static sf::RenderWindow& GetWindow();
    const static int SCREEN_WIDTH = 1920;
    const static int SCREEN_HEIGHT = 1080;
    const static int BORDER_OFFSET = 30;
    const static int OFFSET_Paddle = 100;
    float currentTime = 0.f;;
 


private:
    static bool IsExiting();
    static void GameLoop();
    static void GameUpdate(float deltaTime);

    static void ShowStartScreen();
    static void ShowMenu();
    static void ShowPlayMenu();
    static void render();
    static const sf::Time TimePerFrame;
    
    enum GameState {
        Uninitialized, StartScreen, Paused,
        ShowingMenu, GameMode, Playing, Playing2, Exiting
    };

    static GameState _gameState;
    static sf::RenderWindow _window;
    static ObjectManager _ObjectManager;
};