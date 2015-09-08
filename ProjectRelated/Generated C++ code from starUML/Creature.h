/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _CREATURE_H
#define _CREATURE_H

#include "GameObject.h"


class Creature: public GameObject {
public: 
    
    void step();
    
    void getLastAction();
    
    void getMap();
private: 
    int hp;
    string map;
    Point pos;
};

#endif //_CREATURE_H