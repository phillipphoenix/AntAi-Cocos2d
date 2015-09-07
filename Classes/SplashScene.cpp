#include "SplashScene.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Load stuff
	// Display logo
	/*
	auto logo = Sprite::create("logo.png");
	logo->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(logo);
	*/

	// Schedule scene transition after load
	this->scheduleOnce(schedule_selector(SplashScene::goToMenuScene), SPLASH_SCENE_DELAY);
    
    return true;
}

void SplashScene::goToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
