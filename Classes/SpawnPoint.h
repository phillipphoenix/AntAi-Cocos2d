/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _SPAWNPOINT_H
#define _SPAWNPOINT_H

#include "cocos2d.h"
#include "GameObject.h"
#include "CreatureFactory.h"
#include "Item.h"
#include <vector>
#include <string>


class SpawnPoint: public GameObject {
public: 
	SpawnPoint() {};
	SpawnPoint(int teamId, cocos2d::Color3B teamColour, std::string creatureType, std::string agentType);
    void step();
private:
	int teamId;
	std::string creatureType;
	std::string agentType;
    int hp;
    cocos2d::Point pos;
	CreatureFactory factory;
	std::vector<Item> items;
};

#endif //_SPAWNPOINT_H