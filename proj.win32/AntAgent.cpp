/**
* Project AntAi
* @author Phillip
* @version 1.0.0
*/


#include "AntAgent.h"


AgentAction AntAgent::step(int hp, cocos2d::Point pos, CreatureMap creatureGameMap, std::string currentItem, AgentAction lastAction)
{
	int moveActionInt = rand() % 4;
	switch (moveActionInt)
	{
	case 0:
		return AgentAction::MOVE_DOWN;
		break;
	case 1:
		return AgentAction::MOVE_LEFT;
		break;
	case 2:
		return AgentAction::MOVE_RIGHT;
		break;
	case 3:
		return AgentAction::MOVE_UP;
		break;
	}
	return AgentAction::NONE;
}
