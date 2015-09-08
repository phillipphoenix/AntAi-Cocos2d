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


class SpawnPoint: public GameObject {
public: 
    
    void step();
private: 
    int hp;
    cocos2d::Point pos;
	CreatureFactory factory;
};

#endif //_SPAWNPOINT_H