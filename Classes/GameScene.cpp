#include<iostream>
#include "audio/include/AudioEngine.h"
#include"HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"
USING_NS_CC;
Scene* GameSceneMountain::createScene()
{
	return GameSceneMountain::create();
}

bool GameSceneMountain::init()
{
	if (!Scene::create())
		return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_gamebg->setContentSize(Size(1400, 960));
	_gamebg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_gamebg->setPosition(visibleSize/2);
	this->addChild(_gamebg);

	_land1->setPosition(Vec2(230, 350));
	_land2->setPosition(Vec2(970, 280));
	_land3->setPosition(Vec2(700, 170));
	_land4->setPosition(Vec2(1170, 500));
	_land5->setPosition(Vec2(750, 620));
	_land6->setPosition(Vec2(550, 450));

	this->addChild(_land1);
	this->addChild(_land2);
	this->addChild(_land3);
	this->addChild(_land4);
	this->addChild(_land5);
	this->addChild(_land6);
	 

	auto button_pause = MenuItemImage::create(
		"sound(1).png",
		"sound.(1)png");
	auto button_resume = MenuItemImage::create(
		"sound(1).png",
		"sound(1).png");
	auto button_toggle = MenuItemToggle::createWithCallback
		(CC_CALLBACK_1(GameSceneMountain::menuPauseCallback, this),
			button_pause,
			button_resume, NULL);
	button_toggle->setPosition(Vec2(visibleSize) - Vec2(35, 35));
	Menu* menu_sound = Menu::create(button_toggle,NULL);
	menu_sound->setPosition(Vec2::ZERO);
	this->addChild(menu_sound, 1);

	MyMenu mymenu;
	Button* button_end = mymenu.create_button_end();
	this -> addChild(button_end);

	return true;
}

void GameSceneMountain::menuPauseCallback(Ref* pSender)
{
	static int count = 0;
	if(count%2==0)
	    AudioEngine::pause(_backgroundAudioID);
	else
		AudioEngine::resume(_backgroundAudioID);
	count++;
}

Scene* GameSceneForest::createScene()
{
	return GameSceneForest::create();
}

bool GameSceneForest::init()
{
	if (!Scene::create())
		return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_gamebg->setContentSize(Size(1400, 960));
	_gamebg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_gamebg->setPosition(visibleSize / 2);
	this->addChild(_gamebg);

	_land1->setPosition(Vec2(350, 600));
	_land2->setPosition(Vec2(300, 300));
	_land3->setPosition(Vec2(600, 120));
	_land4->setPosition(Vec2(1050, 500));
	_land5->setPosition(Vec2(800, 370));
	_land6->setPosition(Vec2(1100, 220));

	this->addChild(_land1);
	this->addChild(_land2);
	this->addChild(_land3);
	this->addChild(_land4);
	this->addChild(_land5);
	this->addChild(_land6);

	auto button_pause = MenuItemImage::create(
		"sound_on.png",
		"sound_on.png");
	auto button_resume = MenuItemImage::create(
		"sound_close.png",
		"sound_close.png");
	auto button_toggle = MenuItemToggle::createWithCallback
	(CC_CALLBACK_1(GameSceneForest::menuPauseCallback, this),
		button_pause,
		button_resume, NULL);
	button_toggle->setPosition(Vec2(visibleSize) - Vec2(35, 35));
	Menu* menu_sound = Menu::create(button_toggle, NULL);
	menu_sound->setPosition(Vec2::ZERO);
	this->addChild(menu_sound, 1);

	MyMenu mymenu;
	Button* button_end = mymenu.create_button_end();
	this->addChild(button_end);

	return true;
}

void GameSceneForest::menuPauseCallback(Ref* pSender)
{
	static int count2 = 0;
	if (count2 % 2 == 0)
		AudioEngine::pause(_backgroundAudioID);
	else
		AudioEngine::resume(_backgroundAudioID);
	count2++;
}

void MyMenu::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}

Button* MyMenu::create_button_end()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto button_end = ui::Button::create(
		"close.png",
		"close.png", "close.png");
	button_end->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_end->setPosition(Vec2(visibleSize) - Vec2(100, 35));
	button_end->addClickEventListener([](Ref* sender) {
		Director::getInstance()->end();
		});
	return button_end;
}


