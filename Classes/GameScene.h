#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameMap.h"

using namespace cocos2d;

class GameScene : public cocos2d::Layer
{

public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

	void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags);
private:
	GameMap map;

};

#endif // __GAME_SCENE_H__
