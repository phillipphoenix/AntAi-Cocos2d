/**
 * Project AntAi
 * @author Oscar
 * @version 1.0.0
 */


#ifndef _MAP_H
#define _MAP_H

class GameObject;
class Team;

#include <vector>
#include <cmath>
#include "TileType.h"
#include "MapGenerator.h"


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

	void executeAction(Creature* creature, AgentAction action);
	
	/* Returns true if (x,y) is inside the map and nothing is in that position on either the baseGrid or the gameObjectGrid */
	bool spaceEmpty(int x, int y);
	int getBaseGridValue(int x, int y);
	std::shared_ptr<GameObject> getGameObjectGridValue(int x, int y);

	void addGameObject(int x, int y, GameObject& gameObject);
private:
	// Size of the tile sprite in points
	float tileWidth;
	float tileHeight;
	// Colours used for the base grid
	cocos2d::Color3B emptyColour = cocos2d::Color3B(255, 153, 51); // Empty
	cocos2d::Color3B dirtColour = cocos2d::Color3B(204, 102, 0); // Dirt
	cocos2d::Color3B stoneColour = cocos2d::Color3B(96, 96, 96); // Stone

	// Map generator
	MapGenerator gen;

	// Grids containing the layout of the map
	std::vector<std::vector<TileType>> baseGrid;
	std::vector<std::vector<std::shared_ptr<GameObject>>> gameObjectGrid;
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