/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _SPAWNPOINT_H
#define _SPAWNPOINT_H

#include "GameObject.h"


class SpawnPoint: public GameObject {
public: 
    
    void step();
private: 
    int hp;
    Point pos;
};

#endif //_SPAWNPOINT_H