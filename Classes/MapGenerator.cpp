/**
* Project AntAi
* @author Oscar
* @version 1.0.0
*/


#include "MapGenerator.h"

MapGenerator::MapGenerator() {}

MapGenerator::MapGenerator(int stoneThreshold, int dirtThreshold, int smoothingSteps)
{
	this->stoneThreshold = stoneThreshold;
	this->dirtThreshold = dirtThreshold;
	this->smoothingSteps = smoothingSteps;
}

std::vector<std::vector<TileType>> MapGenerator::generateBaseMap(int width, int height)
{
	auto baseGrid = std::vector<std::vector<TileType>>();

	// Reserve memory
	baseGrid.resize(width);
	for (int x = 0; x < width; ++x) {
		// Reserve memory for each column
		baseGrid[x].resize(height);
		for (int y = 0; y < height; ++y) {
			// Define values
			/*if ((x + y) % 2 == 0) baseGrid[x][y] = TileType::stone;
			else baseGrid[x][y] = TileType::dirt;*/
			// Generate random number between 0 and 100
			int rnd = rand() % 101;
			// Assign TileType depending on the randomly generated value
			if (rnd > stoneThreshold) {
				baseGrid[x][y] = TileType::stone;
			}
			else if (rnd > dirtThreshold) {
				baseGrid[x][y] = TileType::dirt;
			}
			else {
				baseGrid[x][y] = TileType::empty;
			}
		}
	}

	// Perform smoothing
	for (int i = 0; i < smoothingSteps; ++i) {
		smoothMap(baseGrid);
	}

	return baseGrid;
}

std::vector<std::vector<GameObject*>> MapGenerator::placeGameObjects(std::vector<std::vector<TileType>>& baseMap, std::vector<Team> teams)
{
	auto objectGrid = std::vector<std::vector<GameObject*>>();

	int width = baseMap.size();
	int height = baseMap[0].size();

	// Reserve memory
	objectGrid.resize(width);
	for (int x = 0; x < width; ++x) {
		// Reserve memory for each column
		objectGrid[x].resize(height);
		for (int y = 0; y < height; ++y) {
			objectGrid[x][y] = NULL;
		}
	}

	// Place spawn point for every team
	for (int i = 0; i < teams.size(); ++i) {
		// Get random empty tile
		auto pos = findEmptyTile(baseMap);
		// Create and place spawn point
		auto newSpawnPoint = SpawnPoint(teams[i].getId(), teams[i].getColour(), "ant", "antAgent");
		objectGrid[pos.x][pos.y] = &newSpawnPoint;
		// Add to the team's spawnPoint list

		// Turn surrounding tiles into empty tiles
		for (int x = pos.x - 1; x < pos.x + 1; ++x) {
			for (int y = pos.y - 1; y < pos.y + 1; ++y) {
				baseMap[x][y] = TileType::empty;
			}
		}
	}
	return objectGrid;
}

void MapGenerator::smoothMap(std::vector<std::vector<TileType>>& baseGrid)
{
	for (int x = 0; x < baseGrid.size(); ++x) {
		for (int y = 0; y < baseGrid[0].size(); ++y) {
			// Measure surroundings
			int count = measureSurroundings(x, y, baseGrid);
			// Smooth
			if (count > 10) {
				baseGrid[x][y] = TileType::stone;
			}
			else if (count > 5) {
				baseGrid[x][y] = TileType::dirt;
			}
			else {
				baseGrid[x][y] = TileType::empty;
			}
		}
	}
}

int MapGenerator::measureSurroundings(int gridX, int gridY, std::vector<std::vector<TileType>>& baseGrid)
{
	int count = 0;
	// Stone counts as 2, dirt counts as 1, empty counts as 0
	for (int x = gridX - 1; x <= gridX + 1; ++x) {
		for (int y = gridY - 1; y <= gridY + 1; ++y) {
			// Ensure that we are checking inside the actual map
			if (x < 0 || x >= baseGrid.size() || y < 0 || y >= baseGrid[0].size()) {
				count += 2;
			}
			else if (x != gridX || y != gridY) { // Don't count the tile itself
				if (baseGrid[x][y] == TileType::stone) {
					count += 2;
				}
				else if (baseGrid[x][y] == TileType::dirt) {
					++count;
				}
			}
		}
	}
	return count;
}

cocos2d::Vec2 MapGenerator::findEmptyTile(std::vector<std::vector<TileType>>& baseGrid)
{
	auto coords = cocos2d::Vec2();
	// Attempt to get a random empty tile from the base grid
	// TODO: Possible infinite loop
	do {
		coords.x = rand() % baseGrid.size();
		coords.y = rand() % baseGrid[0].size();
	} while (baseGrid[coords.x][coords.y] != TileType::empty);

	return coords;
}
