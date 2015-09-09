/**
 * Project AntAi
 * @author Oscar
 * @version 1.0.0
 */


#ifndef _MAPGENERATOR_H
#define _MAPGENERATOR_H

class GameObject;

#include <vector>
#include "Team.h"
#include "TileType.h"


class MapGenerator {
public:
	MapGenerator();
	MapGenerator(int stoneThreshold, int dirtThreshold, int smoothingSteps);
	std::vector<std::vector<TileType>> generateBaseMap(int width, int height);

	/**
	* @param baseMap
	* @param teams
	*/
	std::vector<std::vector<GameObject*>> placeGameObjects(std::vector<std::vector<TileType>> baseMap, std::vector<Team> teams);
private:
	int stoneThreshold;
	int dirtThreshold;
	int smoothingSteps;

	void smoothMap(std::vector<std::vector<TileType>>& baseGrid);

	int measureSurroundings(int gridX, int gridY, std::vector<std::vector<TileType>>& baseGrid);

};



#endif //_MAPGENERATOR_H