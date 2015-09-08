/**
* Project AntAi
* @author Phillip
* @version 1.0.0
*/


#ifndef _CREATURE_MAP_H
#define _CREATURE_MAP_H

#include <vector>

class CreatureMap {
public:
	CreatureMap();
	CreatureMap(int width, int height);
	int getWidth();
	int getHeight();
	std::vector<int> getVector(int x, int y);
	void saveVector(int x, int y, std::vector<int> vector);
private:
	int width;
	int height;
	std::vector<std::vector<std::vector<int>>> map;
};

#endif //_CREATURE_MAP_H