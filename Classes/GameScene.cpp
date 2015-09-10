#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	// Create map
	MapGenerator gen = MapGenerator(75, 35, 1);
	auto teams = std::vector<Team>();
	map = GameMap(100, 100, teams, gen, this);

	// Schedule update function
	this->scheduleUpdate();

	// Schedule camera control with keyboard arrows
	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::keyPressed, this);
	keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::keyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	return true;
}

void GameScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W || keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		map.setKeyUp(true);
	} else if (keyCode == EventKeyboard::KeyCode::KEY_S || keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)	{
		map.setKeyDown(true);
	} else if (keyCode == EventKeyboard::KeyCode::KEY_A || keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)	{
		map.setKeyLeft(true);
	} else if (keyCode == EventKeyboard::KeyCode::KEY_D || keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)	{
		map.setKeyRight(true);
	}
}

void GameScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_W || keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		map.setKeyUp(false);
	} else if (keyCode == EventKeyboard::KeyCode::KEY_S || keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		map.setKeyDown(false);
	} else if (keyCode == EventKeyboard::KeyCode::KEY_A || keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		map.setKeyLeft(false);
	} else if (keyCode == EventKeyboard::KeyCode::KEY_D || keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		map.setKeyRight(false);
	}
}

GameMap GameScene::getMap()
{
	return map;
}

void GameScene::update(float dt)
{
	// Iterate over all the teams' spawn points and ants, validate their actions and perform them.
	for (std::vector<Team>::iterator itTeam = teams.begin(); itTeam < teams.end(); itTeam++) {
		// Spawn points.
		for (std::vector<SpawnPoint>::iterator itSpawnPoint = itTeam->getSpawnPointIteratorBegin(); itSpawnPoint < itTeam->getSpawnPointIteratorEnd(); itSpawnPoint++) {
			itSpawnPoint->step(itTeam->getCreatures(), map);
		}
		// Creatures.
		for (std::vector<Creature>::iterator itCreature = itTeam->getCreatureIteratorBegin(); itCreature < itTeam->getCreatureIteratorEnd(); itCreature++) {
			AgentAction action = itCreature->step();	// Get action from creature.
			map.executeAction(&(*itCreature), action);	// Execute action, IF valid (map handles validation).
		}
	}
	// Update the sprite map to match the new map realities! OoooOooOooOoOOooOoOooHhhh...
	map.step();
}