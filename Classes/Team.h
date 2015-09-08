/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _TEAM_H
#define _TEAM_H

#include "cocos2d.h"
#include <string>

class Team {
public:
	int getId();
	std::string getCreatureType();
	std::string getAgentType();
	cocos2d::Color3B getColour();
private: 
    int id;
    std::string creatureType;
    std::string agentType;
    cocos2d::Color3B colour;
};

#endif //_TEAM_H