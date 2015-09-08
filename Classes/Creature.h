/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _CREATURE_H
#define _CREATURE_H

#include "cocos2d.h"
#include "Action.h"
#include "GameObject.h"
//#include "Team.h"
#include "Agent.h"
#include "CreatureMap.h"
#include <vector>
#include <string>

class Creature: public GameObject {
public: 
	Creature();
	Creature(int teamId, cocos2d::Color3B teamColour, Agent* agent);
	void setPosition(cocos2d::Point pos);
    void step();
	Action getLastAction();
    CreatureMap getMap();
protected:
	int teamId;
	//Team* team;
	Agent agent;
    int hp;
    CreatureMap map;
	cocos2d::Point pos;
	Action lastAction;
	std::string currentItem;
};

#endif //_CREATURE_H