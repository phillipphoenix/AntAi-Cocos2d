/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _CREATUREFACTORY_H
#define _CREATUREFACTORY_H

#include <string>
#include "Creature.h"

class CreatureFactory {
public: 
    
    /**
     * @param creatureType
     * @param agentType
     */
    Creature* createCreature(std::string creatureType, std::string agentType);
};

#endif //_CREATUREFACTORY_H