/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "Agent.h"

/**
 * Agent implementation
 */


AgentAction Agent::step(int hp, cocos2d::Point pos, CreatureMap creatureGameMap, std::string currentItem, AgentAction lastAction) {
	return AgentAction::MOVE_LEFT; // Default action is to do nothing.
}