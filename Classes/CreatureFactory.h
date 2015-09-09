/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _CREATUREFACTORY_H
#define _CREATUREFACTORY_H

class Creature;
class Agent;

#include "cocos2d.h"
#include <string>

// Include all the agents and creatures.
#include "Ant.h"

class CreatureFactory {
public:
    Creature* createCreature(int teamId, cocos2d::Color3B teamColour, std::string creatureType, std::string agentType, cocos2d::Point pos);
};

#endif //_CREATUREFACTORY_H