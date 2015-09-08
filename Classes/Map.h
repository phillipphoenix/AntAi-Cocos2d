/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _MAP_H
#define _MAP_H

#include <vector>
#include "GameObject.h"

class Map {
private: 
    std::vector<std::vector<std::vector<int>>> baseGrid;
	std::vector<std::vector<GameObject>> gameObjectGrid;
};

#endif //_MAP_H