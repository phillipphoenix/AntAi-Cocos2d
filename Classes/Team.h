/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _TEAM_H
#define _TEAM_H

class Creature;

#include "cocos2d.h"
#include <vector>
#include <string>
#include "SpawnPoint.h"

class Team {
public:
	Team();
	Team(int id, cocos2d::Color3B teamColour, std::string creatureType, std::string agentType);
	int getId();
	std::string getCreatureType();
	std::string getAgentType();
	cocos2d::Color3B getColour();
	// These four methods return the begin and end iterators for the creature and spawn point vectors.
	std::vector<Creature>::iterator getCreatureIteratorBegin();
	std::vector<Creature>::iterator getCreatureIteratorEnd();
	std::vector<SpawnPoint>::iterator getSpawnPointIteratorBegin();
	std::vector<SpawnPoint>::iterator getSpawnPointIteratorEnd();
	// Add elements to the creature and spawn point lists.
	void addCreature(Creature& creature);
	void addSpawnPoint(SpawnPoint& spawnPoint);
	// Get lists.
	std::vector<Creature>* getCreatures();
	std::vector<SpawnPoint>* getSpawnPoints();
private: 
    int id;
    std::string creatureType;
    std::string agentType;
    cocos2d::Color3B colour;
	std::vector<Creature> creatures;
	std::vector<SpawnPoint> spawnPoints;

};

#endif //_TEAM_H