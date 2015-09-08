/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "Team.h"

/**
 * Team implementation
 */

	 int Team::getId()
	 {
		 return id;
	 }

	 std::string Team::getCreatureType()
	 {
		 return creatureType;
	 }

	 std::string Team::getAgentType()
	 {
		 return agentType;
	 }

	 cocos2d::Color3B Team::getColour()
	 {
		 return colour;
	 }
