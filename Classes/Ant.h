/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _ANT_H
#define _ANT_H

#include "Creature.h"

class Ant: public Creature {
public:
	Ant(int teamId, cocos2d::Color3B teamColour, Agent* agent, cocos2d::Point pos);
};

#endif //_ANT_H