/**
 * Project AntAi
 * @author Oscar
 * @version 1.0.0
 */


#include "MapGenerator.h"

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
			 if (x % 2 == 0) baseGrid[x][y] = TileType::stone;
			 else baseGrid[x][y] = TileType::dirt;
		 }
	 }

	 return baseGrid;
 }

 std::vector<std::vector<GameObject*>> MapGenerator::placeGameObjects(std::vector<std::vector<TileType>> baseMap, std::vector<Team> teams)
 {
	 return std::vector<std::vector<GameObject*>>();
 }
