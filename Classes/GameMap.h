/**
 * Project AntAi
 * @author Oscar
 * @version 1.0.0
 */


#ifndef _MAP_H
#define _MAP_H

class GameObject;

#include <vector>
#include <cmath>
#include "TileType.h"
#include "MapGenerator.h"
#include "Team.h"


#define TILE_HEIGHT 6
#define TILE_WIDTH 6

class GameMap {
public:
	GameMap();
	GameMap(int width, int height, std::vector<Team>& teams, MapGenerator& gen, cocos2d::Layer* layer);
	void step();

	void setKeyUp(bool state);
	void setKeyDown(bool state);
	void setKeyLeft(bool state);
	void setKeyRight(bool state);
	
private:
	// Size of the tile sprite in points
	float tileWidth;
	float tileHeight;
	// Colours used for the base grid
	//cocos2d::Color3B emptyColour = cocos2d::Color3B(255, 229, 204); // Empty
	cocos2d::Color3B emptyColour = cocos2d::Color3B(255, 153, 51); // Empty
	cocos2d::Color3B dirtColour = cocos2d::Color3B(204, 102, 0); // Dirt
	cocos2d::Color3B stoneColour = cocos2d::Color3B(96, 96, 96); // Stone
	// Map generator
	MapGenerator gen;
	// Teams
	std::vector<Team> teams;
	// Grids containing the layout of the map
	std::vector<std::vector<TileType>> baseGrid;
	std::vector<std::vector<GameObject*>> gameObjectGrid;
	// Sprite grid used to display the map
	std::vector<std::vector<cocos2d::Sprite*>> tileMap;

	bool keyUp = false;
	bool keyDown = false;
	bool keyLeft = false;
	bool keyRight = false;

	int firstVisibleTile_x;
	int firstVisibleTile_y;

	// Helper function that stores the tile sprite dimensions in points in class members
	void calculateTileDimensions();

	void updateCameraPosition();

};




#endif //_MAP_H