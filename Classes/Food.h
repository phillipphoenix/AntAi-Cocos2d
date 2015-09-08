/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _FOOD_H
#define _FOOD_H

#include "Item.h"


class Food: public Item {
public:
	std::string getType();
};

#endif //_FOOD_H