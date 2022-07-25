#pragma once
#include <deque>
#include "GameCoord.h"
#include "EnumLib.h"

class Snake
{
public:
    /** Init the snake location on the map */
    Snake(GameCoord Location);
    Snake();

private:
    /** Current movement direction */
    enum class EDirection CurrentDirection;

    /** Snake (the first element is the head of the snake, other elements are the snakes tail)*/
    std::deque<GameCoord> SnakeTail;

public:
    /** Returns the current location of the head */
    GameCoord GetHeadLocation() const { return SnakeTail[SnakeTail.size() - 1]; }

    /** Returns snake size */
    auto GetSnakeTailSize() const { return SnakeTail.size(); }

    /**
     *  Returns the tail of the snake.
     *  @param Position - index of the snake tail
    */
    GameCoord GetSnakeTailLocation(int Position) const;

    /** Сonfigures input buttons */
    void SetupInput();

    /** Сhanges the direction of the snake depending on the key pressed */
    void Move();

    /** increases the snake size by 1
     *  @param NewCoord coordinates where to add the tail of the snake
     */
    void Grow(const GameCoord& NewCoord);

    /** Reset the snake location on the map
     * @param StartLocation - Set snake to the middle of map
     */
    void Reset(GameCoord StartLocation);

    /** Draws the snake on the map
    * @param X position in X axis
    * @param Y position in Y axis
    */
    void DrawSnake(const int& X, const int& Y);

};



