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
	Item();
    std::string getType();
	int getQuantity();
	bool takeQuantity(int quantity);
	void putQuantity(int quantity);
private: 
    int quantity;
protected:
	std::string type;
};

#endif //_ITEM_H