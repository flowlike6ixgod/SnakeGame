#pragma once
#include <vector>
#include "Snake.h"
#include "Fruit.h"

class Map
{
public:
	Map();

private:

	/* Map size in X and Y axis */
	GameCoord MapSize = {60, 25};

	/* Map field */
	std::vector<std::vector<GameCoord>> Vec2;

public:
	/** Draws the map
	 * @param snake - reference to snake object
	 * @param fruitLoc - reference to fruit location
	 */
	void DrawMap(Snake& snake, const GameCoord& fruitLoc);

	/* Return map size in X and Y */
	GameCoord GetMapSize() const { return MapSize; }

};

