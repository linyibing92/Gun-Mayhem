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
	_gamebg->setPosition(visibleSize / 2);
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

	auto mylayer = MyLayer::create();
	this->addChild(mylayer);

	auto myloadingbar = MyLoadingBar::create();
	this->addChild(myloadingbar);

	auto box = Box::create();
	this->addChild(box);
	box->drop();


	//林怡冰
	GunP92 Gun;
	//创建机器人角色
	Sprite* character_robot = Sprite::create("character_robot_idle.png");
	character_robot->setScale(1.0f);
	this->addChild(character_robot, 0);
	//隐藏精灵   
	character_robot->setVisible(true);

	//创建枪的角色
	Gun.spriteGun->setScale(0.2f);
	this->addChild(Gun.spriteGun, 0);
	this->addChild(Gun.sprite_bullet, 0);

	//创建炸弹的角色
	Bomb bomb;
	this->addChild(bomb.sprite_bomb);


	//实现通过键盘控制人物移动
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode code, Event* e)//创建一个事件监听器监听键盘事件(监视按的键位)
	{
		character_robot->setPosition(robot_position + offset);
		Gun.spriteGun->setPosition(robot_position.x + offset.x + 10, robot_position.y - 35 + offset.y);
		//机器人动画(向右)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_robot_walk.plist", "character_robot_walk.png");
		auto cache_right = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> robotmove_images_right;
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_idle.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk0.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk1.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk2.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk3.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk4.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk5.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk6.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk7.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_idle.png"));
		Animation* robotmove_right_animation = Animation::createWithSpriteFrames(robotmove_images_right, 0.5f / 10);
		//机器人动画(向左)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_robot_walk1.plist", "character_robot_walk1.png");
		auto cache_left = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> robotmove_images_left;
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_idle.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk01.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk11.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk21.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk31.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk41.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk51.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk61.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk71.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_idle.png"));
		Animation* robotmove_left_animation = Animation::createWithSpriteFrames(robotmove_images_left, 0.5f / 10);
		//机器人动画(向上)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_robot_Jump.plist", "character_robot_jump.png");
		auto cache_up = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> robotmove_images_up;
		robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_idle.png"));
		robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_jump.png"));
		robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_jump.png"));
		robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_jump.png"));
		robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_idle.png"));
		Animation* robotmove_up_animation = Animation::createWithSpriteFrames(robotmove_images_up, 0.5f / 5);

		FiniteTimeAction* move_up = MoveBy::create(0.25f, Vec2(0, 10.f));
		FiniteTimeAction* move_down = MoveBy::create(0.25f, Vec2(0, -10.f));
		FiniteTimeAction* move_left = MoveBy::create(0.25f, Vec2(-10.f, 0));
		FiniteTimeAction* move_right = MoveBy::create(0.25f, Vec2(10.f, 0));

		//枪的移动参数
		FiniteTimeAction* move_up_Gun = MoveBy::create(0.25f, Vec2(0, 10.f));
		FiniteTimeAction* move_down_Gun = MoveBy::create(0.25f, Vec2(0, -10.f));
		FiniteTimeAction* move_left_Gun = MoveBy::create(0.25f, Vec2(-10.f, 0));
		FiniteTimeAction* move_right_Gun = MoveBy::create(0.25f, Vec2(10.f, 0));


		switch (code)
		{
			case EventKeyboard::KeyCode::KEY_UP_ARROW:
				offset.y += 20.f;
				robot_up = Spawn::create(Repeat::create(move_left, 2), Animate::create(robotmove_up_animation), nullptr);
				Gun.spriteGun->runAction(Repeat::create(move_left_Gun, 2));
				character_robot->runAction(robot_up);
				break;
			case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
				offset.y -= 20.f;
				character_robot->runAction(Repeat::create(move_down, 2));
				Gun.spriteGun->runAction(Repeat::create(move_down_Gun, 2));
				break;
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
				offset.x -= 20.f;
				robot_left = Spawn::create(Repeat::create(move_left, 2), Animate::create(robotmove_left_animation), nullptr);
				character_robot->runAction(robot_left);
				//枪支移动
				//向左移动时，翻转不显示
				Gun.spriteGun->setFlippedX(false);
				Gunflip = GunLeft;
				Gun.spriteGun->runAction(Repeat::create(move_left_Gun, 2));
				break;
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
				offset.x += 20.f;
				robot_right = Spawn::create(Repeat::create(move_right, 2), Animate::create(robotmove_right_animation), nullptr);
				character_robot->runAction(robot_right);
				//枪支移动
				//向右移动时，翻转显示
				Gun.spriteGun->setFlippedX(true);
				Gunflip = GunRight;
				Gun.spriteGun->runAction(Repeat::create(move_right_Gun, 2));
				break;
			case EventKeyboard::KeyCode::KEY_SPACE:
				bomb.sprite_bomb->setPosition(robot_position.x + offset.x, robot_position.y + offset.y);
				bomb.bomb_move(Point(robot_position.x + offset.x, robot_position.y + offset.y));
				break;
			default:
				break;
		}
	};


	//创建事件监听器鼠标事件
	auto myMouseListener = EventListenerMouse::create();
	//鼠标左键按下
	myMouseListener->onMouseDown = [=](Event* event)
	{
		Gun.sprite_bullet->setPosition(robot_position.x + offset.x + 10, robot_position.y - 35 + offset.y);
		Gun.bulletmove(Gunflip);
	};



	//将事件监听器与场景绑定
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	return true;
}

