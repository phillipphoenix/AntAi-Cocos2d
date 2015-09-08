/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _ITEM_H
#define _ITEM_H

#include "GameObject.h"


class Item: public GameObject {
public: 
    
    void getType();
private: 
    int quantity;
};

#endif //_ITEM_H