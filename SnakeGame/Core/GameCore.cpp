#include "GameCore.h"

#include <conio.h>
#include <iostream>
#include <mutex>
#include <Windows.h>
#include <thread>

#include "ScoreBoard.h"
#include "UI.h"

Core::Core()
{
    // Set states
    CurrentState = EGameState::MAINMENU;
    bIsAlive = false;

    snake = new Snake({map.GetMapSize().X / 2, map.GetMapSize().Y / 2}); // Spawn snake in the middle
    fruit = new Fruit();
    ui = new UI();
}

void Core::InitGame()
{
    Update();
}

void Core::Update()
{
    system("cls");
    while (true)
    {
        // Сhecks the status for next actions
        switch (CurrentState)
        {
        //Main menu loop
        case EGameState::MAINMENU:
            MainMenuLoop();
        case EGameState::GAME:
            GameLoop();
        case EGameState::ENDGAME:
            EndGameLoop();
        }
    }
}


void Core::ClearConsole()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Core::SetupSnakeInput()
{
    snake->SetupInput(); // Configure input
    snake->Move(); // Moves snake
}

void Core::OnCollisionOverlap()
{
    GameCoord Location = snake->GetHeadLocation();

    if (Location.X == map.GetMapSize().X || Location.X == 0 || Location.Y == map.GetMapSize().Y || Location.Y == 0)
    // Border collision
    {
        bIsAlive = false;
    }

    for (int i = 1; i <= ui->GetScoreBoard()->GetCurrentScore() / 10; i++) // Snake tail collision
    {
        if (snake->GetSnakeTailLocation(i).X == Location.X && snake->GetSnakeTailLocation(i).Y == Location.Y)
        {
            bIsAlive = false;
        }
    }

    if (fruit->GetFruitLocation().X == Location.X && fruit->GetFruitLocation().Y == Location.Y) // Fruit collision
    {
        snake->Grow({fruit->GetFruitLocation().X, fruit->GetFruitLocation().Y}); // Increase snake by 1 and set location
        fruit->Spawn(map.GetMapSize()); // Spawn new fruit;
        ui->GetScoreBoard()->OnPointsChanged(fruit->GetScore()); // Change points by +10
    }
}

void Core::MainMenuLoop()
{
    while (CurrentState == EGameState::MAINMENU)
    {
        ClearConsole();
        ui->ShowMainMenu();

        if (_kbhit())
        {
            switch (_getch())
            {
            case '1': // '1' - Start game
                bIsAlive = true;
                CurrentState = EGameState::GAME;
                ClearConsole();
                break;
            case '2': // '2' - Show record score
                ui->ShowScore(true);
                break;
            case '3': ui->Close(); // '3' - Close game
                break;
            }
        }
    }
}

void Core::GameLoop()
{
    std::mutex _mutex;
    while (bIsAlive && CurrentState == EGameState::GAME) // Game loop
    {
        ClearConsole();

        map.DrawMap(*snake, fruit->GetFruitLocation()); // Draw map, snake and fruits

        std::thread CollisionThread(&Core::OnCollisionOverlap, this);
        CollisionThread.join();

        std::thread InputThread(&Core::SetupSnakeInput, this);
        InputThread.join();

        std::this_thread::sleep_for(std::chrono::milliseconds(65)); // Snake speed

        ui->ShowScore(false); // Shows in game score menu
    }
}

void Core::EndGameLoop()
{
    if (!bIsAlive)
    {
        ClearConsole();

        ui->ShowEndMenu(); // Shows eng menu

        if (_kbhit())
        {
            switch (_getch())
            {
            case '1': // '1' - New Game
                ui->GetScoreBoard()->ResetScore(); // Reset score

                bIsAlive = true;
                CurrentState = EGameState::GAME;

                snake->Reset({map.GetMapSize().X / 2, map.GetMapSize().Y / 2}); // Reset snakes location
                break;
            case '2': ui->Close(); // '2' - Close game
                break;
            }
        }
    }
}

Core::~Core()
{
    delete snake;
    delete fruit;
    delete ui;
}
