/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _MAPGENERATOR_H
#define _MAPGENERATOR_H

#include <vector>
#include "Team.h"
#include "GameObject.h"

class MapGenerator {
public: 
    
	std::vector<std::vector<std::vector<int>>> generateBaseMap(int width, int height);
    
    /**
     * @param baseMap
     * @param teams
     */
	std::vector<std::vector<GameObject>> placeGameObjects(std::vector<std::vector<std::vector<int>>> baseMap, std::vector<Team> teams);
};

#endif //_MAPGENERATOR_H