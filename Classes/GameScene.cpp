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

	// Test
	/*auto testLabel = Label::createWithSystemFont("Here comes the bride...", "Arial", 20);
	testLabel->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	this->addChild(testLabel);*/

	MapGenerator gen = MapGenerator();
	auto teams = std::vector<Team>();
	map = GameMap(100, 100, teams, gen);	

	return true;
}

void GameScene::draw(Renderer * renderer, const Mat4 & transform, uint32_t flags)
{
	map.draw();
}
