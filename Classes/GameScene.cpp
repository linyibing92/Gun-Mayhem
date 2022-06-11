#include<iostream>
#include "audio/include/AudioEngine.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"
USING_NS_CC;
Scene* GameSceneMountain::createScene()
{
	return GameSceneMountain::create();
}

int GameSceneMountain::_boxes_type[15] = {0};
int GameSceneMountain::_boxes_positionx[15] = {0};

Box* GameSceneMountain::box = Box::create();

bool GameSceneMountain::init()
{
	if (!Scene::initWithPhysics())
		return false;


	//设置物理世界速度
	//this->getPhysicsWorld()->setSpeed(1.2);
	//设置背景图片

	auto visibleSize = Director::getInstance()->getVisibleSize();
	_gamebg->setContentSize(Size(1400, 960));
	_gamebg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_gamebg->setPosition(visibleSize / 2);
	this->addChild(_gamebg);

//设置lable1-6的所有静态刚体
	_land1->setPosition(Vec2(230, 350));
	_land1->setTag(3);
	auto body1 = PhysicsBody::createBox(_land1->getContentSize(), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	body1->setDynamic(false);
	_land1->setPhysicsBody(body1);
	body1->setContactTestBitmask(0);

	_land2->setPosition(Vec2(970, 280));
	_land2->setTag(3);
	auto body2 = PhysicsBody::createBox(_land2->getContentSize(), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	body2->setDynamic(false);
	_land2->setPhysicsBody(body2);
	body2->setContactTestBitmask(0);

	_land3->setPosition(Vec2(700, 170));
	_land3->setTag(3);
	auto body3 = PhysicsBody::createBox(_land3->getContentSize(), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	body3->setDynamic(false);
	_land3->setPhysicsBody(body3);
	body3->setContactTestBitmask(0);

	_land4->setPosition(Vec2(1170, 500));
	_land4->setTag(3);
	auto body4 = PhysicsBody::createBox(_land4->getContentSize(), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	body4->setDynamic(false);
	_land4->setPhysicsBody(body4);
	body4->setContactTestBitmask(0);

	_land5->setPosition(Vec2(750, 620));
	_land5->setTag(3);
	auto body5 = PhysicsBody::createBox(_land5->getContentSize(), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	body5->setDynamic(false);
	_land5->setPhysicsBody(body5);
	body5->setContactTestBitmask(0);


	_land6->setPosition(Vec2(550, 450));
	_land6->setTag(3);
	auto body6 = PhysicsBody::createBox(_land6->getContentSize(), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	body6->setDynamic(false);
	_land6->setPhysicsBody(body6);
	body6->setContactTestBitmask(0);





	this->addChild(_land1);
	this->addChild(_land2);
	this->addChild(_land3);
	this->addChild(_land4);
	this->addChild(_land5);
	this->addChild(_land6);





	//加入血条
	this->scheduleUpdate();//���ö�ʱ��ص���



	//Ѫ����ʾ
	auto myloadingbar = MyLoadingBar::create();
	this->addChild(myloadingbar);
	if (myloadingbar->getHP_wmale() <= 0|| myloadingbar->getHP_robot()<=0) {
		auto layerend = MyLayerWinner::create();
		this->addChild(layerend);
	}



	box = Box::create();
    this->addChild(box);



	//每十秒掉落一个宝箱，最多十五个


	this->schedule([&](float dlt) {
		static int drop_times = 0;
		if (drop_times > 15) {
			this->unschedule("schedule");
			return;
		}
		else {
			if(drop_times!=0)
			    box->removeAllChildren();

			box->drop(_boxes_type,_boxes_positionx,_boxes_positiony,drop_times);

			++drop_times;
		}
		}, 10.f, "schedule");


	//�����ɫ
	auto wmale=CharacterWmale::create();
	this->addChild(wmale);
	//�����˽�ɫ
	auto robot = CharacterRobot::create();
	this->addChild(robot);

	auto gun_wmale = GunLayer_wmale::create();
	this->addChild(gun_wmale);

	auto gun_robot = GunLayer_robot::create();
	this->addChild(gun_robot);


	//右上角菜单
	auto mylayer = MyLayer::create();
	this->addChild(mylayer,100);

	//设置掩体
	robot->body->setContactTestBitmask(1);
	robot->body->setCategoryBitmask(1);
	robot->body->setCollisionBitmask(1);
	robot->body->setContactTestBitmask(1);

	wmale->body->setContactTestBitmask(2);
	wmale->body->setCategoryBitmask(2);
	wmale->body->setCollisionBitmask(2);
	wmale->body->setContactTestBitmask(2);

	gun_wmale->body_gun1->setContactTestBitmask(8);
	gun_wmale->body_gun1->setCategoryBitmask(8);
	gun_wmale->body_gun1->setCollisionBitmask(8);
	gun_wmale->body_gun1->setContactTestBitmask(8);
	gun_robot->body_gun1->setContactTestBitmask(8);
	gun_robot->body_gun1->setCategoryBitmask(8);
	gun_robot->body_gun1->setCollisionBitmask(8);
	gun_robot->body_gun1->setContactTestBitmask(8);

	gun_wmale->body_gun2->setContactTestBitmask(8);
	gun_wmale->body_gun2->setCategoryBitmask(8);
	gun_wmale->body_gun2->setCollisionBitmask(8);
	gun_wmale->body_gun2->setContactTestBitmask(8);
	gun_robot->body_gun2->setContactTestBitmask(8);
	gun_robot->body_gun2->setCategoryBitmask(8);
	gun_robot->body_gun2->setCollisionBitmask(8);
	gun_robot->body_gun2->setContactTestBitmask(8);

	gun_wmale->body_gun3->setContactTestBitmask(8);
	gun_wmale->body_gun3->setCategoryBitmask(8);
	gun_wmale->body_gun3->setCollisionBitmask(8);
	gun_wmale->body_gun3->setContactTestBitmask(8);
	gun_robot->body_gun3->setContactTestBitmask(8);
	gun_robot->body_gun3->setCategoryBitmask(8);
	gun_robot->body_gun3->setCollisionBitmask(8);
	gun_robot->body_gun3->setContactTestBitmask(8);

	gun_wmale->body_bullet1->setContactTestBitmask(1);
	gun_wmale->body_bullet1->setCategoryBitmask(1);
	gun_wmale->body_bullet1->setCollisionBitmask(1);
	gun_wmale->body_bullet1->setContactTestBitmask(1);
	gun_wmale->body_bullet2->setContactTestBitmask(1);
	gun_wmale->body_bullet2->setCategoryBitmask(1);
	gun_wmale->body_bullet2->setCollisionBitmask(1);
	gun_wmale->body_bullet2->setContactTestBitmask(1);
	gun_wmale->body_bullet3->setContactTestBitmask(1);
	gun_wmale->body_bullet3->setCategoryBitmask(1);
	gun_wmale->body_bullet3->setCollisionBitmask(1);
	gun_wmale->body_bullet3->setContactTestBitmask(1);

	gun_wmale->body_bomb->setContactTestBitmask(1);
	gun_wmale->body_bomb->setCategoryBitmask(1);
	gun_wmale->body_bomb->setCollisionBitmask(1);
	gun_wmale->body_bomb->setContactTestBitmask(1);

	gun_robot->body_bullet1->setContactTestBitmask(2);
	gun_robot->body_bullet1->setCategoryBitmask(2);
	gun_robot->body_bullet1->setCollisionBitmask(2);
	gun_robot->body_bullet1->setContactTestBitmask(2);
	gun_robot->body_bullet2->setContactTestBitmask(2);
	gun_robot->body_bullet2->setCategoryBitmask(2);
	gun_robot->body_bullet2->setCollisionBitmask(2);
	gun_robot->body_bullet2->setContactTestBitmask(2);
	gun_robot->body_bullet3->setContactTestBitmask(2);
	gun_robot->body_bullet3->setCategoryBitmask(2);
	gun_robot->body_bullet3->setCollisionBitmask(2);
	gun_robot->body_bullet3->setContactTestBitmask(2);

	gun_robot->body_bomb->setContactTestBitmask(2);
	gun_robot->body_bomb->setCategoryBitmask(2);
	gun_robot->body_bomb->setCollisionBitmask(2);


	// ע����ײ�����¼�
	EventListenerPhysicsContact* hitListener = EventListenerPhysicsContact::create();
	hitListener->onContactBegin = [=](PhysicsContact& contact)
	{
		auto body_1 = (Sprite*)contact.getShapeA()->getBody()->getNode(); //������ײ������1����gun_wmale���ӵ���robot
		auto body_2 = (Sprite*)contact.getShapeB()->getBody()->getNode(); //������ײ������2����gun_robot���ӵ���wmale


		//�ӵ�����
		if (body_1->getTag() == 1) {
			myloadingbar->setHP_robot(gun_wmale->bullet_attack());
		}
		if (body_2->getTag() == 2) {
			myloadingbar->setHP_wmale(gun_robot->bullet_attack());
		}

		return true;
	};
	Director::getInstance()->getEventDispatcher()
		->addEventListenerWithSceneGraphPriority(hitListener, this);

int* GameSceneMountain::getBoxesType()
{
	return _boxes_type;
}

int* GameSceneMountain::getBoxesPositionx()
{
	return _boxes_positionx;
}

int* GameSceneMountain::getBoxesPositiony()
{
	return  _boxes_positiony;
}

Box* GameSceneMountain::getBoxes()
{
	return box;
}




Scene* GameSceneForest::createScene()
{
	return GameSceneForest::create();
}


bool GameSceneForest::init()//与mountainscene类似

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



void MyMenu::menuSingleCallback(cocos2d::Ref* pSender)//single按钮的回调函数
{
	Scene* pScene = ChooseSingle::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
}

void MyMenu::menuDoubleCallback(cocos2d::Ref* pSender)//double按钮的回调函数
{
	Scene* pScene = ChooseDouble::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
}



Menu* MyMenu::create_button_single()//创建single按钮
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


Menu* MyMenu::create_button_double()//创建double按钮
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




void ChooseScene::create_button_gun()//创建枪的按钮（但无事件监听器，类似精灵）
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Label* label = Label::createWithTTF("Gun", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(50, visibleSize.height - 415));


	Sprite* shou = Sprite::create("shou.png");

	shou->setPosition(Vec2(400, visibleSize.height - 430));
	Sprite* juji = Sprite::create("juji.png");
	juji->setPosition(Vec2(700, visibleSize.height - 430));
	Sprite* jiguan = Sprite::create("jiguan.png");
	jiguan->setPosition(Vec2(1000, visibleSize.height - 430));

	Label* label2 = Label::createWithTTF("Sorry,no choice here.You can only have pistols now.", "fonts/Marker Felt.ttf", 30);
	label2->setPosition(Vec2(450, visibleSize.height - 520));

	this->addChild(label);
	//this->addChild(label2);
	this->addChild(shou);
	this->addChild(juji);
	this->addChild(jiguan);

}


void ChooseScene::create_button_scene()//创建mountain的按钮（但无事件监听器，类似精灵）
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
	//this->addChild(_button_forest);
}




void ChooseScene::create_button_begin()//创建开始的按钮
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_button_begin->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_button_begin->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 850));

	_button_begin->addClickEventListener([&](Ref* sender) {
	/*	if (_scene_forest_status == true) {
			Scene* pScene = GameSceneForest::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
		}
		else {
			Scene* pScene = GameSceneMountain::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
		}*/
		Scene* pScene = GameSceneMountain::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, pScene));
		});
	this->addChild(_button_begin);
}


