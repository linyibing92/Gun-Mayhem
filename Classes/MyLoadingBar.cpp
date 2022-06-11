#include "MyLoadingBar.h"

bool MyLoadingBar::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if(!Layer::create())
		return false;
	auto label1 = Label::createWithTTF("P1:HP", "fonts/Marker Felt.ttf", 30);
	label1->setPosition(Vec2(30, visibleSize.height - 20));
	this->addChild(label1);
	auto label2 = Label::createWithTTF("P2:HP", "fonts/Marker Felt.ttf", 30);
	label2->setPosition(Vec2(630, visibleSize.height - 20));
	this->addChild(label2);
	_myLoadingBar_1->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	_myLoadingBar_1->setPosition(Vec2(10,visibleSize.height-40));
	_myLoadingBar_1->loadTexture("myloadingbar(2).png");
	this->scheduleUpdate();//启用定时器回调函数
	_myLoadingBar_1->setPercent(HP_robot);
	_myLoadingBar_1->setDirection(LoadingBar::Direction::LEFT);
	this->addChild(_myLoadingBar_1);
	_myLoadingBar_2->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	_myLoadingBar_2->setPosition(Vec2(610, visibleSize.height - 40));
	_myLoadingBar_2->loadTexture("myloadingbar(2).png");

	//this->scheduleUpdate();//启用定时器回调函数

	_myLoadingBar_2->setPercent(HP_wmale);
	_myLoadingBar_2->setDirection(LoadingBar::Direction::LEFT);
	this->addChild(_myLoadingBar_2);





	return true;
}

void MyLoadingBar::setHP_wmale(int harm)
{
	HP_wmale = HP_wmale-harm;
}

float MyLoadingBar::getHP_robot()
{
	return HP_robot;
}

float MyLoadingBar::getHP_wmale()
{
	return HP_wmale;
}

void MyLoadingBar::setHP_robot(int harm)
{
	HP_robot = HP_robot-harm;
}

void MyLoadingBar::update(float delta)
{
	_myLoadingBar_1->setPercent(HP_robot);
	_myLoadingBar_2->setPercent(HP_wmale);
}
