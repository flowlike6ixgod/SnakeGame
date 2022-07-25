#include "Snake.h"
#include <conio.h>
#include <iostream>
#include <thread>

#include "Fruit.h"

Snake::Snake(GameCoord Location)
{
    // Setup cur location
    CurrentDirection = EDirection::NONE;

    // Init snake and add the tail
    SnakeTail.clear();
    SnakeTail.push_back(Location);
    SnakeTail.push_back(Location);
}

GameCoord Snake::GetSnakeTailLocation(int Position) const
{
    return SnakeTail[Position];
}

void Snake::SetupInput()
{
    // checks if keboard hit
    if (_kbhit())
    {
        // waiting input char
        switch (_getch())
        {
        case 'w':
        case 'W': if (CurrentDirection != EDirection::DOWN) { CurrentDirection = EDirection::UP; }
            break;
        case 'a':
        case 'A': if (CurrentDirection != EDirection::RIGHT) { CurrentDirection = EDirection::LEFT; }
            break;
        case 's':
        case 'S': if (CurrentDirection != EDirection::UP) { CurrentDirection = EDirection::DOWN; }
            break;
        case 'd':
        case 'D': if (CurrentDirection != EDirection::LEFT) { CurrentDirection = EDirection::RIGHT; }
            break;
        }
    }
}

void Snake::Move()
{
    // Tail follows head
    for (int i = 1; i < SnakeTail.size(); i++)
    {
        SnakeTail[i - 1] = SnakeTail[i];
    }
    // Change dir depending from CurrentDirection
    switch (CurrentDirection)
    {
    case EDirection::UP: SnakeTail[SnakeTail.size() - 1].Y--;
        break;
    case EDirection::LEFT: SnakeTail[SnakeTail.size() - 1].X--;
        break;
    case EDirection::DOWN: SnakeTail[SnakeTail.size() - 1].Y++;
        break;
    case EDirection::RIGHT: SnakeTail[SnakeTail.size() - 1].X++;
        break;
    }
}

void Snake::Grow(const GameCoord& NewCoord)
{
    // insert new element with new coordinates
    SnakeTail.insert(SnakeTail.begin(), NewCoord);
}

void Snake::Reset(GameCoord StartLocation)
{
    CurrentDirection = EDirection::NONE;
    // Init snake and add the tail
    SnakeTail.clear();
    SnakeTail.push_back(StartLocation);
    SnakeTail.push_back(StartLocation);
}


void Snake::DrawSnake(const int& X, const int& Y)
{
    bool print = false;
    // iterate over snakes size
    for (int k = 0; k < GetSnakeTailSize(); k++)
    {
        // setup snakes head and in the centre of map
        if (GetSnakeTailLocation(k).X == X && GetSnakeTailLocation(k).Y == Y)
        {
            // this variable controls the drawing spaces
            if (k == GetSnakeTailSize() - 1)
            {
                std::cout << "O"; // Head
                print = true;
            }
            else
            {
                std::cout << "o"; //Body
                print = true;
            }
        }
    }
    if (!print) // fill other space
    {
        std::cout << " ";
    }
}
