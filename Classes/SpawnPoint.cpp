/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "SpawnPoint.h"

/**
 * SpawnPoint implementation
 */


SpawnPoint::SpawnPoint(int teamId, cocos2d::Color3B teamColour, std::string creatureType, std::string agentType)
{
	this->teamId = teamId;
	this->colour = teamColour;
	this->creatureType = creatureType;
	this->agentType = agentType;
}

void SpawnPoint::step() {
	// Check if the items list contains food and if it does, use it to create a creature.
	if (items.size() > 0) {
		for (std::vector<Item>::iterator item = items.begin(); item != items.end(); ++item) {
			if (item->getType() == "food" && item->getQuantity() > 0) {
				// If food is present, create creature and remove 1 food.
				factory.createCreature(teamId, colour, creatureType, agentType, pos);
				item->takeQuantity(1);
			}
		}
	}
}