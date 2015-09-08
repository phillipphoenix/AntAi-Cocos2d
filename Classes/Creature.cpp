/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "Creature.h"

/**
 * Creature implementation
 */

Creature::Creature()
{
}

// Team* means it will always point to the same team and don't clone the object.
// Agent (without the *) means it will be a clone each time.
Creature::Creature(int teamId, cocos2d::Color3B teamColour, Agent* agent)
{
	this->teamId = teamId;
	colour = teamColour;
	this->agent = *agent;
}

void Creature::setPosition(cocos2d::Point pos)
{
	this->pos = pos;
}

void Creature::step() {

	agent.step(hp, new cocos2d::Point(pos.x, pos.y), NULL, NULL, std::string(currentItem), lastAction);
}

Action Creature::getLastAction() {
	return lastAction;
}

CreatureMap Creature::getMap() {
	return map;
}