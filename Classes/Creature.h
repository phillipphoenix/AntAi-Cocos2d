/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _CREATURE_H
#define _CREATURE_H

#include "cocos2d.h"
#include "AgentAction.h"
#include "GameObject.h"
#include "Agent.h"
#include "CreatureMap.h"
#include <vector>
#include <string>

class Creature: public GameObject {
public: 
	Creature();
	Creature(int teamId, cocos2d::Color3B teamColour, Agent* agent, cocos2d::Point pos);
	void setPosition(cocos2d::Point pos);

	/*
	The step method will call the agent's step method, which is the AI that decides on an action to take.
	It returns the action, to the caller of the step method, which will handle the action, if it is valid.
	Creatures inheriting from this class can override the step method in order to restrict the valid moves for a particular creature.
	*/
    AgentAction step();

	AgentAction getLastAction();
	/* Get the game map as the creature knows it. */
    CreatureMap getMap();
	/* Update the part of the map, visible to the creature (with the creature in the middle). */
	void updateVisibleMap(CreatureMap visibleMap);
	int getHp();
	void setHp(int hp);
	/* The range the creature can see in each direction (the visible map is square!). */
	int getVisionRange();
	std::string getCurrentItem();
	cocos2d::Point getPosition();
protected:
	int teamId;
	Agent* agent;
    int hp;
	int visionRange = 3; // The range the creature can see in each direction (the visible map is square!).
    CreatureMap map; // The game map as the creature knows it.
	CreatureMap visibleMap; // The part of the map, visible to the creature (with the creature in the middle).
	cocos2d::Point pos;
	AgentAction lastAction;
	std::string currentItem;
};

#endif //_CREATURE_H