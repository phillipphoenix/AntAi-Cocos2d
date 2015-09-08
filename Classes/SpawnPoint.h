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


class SpawnPoint: public GameObject {
public: 
    
    void step();
private: 
    int hp;
    cocos2d::Point pos;
	CreatureFactory factory;
	std::vector<Item> items;
};

#endif //_SPAWNPOINT_H