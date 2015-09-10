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

	 std::vector<Creature>::iterator Team::getCreatureIteratorBegin()
	 {
		 return creatures.begin();
	 }

	 std::vector<Creature>::iterator Team::getCreatureIteratorEnd()
	 {
		 return creatures.end();
	 }

	 std::vector<SpawnPoint>::iterator Team::getSpawnPointIteratorBegin()
	 {
		 return spawnPoints.begin();
	 }

	 std::vector<SpawnPoint>::iterator Team::getSpawnPointIteratorEnd()
	 {
		 return spawnPoints.end();
	 }

	 void Team::addCreature(Creature & creature)
	 {
		 creatures.push_back(creature);
	 }

	 void Team::addSpawnPoint(SpawnPoint & spawnPoint)
	 {
		 spawnPoints.push_back(spawnPoint);
	 }

	 std::vector<Creature>* Team::getCreatures()
	 {
		 return &creatures;
	 }

	 std::vector<SpawnPoint>* Team::getSpawnPoints()
	 {
		 return &spawnPoints;
	 }
