#pragma once
#include "GameCoord.h"


class Fruit
{
protected:
    /* The number of points you get */
    int ScoreValue;

    GameCoord FruitSpawnLocation;

public:
    Fruit();
    /* Destroy item */
    void Destroy();

    /** Spawn item in random place
     * @param Location Fruit spawn location
     */
    GameCoord Spawn(GameCoord Location);

    /* Returns current fruit location */
    GameCoord GetFruitLocation() const { return FruitSpawnLocation; }

    /* Returns fruit score */
    int GetScore() const { return ScoreValue; }

};