void MyMenu::menuSingleCallback(cocos2d::Ref* pSender)
{
	Scene* pScene = ChooseSingle::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
}

void MyMenu::menuDoubleCallback(cocos2d::Ref* pSender)
{
	Scene* pScene = ChooseDouble::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
}


Menu* MyMenu::create_button_single()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto button_single= MenuItemImage::create(
		"single(1).png",
		"single(1).png",CC_CALLBACK_1(MyMenu::menuSingleCallback, this));
	button_single->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_single->setPosition(Vec2(visibleSize / 2) - Vec2(200, 0));
	auto menu_bottle_single = Menu::create(button_single, NULL);
	return menu_bottle_single;
}

Menu* MyMenu::create_button_double()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto button_double = MenuItemImage::create(
		"double.png",
		"double.png", CC_CALLBACK_1(MyMenu::menuDoubleCallback, this));
	button_double->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button_double->setPosition(Vec2(visibleSize / 2) +Vec2(200, 0));
	auto menu_bottle_double = Menu::create(button_double, NULL);
	return menu_bottle_double;
}

Menu* ChooseScene::create_button_gun()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Label* label = Label::createWithTTF("Gun", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(50, visibleSize.height - 500));
	this->addChild(label);

	return nullptr;
}

void ChooseScene::create_button_scene()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Label* label = Label::createWithTTF("Scene", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(50, visibleSize.height - 900));
	this->addChild(label);

	_button_mountain->addClickEventListener([&](Ref* sender) {
		_scene_mountain_status = true;
		_scene_forest_status = false;
		});
	_button_forest->addClickEventListener([&](Ref* sender) {
		_scene_forest_status = true;
		_scene_mountain_status = false;
		});

	_button_mountain->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_mountain->setPosition(Vec2(400, visibleSize.height - 900));
	_button_forest->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_forest->setPosition(Vec2(800, visibleSize.height - 900));

	this->addChild(_button_mountain);
	this->addChild(_button_forest);
}



void ChooseScene::create_button_begin()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_button_begin->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_begin->setPosition(Vec2(visibleSize.width/2, visibleSize.height - 1200));

	_button_begin->addClickEventListener([&](Ref* sender) {
		if (_scene_forest_status == true) {
			static Scene* pScene = GameSceneForest::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
		}

		else {
			static Scene* pScene = GameSceneMountain::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
		}
		});
	this->addChild(_button_begin);
}




Scene* ChooseSingle::createScene()
{
	return ChooseSingle::create();
}

void ChooseSingle::SetBG()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_bg = Sprite::create("singlebg.jpg");
	_bg->setContentSize(Size(1400, 960));
	_bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_bg->setPosition(Vec2(visibleSize / 2));
}

Menu* ChooseSingle::create_button_char()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	Label* label = Label::createWithTTF("Character", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(50,visibleSize.height -100) );
	this->addChild(label);

	Sprite* sprite1 = Sprite::create("wmale.png");
	Sprite* sprite2 = Sprite::create("bmale.png");
	Sprite* sprite3 = Sprite::create("robot.png");
	sprite1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite3->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite1->setPosition(Vec2(50, visibleSize.height - 100));
	sprite2->setPosition(Vec2(300, visibleSize.height - 100));
	sprite3->setPosition(Vec2(600, visibleSize.height - 100));
	this->addChild(sprite1);
	this->addChild(sprite2);
	this->addChild(sprite3);

	_button_wmale->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_bmale->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_robot->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_wmale->setPosition(Vec2(50, visibleSize.height - 400));
	_button_bmale->setPosition(Vec2(300, visibleSize.height - 400));
	_button_robot->setPosition(Vec2(600, visibleSize.height - 400));



	return nullptr;
}

bool ChooseSingle::init()
{
	if (!Scene::create())
		return false;
	SetBG();
	this->addChild(_bg);
	create_button_scene();
}

Scene* ChooseDouble::createScene()
{
	return ChooseDouble::create();
}

void ChooseDouble::SetBG()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_bg = Sprite::create("doublebg.jpg");
	_bg->setContentSize(Size(1400, 960));
	_bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_bg->setPosition(Vec2(visibleSize / 2));
}

Menu* ChooseDouble::create_button_char()
{










	return nullptr;
}

bool ChooseDouble::init()
{
	if (!Scene::create())
		return false;
	SetBG();
	this->addChild(_bg);
	create_button_scene();
}
