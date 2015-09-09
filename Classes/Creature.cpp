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
Creature::Creature(int teamId, cocos2d::Color3B teamColour, Agent* agent, cocos2d::Point pos)
{
	this->teamId = teamId;
	this->colour = teamColour;
	this->agent = *agent;
	this->pos = pos;
}

void Creature::setPosition(cocos2d::Point pos)
{
	this->pos = pos;
}

Action Creature::step() {
	return agent.step(hp, pos, visibleMap, map, currentItem, lastAction);
}

Action Creature::getLastAction() {
	return lastAction;
}

CreatureMap Creature::getMap() {
	return map;
}

void Creature::updateVisibleMap(CreatureMap visibleMap)
{
	this->visibleMap = visibleMap;

	// Merge the new visible map into the overall creature game map.
	int x = pos.x;
	int y = pos.y;
	int minX = x - visionRange;
	int minY = y - visionRange;
	int maxX = x + visionRange;
	int maxY = y + visionRange;

	for (int iX = minX; iX < maxX; iX++) {
		for (int iY = minY; iY < maxY; iY++) {
			if (iX >= 0 && iX < map.getWidth() && iY >= 0 && iY < map.getHeight()) {
				map.saveVector(iX, iY, visibleMap.getVector(iX - minX, iY - minY));
			}
		}
	}

}

int Creature::getHp()
{
	return hp;
}

void Creature::setHp(int hp)
{
	this->hp = hp;
}

int Creature::getVisionRange()
{
	return visionRange;
}

std::string Creature::getCurrentItem()
{
	return currentItem;
}
