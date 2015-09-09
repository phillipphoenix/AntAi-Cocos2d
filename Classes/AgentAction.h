/**
 * Project AntAi
 * @author Phillip
 * @version 1.0.0
 */


#ifndef _ACTION_H
#define _ACTION_H

enum AgentAction {
	NONE = 0,
	MOVE_LEFT = 1, MOVE_UP = 2, MOVE_RIGHT = 3, MOVE_DOWN = 4,
	DIG_LEFT = 5, DIG_UP = 6, DIG_RIGHT = 7, DIG_DOWN = 8,
	ATTACK_LEFT = 9, ATTACK_UP = 10, ATTACK_RIGHT = 11, ATTACK_DOWN = 12,
	PICKUP_LEFT = 13, PICKUP_UP = 14, PICKUP_RIGHT = 15, PICKUP_DOWN = 16,
	PUTDOWN_LEFT = 17, PUTDOWN_UP = 18, PUTDOWN_RIGHT = 19, PUTDOWN_DOWN = 20,
	EAT = 21,
	SHARE_KNOWLEDGE = 22
};

#endif //_ACTION_H