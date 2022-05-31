#include "SelectScene.h"
#include"GameScene.h"
Scene* SelectScene::createScene()
{
	return SelectScene::create();
}

bool SelectScene::init()
{
	if (!Scene::create())return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto sprite_bg = Sprite::create("bg(1)(1).jpg");
	sprite_bg->setContentSize(Size(1400, 960));
	sprite_bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite_bg->setPosition(Vec2(visibleSize/2));
	this->addChild(sprite_bg, 0);


	auto label_title = Label::createWithTTF("Let's create a room!\n\nPls choose a mode: ", "fonts/Marker Felt.ttf", 80);
	label_title->setPosition(Vec2(visibleSize / 2)-Vec2(50,-250));
	this->addChild(label_title);

	MyMenu m1;
	Menu* menu_button_single = m1.create_button_single();
	menu_button_single->setPosition(Vec2::ZERO);
	this->addChild(menu_button_single);

	Menu* menu_button_double = m1.create_button_double();
	menu_button_double->setPosition(Vec2::ZERO);
	this->addChild(menu_button_double);

	auto layer = MyLayer::create(); 
	this->addChild(layer);

	return true;
}
