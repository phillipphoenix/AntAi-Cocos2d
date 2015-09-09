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

GameMap::GameMap(int width, int height, std::vector<Team>& teams, MapGenerator& gen, cocos2d::Layer* layer)
{
	// Save reference to map generator
	this->gen = gen;
	// Generate base grid
	baseGrid = gen.generateBaseMap(width, height);
	// Generate game object grid
	gameObjectGrid = gen.placeGameObjects(baseGrid, teams);
	// Save reference to teams
	this->teams = teams;
	// Initialise first visible tile coordinates
	firstVisibleTile_x = 0;
	firstVisibleTile_y = 0;

	// Reserve sprite grid to cover the whole screen
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	// Store size of tile sprite in points
	calculateTileDimensions();
	// Initialize x coordinate
	float x_offset = origin.x;
	// Reserve row
	tileMap.resize(ceil(visibleSize.width / tileWidth));
	for (int x = 0; x < tileMap.size(); ++x) {
		// Initialize y coordinate
		float y_offset = origin.y;
		// Reserve column
		tileMap[x].resize(ceil(visibleSize.height / tileHeight));
		for (int y = 0; y < tileMap[x].size(); ++y) {
			// Create sprite
			tileMap[x][y] = cocos2d::Sprite::create("rect.png");
			// Set anchor point and position for the sprite
			tileMap[x][y]->setAnchorPoint(cocos2d::Vec2(0, 0));
			tileMap[x][y]->setPosition(x_offset, y_offset);
			// Add sprite to the layer
			layer->addChild(tileMap[x][y], 1);
			
			y_offset += tileHeight;
		}
		x_offset += tileWidth;
	}
}

void GameMap::calculateTileDimensions()
{
	auto tile = cocos2d::Sprite::create("rect.png");
	tileWidth = tile->getContentSize().width;
	tileHeight = tile->getContentSize().height;
}

// Updates the tileMap with the information in the baseGrid and the gameObjectGrid
void GameMap::step()
{
	// Calculate the first visible tile from the map
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	// Update camera position
	updateCameraPosition();
	int offset_x = firstVisibleTile_x * tileWidth;
	int offset_y = firstVisibleTile_y * tileHeight;
	// Run through the tileMap and color the sprites according to the baseGrid and gameObjectGrid data
	// Initialize x index of current tile
	int currentTile_x = firstVisibleTile_x;
	for (int x = 0; x < tileMap.size(); ++x) {
		// Initialize y index of current tile
		int currentTile_y = firstVisibleTile_y;
		for (int y = 0; y < tileMap[x].size(); ++y) {

			if (currentTile_x >= baseGrid.size() || currentTile_y >= baseGrid[currentTile_x].size()) {
				tileMap[x][y]->setVisible(false);
			} else if (baseGrid[currentTile_x][currentTile_y] == TileType::empty) {
				tileMap[x][y]->setVisible(true);
				tileMap[x][y]->setColor(emptyColour);
			}
			else if (baseGrid[currentTile_x][currentTile_y] == TileType::dirt) {
				tileMap[x][y]->setVisible(true);
				tileMap[x][y]->setColor(dirtColour);
			}
			else { // stone
				tileMap[x][y]->setVisible(true);
				tileMap[x][y]->setColor(stoneColour);
			}

			++currentTile_y;
		}
		++currentTile_x;
	}
}

void GameMap::updateCameraPosition()
{
	if (keyUp && firstVisibleTile_y < baseGrid[0].size() - tileMap[0].size()) {
		++firstVisibleTile_y;
	} else if (keyDown && firstVisibleTile_y > 0) {
		--firstVisibleTile_y;
	} else if(keyLeft && firstVisibleTile_x > 0) {
		--firstVisibleTile_x;
	} else if (keyRight && firstVisibleTile_x <= baseGrid.size() - tileMap.size()) {
		++firstVisibleTile_x;
	}
}

void GameMap::setKeyUp(bool state)
{
	keyUp = state;
}
void GameMap::setKeyDown(bool state)
{
	keyDown = state;
}
void GameMap::setKeyLeft(bool state)
{
	keyLeft = state;
}
void GameMap::setKeyRight(bool state)
{
	keyRight = state;
}