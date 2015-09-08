/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _CREATURE_H
#define _CREATURE_H

#include "GameObject.h"
#include "cocos2d.h"
#include "Action.h"

class Creature: public GameObject {
public: 
    
    void step();
    
	Action getLastAction();
    
    void getMap();
private: 
    int hp;
    int*** map;
	cocos2d::Point pos;
	Action lastAction;
};

#endif //_CREATURE_H