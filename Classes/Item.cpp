/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "Item.h"

/**
 * Item implementation
 */


std::string Item::getType() {
	return "";
}

int Item::getQuantity()
{
	return quantity;
}

bool Item::takeQuantity(int quantity)
{
	if (quantity > 0 && quantity <= this->quantity) {
		this->quantity -= quantity;
		return true;
	}
	return false;
}

void Item::putQuantity(int quantity)
{
	if (quantity > 0)
		this->quantity += quantity;
}
