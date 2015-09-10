/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "SpawnPoint.h"
#include "GameMap.h"

/**
 * SpawnPoint implementation
 */


SpawnPoint::SpawnPoint(int teamId, cocos2d::Color3B teamColour, cocos2d::Point pos, std::string creatureType, std::string agentType)
{
	this->teamId = teamId;
	this->colour = cocos2d::Color3B(teamColour.r-10, teamColour.g-10, teamColour.b-10); // Make the spawn point a darker shade of the team colour.
	this->pos = pos;
	this->creatureType = creatureType;
	this->agentType = agentType;

	// Add starting items.
	Food food = Food();
	food.putQuantity(10);
	this->items.push_back(food);
}

void SpawnPoint::step(std::vector<Creature>* teamCreatureList, GameMap& map) {
	// Check if the items list contains food and if it does, use it to create a creature.
	if (items.size() > 0) {
		for (std::vector<Item>::iterator item = items.begin(); item != items.end(); ++item) {
			if (item->getType() == "food" && item->getQuantity() > 0) {
				// If food is present and a free space exists around the spawn point, create creature and remove 1 food.
				Creature* creature;
				if (map.spaceEmpty(pos.x - 1, pos.y)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x - 1, pos.y));
				} else if (map.spaceEmpty(pos.x + 1, pos.y)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x + 1, pos.y));
				} else if (map.spaceEmpty(pos.x, pos.y - 1)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x, pos.y - 1));
				} else if (map.spaceEmpty(pos.x, pos.y + 1)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x, pos.y + 1));
				} else if (map.spaceEmpty(pos.x - 1, pos.y - 1)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x - 1, pos.y - 1));
				} else if (map.spaceEmpty(pos.x + 1, pos.y - 1)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x + 1, pos.y - 1));
				} else if (map.spaceEmpty(pos.x - 1, pos.y + 1)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x - 1, pos.y + 1));
				} else if (map.spaceEmpty(pos.x + 1, pos.y + 1)) {
					creature = factory.createCreature(teamId, colour, creatureType, agentType, cocos2d::Point(pos.x + 1, pos.y + 1));
				}
				if (creature != NULL) {
					teamCreatureList->push_back(*creature); // Add creature to the team's creature list.
					map.addGameObject(creature->getPosition().x, creature->getPosition().y, creature); // Add creature to gameObjectGrid on the map.
					item->takeQuantity(1); // Take 1 food from the spawn point.
				}
			}
		}
	}
}

cocos2d::Point SpawnPoint::getPos()
{
	return pos;
}
