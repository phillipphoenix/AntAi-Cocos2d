#include "MenuScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Title
	auto titleLabel = Label::createWithSystemFont("Ant AI", "Arial", 50);
	titleLabel->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height - titleLabel->getContentSize().height);
	this->addChild(titleLabel);

	// Menu
	Vector<MenuItem*> MenuItems;

	auto playItem = MenuItemFont::create("Play", CC_CALLBACK_1(MenuScene::goToGameScene, this));
	playItem->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
	MenuItems.pushBack(playItem);

	auto exitItem = MenuItemFont::create("Exit", CC_CALLBACK_1(MenuScene::exitGame, this));
	exitItem->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - playItem->getContentSize().height);
	MenuItems.pushBack(exitItem);

	// Create menu form vector of items
	auto menu = Menu::createWithArray(MenuItems);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);

	return true;
}

void MenuScene::goToGameScene(cocos2d::Ref* sender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void MenuScene::exitGame(cocos2d::Ref* sender)
{
	Director::getInstance()->end();
}
