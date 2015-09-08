/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _MAPGENERATOR_H
#define _MAPGENERATOR_H

class MapGenerator {
public: 
    
    void generateBaseMap();
    
    /**
     * @param baseMap
     * @param teams
     */
    void placeGameObjects( baseMap,  teams);
};

#endif //_MAPGENERATOR_H