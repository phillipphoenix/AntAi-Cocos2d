/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#include "SpawnPoint.h"

/**
 * SpawnPoint implementation
 */


void SpawnPoint::step() {
	for (std::vector<Item>::iterator item = items.begin(); item != items.end(); ++item) {
		if (item->getType() == "food" && item->getQuantity() > 0) {

		}
	}
}