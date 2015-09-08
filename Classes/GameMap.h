/**
 * Project AntAi
 * @author Oscar
 * @version 1.0.0
 */


#ifndef _MAP_H
#define _MAP_H

class GameObject;

#include <vector>
#include "TileType.h"
#include "MapGenerator.h"


#define TILE_HEIGHT 4
#define TILE_WIDTH 4

class GameMap {
public:
	GameMap();
	GameMap(int width, int height, std::vector<Team> teams, MapGenerator gen);
	void draw();
private:
	MapGenerator gen;
	std::vector<std::vector<TileType>> baseGrid;
	std::vector<std::vector<GameObject*>> gameObjectGrid;

	void drawTile(int x, int y, TileType tile);
	void drawGameObject(int x, int y, cocos2d::Color3B colour);
};




#endif //_MAP_H