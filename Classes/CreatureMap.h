/**
* Project AntAi
* @author Phillip
* @version 1.0.0
*/


#ifndef _CREATURE_MAP_H
#define _CREATURE_MAP_H

#include <vector>

/*
The inner vector is defined as follows:
0 - step	// The step this was discovered last.
1 - object	// The object is one of these types: empty=0, walls=1, spawn points=2, creatures=3, items=4.
2 - type	// The type depends on the object: empty=not used, walls=0,1 (dirt, stone), spawn points and creatures=team id, items=0 (food).
3 - var1	// Extra variable #1, not always used. Creatures=current item, items=quantity.
4 - var2	// Extra variable #2, not always used. creatures=last action.
*/
class CreatureMap {
public:
	CreatureMap();
	CreatureMap(int width, int height);
	int getWidth();
	int getHeight();
	/*
	The vector is defined as follows:
	0 - step	// The step this was discovered last.
	1 - object	// The object is one of these types: empty=0, walls=1, spawn points=2, creatures=3, items=4.
	2 - type	// The type depends on the object: empty=not used, walls=0,1 (dirt, stone), spawn points and creatures=team id, items=0 (food).
	3 - var1	// Extra variable #1, not always used. Creatures=current item, items=quantity.
	4 - var2	// Extra variable #2, not always used. creatures=last action.
	*/
	std::vector<int> getVector(int x, int y);
	/*
	The vector is defined as follows:
	0 - step	// The step this was discovered last.
	1 - object	// The object is one of these types: empty=0, walls=1, spawn points=2, creatures=3, items=4.
	2 - type	// The type depends on the object: empty=not used, walls=0,1 (dirt, stone), spawn points and creatures=team id, items=0 (food).
	3 - var1	// Extra variable #1, not always used. Creatures=current item, items=quantity.
	4 - var2	// Extra variable #2, not always used. creatures=last action.
	*/
	void saveVector(int x, int y, std::vector<int> vector);
private:
	int width;
	int height;
	/*
	The inner vector of ints are defined as follows:
	0 - step	// The step this was discovered last.
	1 - object	// The object is one of these types: empty=0, walls=1, spawn points=2, creatures=3, items=4.
	2 - type	// The type depends on the object: empty=not used, walls=0,1 (dirt, stone), spawn points and creatures=team id, items=0 (food).
	3 - var1	// Extra variable #1, not always used. Creatures=current item, items=quantity.
	4 - var2	// Extra variable #2, not always used. creatures=last action.
	*/
	std::vector<std::vector<std::vector<int>>> map;
};

#endif //_CREATURE_MAP_H