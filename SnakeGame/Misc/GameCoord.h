#pragma once

struct GameCoord
{
public:
    int X;
    int Y;

    friend bool operator==(const GameCoord& l, const GameCoord& r)
    {
        return l.X == r.X && l.Y == r.Y;
    }
};
