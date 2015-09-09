/**
* Project AntAi
* @author Phillip
* @version 1.0.0
*/


#include "CreatureMap.h"

/**
* Agent implementation
*/

CreatureMap::CreatureMap()
{
}

CreatureMap::CreatureMap(int width, int height)
{
	this->width = width;
	this->height = height;
	// Initialise the vectors to the correct lengths.
	map.resize(width);
	for (int i = 0; i < width; i++) {
		map[i].resize(height);
	}
}

int CreatureMap::getWidth()
{
	return width;
}

int CreatureMap::getHeight()
{
	return height;
}

std::vector<int> CreatureMap::getVector(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		return map[x][y];
	return std::vector<int> {};
}

void CreatureMap::saveVector(int x, int y, std::vector<int> vector)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		map[x][y] = vector;
}
