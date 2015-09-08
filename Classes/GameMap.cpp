/**
 * Project AntAi
 * @author Oscar
 * @version 1.0.0
 */


#include "GameMap.h"

/**
 * GameMap implementation
 */

GameMap::GameMap() {}

GameMap::GameMap(int width, int height, std::vector<Team> teams, MapGenerator gen)
{
	this->gen = gen;
	baseGrid = gen.generateBaseMap(width, height);
	gameObjectGrid = gen.placeGameObjects(baseGrid, teams);
}
void GameMap::draw()
{
	// Run through the base map grid and draw all the tiles
	for (int x = 0; x < baseGrid.size(); ++x) {
		for (int y = 0; y < baseGrid[x].size(); ++y) {
			drawTile(x, y, baseGrid[x][y]);
			//drawGameObject(x, y, gameObjectGrid[x][y]->getColour());
		}
	}
}

void GameMap::drawTile(int x, int y, TileType tile)
{	
	//auto emptyColour = cocos2d::Color3B(255, 229, 204); // Empty
	//auto dirtColour = cocos2d::Color3B(204, 102, 0); // Dirt
	//auto stoneColour = cocos2d::Color3B(96, 96, 96); // Stone

	// Select colour based on the TileType
	cocos2d::Color3B colour;
	if (tile == TileType::empty) {
		colour = cocos2d::Color3B(255, 229, 204);
	}
	else if (tile == TileType::dirt) {
		colour = cocos2d::Color3B(204, 102, 0);
	}
	else { // Stone
		colour = cocos2d::Color3B(96, 96, 96);
	}
	// Draw the tile
	cocos2d::DrawPrimitives::drawSolidRect(cocos2d::Vec2(x * TILE_WIDTH, y * TILE_HEIGHT), cocos2d::Vec2(x * TILE_WIDTH + TILE_WIDTH, y * TILE_HEIGHT + TILE_HEIGHT), cocos2d::Color4F(colour));
}

void GameMap::drawGameObject(int x, int y, cocos2d::Color3B colour)
{
	cocos2d::DrawPrimitives::drawSolidRect(cocos2d::Vec2(x, y), cocos2d::Vec2(x + TILE_WIDTH, y + TILE_HEIGHT), cocos2d::Color4F(colour));
}
