#include "Fruit.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

Fruit::Fruit()
{
    srand(time(NULL));
    ScoreValue = 10;
    FruitSpawnLocation.X = 10 + rand() % 10;
    FruitSpawnLocation.Y = 5 + rand() % 15;
}

void Fruit::Destroy()
{
    std::cout << "";
    FruitSpawnLocation = {0, 0};
}

GameCoord Fruit::Spawn(GameCoord Location)
{
    srand(time(NULL));
    FruitSpawnLocation.X = rand() % (Location.X - 2) + 1;
    FruitSpawnLocation.Y = rand() % (Location.Y - 2) + 1;

    return FruitSpawnLocation;
}