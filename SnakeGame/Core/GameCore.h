#pragma once
#include "Map.h"
#include "Snake.h"
#include "EnumLib.h"

class UI;

class Core
{
public:
    Core();
    ~Core();

private:
    /* map class for drawing */
    Map map;

    /* Shows game ui */
    UI* ui;

    Snake* snake;

    Fruit* fruit;

    /* Current game state */
    EGameState CurrentState;

    /* is snake alive? */
    bool bIsAlive;

public:
    /* штшешфдшяу пфьу акщь ыефке */
    void InitGame();

private:
    /* Update game every tick */
    void Update();

    /* Update console without flicking */
    static void ClearConsole();

    /** Setup input and move functionality */
    void SetupSnakeInput();

    /** Handles collision with objects */
    void OnCollisionOverlap();

    void MainMenuLoop();

    void GameLoop();

    void EndGameLoop();
};

