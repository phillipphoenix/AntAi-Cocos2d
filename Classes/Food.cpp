/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "Food.h"

/**
 * Food implementation
 */

Food::Food()
{
	colour = cocos2d::Color3B(255, 255, 255);
}

std::string Food::getType() {
	return "food";
}