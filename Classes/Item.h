/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _ITEM_H
#define _ITEM_H

#include "GameObject.h"
#include <string>


class Item: public GameObject {
public: 
    
    virtual std::string getType();
private: 
    int quantity;
};

#endif //_ITEM_H