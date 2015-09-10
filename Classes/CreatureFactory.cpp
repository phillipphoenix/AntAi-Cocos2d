/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "CreatureFactory.h"

/**
 * CreatureFactory implementation
 */


/**
 * @param creatureType
 * @param agentType
 */
Creature* CreatureFactory::createCreature(int teamId, cocos2d::Color3B teamColour, std::string creatureType, std::string agentType, cocos2d::Point pos) {
	Agent* agent;
	// Find which agent to create.
	if (agentType == "antAgent") {
		agent = new AntAgent();
	}

	Creature* creature;
	// Find which creature to create.
	if (creatureType == "ant") {
		creature = new Ant(teamId, teamColour, agent, pos);
	}

	return creature;

}