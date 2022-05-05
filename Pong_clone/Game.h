#pragma once
#include "stdafx.h"

class Game
{

public:
    static void Start();

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
    static sf::RenderWindow window;
};