/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _SPAWNPOINT_H
#define _SPAWNPOINT_H

class Team;
class GameMap;

#include "cocos2d.h"
#include "GameObject.h"
#include "CreatureFactory.h"
#include "Item.h"
#include "Food.h"
#include <vector>
#include <string>

#include <iostream>


class SpawnPoint: public GameObject {
public: 
	SpawnPoint() {};
	SpawnPoint(int teamId, cocos2d::Color3B teamColour, cocos2d::Point pos, std::string creatureType, std::string agentType);
    void step(std::vector<Creature>* teamCreatureList, GameMap& map); // Give the creature list, so it can be updated with a new creature.
	cocos2d::Point getPos();
	cocos2d::Color3B getColour();
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