//杨乐雅

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

	auto mylayer = MyLayer::create();
	this->addChild(mylayer);

	auto myloadingbar = MyLoadingBar::create();
	this->addChild(myloadingbar);
	return true;
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
	auto button_single = MenuItemImage::create(
		"single(1).png",
		"single(1).png", CC_CALLBACK_1(MyMenu::menuSingleCallback, this));
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
	button_double->setPosition(Vec2(visibleSize / 2) + Vec2(200, 0));
	auto menu_bottle_double = Menu::create(button_double, NULL);
	return menu_bottle_double;
}



void ChooseScene::create_button_gun()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Label* label = Label::createWithTTF("Gun", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(50, visibleSize.height - 385));

	Sprite* shou = Sprite::create("shou.png");
	shou->setPosition(Vec2(400, visibleSize.height - 400));
	Sprite* juji = Sprite::create("juji.png");
	juji->setPosition(Vec2(700, visibleSize.height - 400));
	Sprite* jiguan = Sprite::create("jiguan.png");
	jiguan->setPosition(Vec2(1000, visibleSize.height - 400));

	Label* label2 = Label::createWithTTF("Sorry,no choice here.You can only have pistols now.", "fonts/Marker Felt.ttf", 30);
	label2->setPosition(Vec2(450, visibleSize.height - 500));

	this->addChild(label);
	this->addChild(label2);
	this->addChild(shou);
	this->addChild(juji);
	this->addChild(jiguan);

}

void ChooseScene::create_button_scene()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Label* label = Label::createWithTTF("Scene", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(50, visibleSize.height - 650));
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
	_button_mountain->setPosition(Vec2(400, visibleSize.height - 650));
	_button_forest->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_forest->setPosition(Vec2(800, visibleSize.height - 650));

	this->addChild(_button_mountain);
	this->addChild(_button_forest);
}



void ChooseScene::create_button_begin()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_button_begin->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_begin->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 850));

	_button_begin->addClickEventListener([&](Ref* sender) {
		if (_scene_forest_status == true) {
			Scene* pScene = GameSceneForest::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
		}
		else {
			Scene* pScene = GameSceneMountain::createScene();
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
	label->setPosition(Vec2(80, visibleSize.height - 100));
	this->addChild(label);

	Button* button1 = Button::create("wmale2.png", "wmale(1).png", "wmale.png");
	Button* button2 = Button::create("bmale.png", "bmale(1).png", "bmale.png");
	Button* button3 = Button::create("robot.png", "robot(1).png", "robot.png");
	button1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button3->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button1->setPosition(Vec2(350, visibleSize.height - 100));
	button2->setPosition(Vec2(650, visibleSize.height - 100));
	button3->setPosition(Vec2(950, visibleSize.height - 100));
	this->addChild(button1);
	this->addChild(button2);
	this->addChild(button3);

	return nullptr;
}

bool ChooseSingle::init()
{
	if (!Scene::create())
		return false;
	SetBG();
	this->addChild(_bg);
	create_button_scene();
	create_button_gun();
	create_button_char();
	create_button_begin();
	auto layer = MyLayer::create();
	this->addChild(layer);
	return true;
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

	auto visibleSize = Director::getInstance()->getVisibleSize();

	Label* label = Label::createWithTTF("Character", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(80, visibleSize.height - 100));
	this->addChild(label);

	Button* button1 = Button::create("wmale2.png", "wmale(1).png", "wmale.png");
	Button* button2 = Button::create("bmale.png", "bmale(1).png", "bmale.png");
	Button* button3 = Button::create("robot.png", "robot(1).png", "robot.png");
	button1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button3->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button1->setPosition(Vec2(350, visibleSize.height - 100));
	button2->setPosition(Vec2(650, visibleSize.height - 100));
	button3->setPosition(Vec2(950, visibleSize.height - 100));

	this->addChild(button1);
	this->addChild(button2);
	this->addChild(button3);

	return nullptr;

}

bool ChooseDouble::init()
{
	if (!Scene::create())
		return false;
	SetBG();
	this->addChild(_bg);
	create_button_scene();
	create_button_gun();
	create_button_char();
	create_button_begin();
	auto layer = MyLayer::create();
	this->addChild(layer);
	return true;
}