Scene* ChooseSingle::createScene()
{
	return ChooseSingle::create();
}


void ChooseSingle::SetBG()//设置背景图片
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_bg = Sprite::create("singlebg.jpg");
	_bg->setContentSize(Size(1400, 960));
	_bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_bg->setPosition(Vec2(visibleSize / 2));
}


Menu* ChooseSingle::create_button_char()//设置人物按钮（但无事件监听器，类似精灵）
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	Label* label = Label::createWithTTF("Character", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(80, visibleSize.height - 100));
	this->addChild(label);

	Label* label2=Label::createWithTTF("P2","fonts/Marker Felt.ttf", 40);
	label2->setPosition(Vec2(660, visibleSize.height - 35));
	this->addChild(label2);

	Label* label3 = Label::createWithTTF("Robot", "fonts/Marker Felt.ttf", 40);
	label3->setPosition(Vec2(370, visibleSize.height - 35));
	this->addChild(label3);


	Label*label4= Label::createWithTTF("move:W/A/S/D\nbullet:J\nbomb:K\npick:L","fonts/Marker Felt.ttf", 30);
	label4->setPosition(Vec2(670, visibleSize.height - 255));
	this->addChild(label4);


	Button* button1 = Button::create("wmale.png", "wmale.png", "wmale.png");
	Button* button2 = Button::create("robot.png", "robot.png", "robot.png");
	Button* button3 = Button::create("bmale.png", "bmale.png", "bmale.png");
	button1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button3->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button1->setPosition(Vec2(650, visibleSize.height - 100));
	button2->setPosition(Vec2(350, visibleSize.height - 100));
	button3->setPosition(Vec2(950, visibleSize.height - 100));
	this->addChild(button1);
	this->addChild(button2);
	//this->addChild(button3);

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


