#pragma once
#include "stdafx.h"
#include "PaddlePlayer.h"
#include "PaddlePlayer2.h"
#include "ObjectManager.h"
#include "Ball.h"
#include "GameBackground.h"

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


private:
    static bool IsExiting();
    static void GameLoop();

    static void ShowStartScreen();
    static void ShowMenu();
    
    enum GameState {
        Uninitialized, StartScreen, Paused,
        ShowingMenu, Playing, Exiting
    };

    static GameState _gameState;
    static sf::RenderWindow _window;
    static ObjectManager _ObjectManager;
};