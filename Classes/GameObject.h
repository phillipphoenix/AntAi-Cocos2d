/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "cocos2d.h"

class GameObject {
public: 
    
    cocos2d::Color3B getColour();
protected:
	cocos2d::Color3B colour;

};

#endif //_GAMEOBJECT_H