void ChooseDouble::SetBG()//设置背景图片
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_bg = Sprite::create("doublebg.jpg");
	_bg->setContentSize(Size(1400, 960));
	_bg->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	_bg->setPosition(Vec2(visibleSize / 2));
}


Menu* ChooseDouble::create_button_char()//设置人物按钮（但无事件监听器，类似精灵）
{

	auto visibleSize = Director::getInstance()->getVisibleSize();

	Label* label = Label::createWithTTF("Character", "fonts/Marker Felt.ttf", 40);
	label->setPosition(Vec2(80, visibleSize.height - 100));
	this->addChild(label);

	Label* label2 = Label::createWithTTF("P1", "fonts/Marker Felt.ttf", 40);
	label2->setPosition(Vec2(360, visibleSize.height - 35));
	this->addChild(label2);

	Label* label3 = Label::createWithTTF("P2", "fonts/Marker Felt.ttf", 40);
	label3->setPosition(Vec2(670, visibleSize.height - 35));
	this->addChild(label3);


	Label* label4 = Label::createWithTTF("move:W/A/S/D\nbullet:J\nbomb:K\npick:L", "fonts/Marker Felt.ttf", 30);
	label4->setPosition(Vec2(670, visibleSize.height - 255));
	this->addChild(label4);

	Label* label5 = Label::createWithTTF("move:arrow keys\nbullet:mouse\nbomb:space\npick:enter", "fonts/Marker Felt.ttf", 30);
	label5->setPosition(Vec2(370, visibleSize.height - 255));
	this->addChild(label5);

	Button* button1 = Button::create("wmale2.png", "wmale.png", "wmale.png");
	Button* button2 = Button::create("robot.png", "robot.png", "robot.png");
	Button* button3 = Button::create("bmale.png", "bmale.png", "bmale.png");
	button1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button3->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button1->setPosition(Vec2(650, visibleSize.height - 100));
	button2->setPosition(Vec2(350, visibleSize.height - 100));
	button3->setPosition(Vec2(950, visibleSize.height - 100));

	this->addChild(button1);
	this->addChild(button2);
	//this->addChild(button3);

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