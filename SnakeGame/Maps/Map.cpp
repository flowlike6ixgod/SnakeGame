#include "Map.h"
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

Map::Map()
{
    //Vec2.resize(MapSize.Y, std::vector<GameCoord>(MapSize.X));
}

void Map::DrawMap(Snake& snake, const GameCoord& fruitLoc)
{
    std::cout << " Head X: " << snake.GetHeadLocation().X << "\t" << " Head Y: " << snake.GetHeadLocation().Y <<
        std::endl;

    std::cout << " Tail X: " << snake.GetSnakeTailLocation(1).X << "\t" << " Tail Y: " << snake.GetSnakeTailLocation(1).
        Y << std::endl;
    std::cout << "\n\n\n";

    // iterate over columns and rows
    for (int column = 0; column < MapSize.Y; column++)
    {
        std::cout << "\t\t\t\t";
        std::cout << "#";
        for (int row = 0; row < MapSize.X; row++)
        {
            // drawing upper border
            if (column == 0 || column == MapSize.Y - 1)
            {
                std::cout << "#";
            }
            // drawing fruit at random location
            else if (column == fruitLoc.Y && row == fruitLoc.X)
            {
                std::cout << "F";
            }
            else
            {
                snake.DrawSnake(row, column);

            }
        }
        // draw right border
        std::cout << "#" << std::endl;
    }
}
