
#include "Gun.h"
USING_NS_CC;

//子弹移动函数
void GunM249::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveTo = MoveBy::create(0.5, Point(240, 0));

		auto bulletHide = Hide::create();//执行完动作后隐藏精灵
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveTo, bulletHide, NULL);
		//设置重复动作，完成机关枪的多次射击
		sprite_bullet->runAction(seq);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(0.5, Point(-240, 0));
		auto bulletHide = Hide::create();//执行完动作后隐藏精灵
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveToLeft, bulletHide, NULL);
		//设置重复动作，完成机关枪的多次射击
		sprite_bullet->runAction(seq);
	}

}

void GunP92::bulletmove(int _flip) const
{

	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveToRight = MoveBy::create(1, Point(200, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveToRight, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-200, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveToLeft, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
}
void Gun98K::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveToRight = MoveBy::create(0.5, Point(480, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveToRight, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(0.5, Point(-480, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveToLeft, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
}

//获取武器攻击力·函数
int GunM249::GetWeaponpower()
{
	return GunM249::MyPower;
}

int GunP92::GetWeaponpower()
{
	return GunP92::MyPower;
}

int Gun98K::GetWeaponpower()
{
	return Gun98K::MyPower;
}



//攻击函数
int GunLayer_robot::bullet_attack()
{
	int harm = 0;
	if (gunp92.GetweaponState())
		harm = gunp92.GetWeaponpower();
	else if (gunm249.GetweaponState())
		harm = gunm249.GetWeaponpower();
	else if (gun98k.GetweaponState())
		harm = gun98k.GetWeaponpower();
	else if (bomb.GetWeaponpower())
		harm = bomb.GetWeaponpower();
	else
		harm = 0;
	return harm;

}



int GunLayer_wmale::bullet_attack()
{
	int harm = 0;
	if (gunp92.GetweaponState())
		harm = gunp92.GetWeaponpower();
	else if (gunm249.GetweaponState())
		harm = gunm249.GetWeaponpower();
	else if (gun98k.GetweaponState())
		harm = gun98k.GetWeaponpower();
	else if (bomb.GetWeaponpower())
		harm = bomb.GetWeaponpower();
	else
		harm = 0;
	return harm;

}




//设置人物wmale的枪支图层
bool GunLayer_wmale::init()
{
	if (!Scene::create())
		return false;

	_land5->setPosition(Vec2(750, 620));
	this->scheduleUpdate();

	//创建枪的角色
	gunp92.spriteGun->setScale(0.25f);
	gun98k.spriteGun->setScale(0.25f);
	gunm249.spriteGun->setScale(0.25f);
	this->addChild(gunp92.spriteGun);
	this->addChild(gun98k.spriteGun);
	this->addChild(gunm249.spriteGun);

	gunp92.spriteGun->setPhysicsBody(body_gun1);
	gun98k.spriteGun->setPhysicsBody(body_gun2);
	gunm249.spriteGun->setPhysicsBody(body_gun3);

	//子弹
	this->addChild(gunp92.sprite_bullet);
	this->addChild(gun98k.sprite_bullet);
	this->addChild(gunm249.sprite_bullet);
	//刚体设置
	gunp92.sprite_bullet->setTag(1);
	body_bullet1->setGravityEnable(false);
	gunp92.sprite_bullet->setPhysicsBody(body_bullet1);

	gun98k.sprite_bullet->setTag(1);
	body_bullet2->setGravityEnable(false);
	gun98k.sprite_bullet->setPhysicsBody(body_bullet2);

	gunm249.sprite_bullet->setTag(1);
	body_bullet3->setGravityEnable(false);
	gunm249.sprite_bullet->setPhysicsBody(body_bullet3);

	//设置枪支状态为picked
	gunp92.SetWeaponState(true);
	gun98k.SetWeaponState(false);
	gunm249.SetWeaponState(false);
	bomb.SetWeaponState(false);

	//创建炸弹的角色
	this->addChild(bomb.sprite_bomb);
	//刚体设置
	bomb.sprite_bomb->setTag(1);
	body_bomb->setGravityEnable(false);
	bomb.sprite_bomb->setPhysicsBody(body_bomb);

	//设置精灵起始位置在最高障碍正中间 
	gun_position = _land5->getPosition() + Vec2(_land5->getContentSize().width / 5, _land5->getContentSize().height / 2);


	//隐藏精灵
	gunp92.spriteGun->setVisible(true);
	gunp92.spriteGun->setPosition(gun_position + offset);
	gun98k.spriteGun->setVisible(false);
	gun98k.spriteGun->setPosition(gun_position + offset);
	gunm249.spriteGun->setVisible(false);
	gunm249.spriteGun->setPosition(gun_position + offset);
	bomb.sprite_bomb->setVisible(false);
	bomb.sprite_bomb->setPosition(0, 0);

	//实现通过键盘控制人物移动
	auto keyListener = EventListenerKeyboard::create();//创建一个事件监听器监听键盘事件(监视键位的按下和松开)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_W||keycode == EventKeyboard::KeyCode::KEY_CAPITAL_W)
		{
			//枪械向上向下
			FiniteTimeAction* gun_jump1 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			FiniteTimeAction* gun_jump2 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			FiniteTimeAction* gun_jump3 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			//FiniteTimeAction* gun_jump4 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			gunp92.spriteGun->runAction(gun_jump1);
			gun98k.spriteGun->runAction(gun_jump2);
			gunm249.spriteGun->runAction(gun_jump3);
			//bomb.sprite_bomb->runAction(gun_jump4);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_S|| keycode == EventKeyboard::KeyCode::KEY_CAPITAL_S)
		{
			FiniteTimeAction* gun_down1 = MoveBy::create(0.5f, Vec2(0, -40.f));
			FiniteTimeAction* gun_down2 = MoveBy::create(0.5f, Vec2(0, -40.f));
			FiniteTimeAction* gun_down3 = MoveBy::create(0.5f, Vec2(0, -40.f));
			//FiniteTimeAction* gun_down4 = MoveBy::create(0.5f, Vec2(0, -40.f));
			offset.y -= 20.f;
			gunp92.spriteGun->runAction(gun_down1);
			gun98k.spriteGun->runAction(gun_down2);
			gunm249.spriteGun->runAction(gun_down3);
			//bomb.sprite_bomb->runAction(gun_down4);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_J || keycode == EventKeyboard::KeyCode::KEY_CAPITAL_J) //将按键J作为人物wmale的子弹射击方式
		{
			auto soundbullet = AudioEngine::play2d("bullet.mp3", false);
			if (gunp92.GetweaponState()) {
				gunp92.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
				gunp92.bulletmove(Gunflip);
			}
			if (gun98k.GetweaponState()) {
				gun98k.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
				gun98k.bulletmove(Gunflip);
			}
			if (gunm249.GetweaponState()) {
				for (int i = 0; i < 3; i++) {
					gunm249.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
					gunm249.bulletmove(Gunflip);
				}
			}
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_K||keycode == EventKeyboard::KeyCode::KEY_CAPITAL_K) //按键K作为人物wmale炸弹的投放
		{
			//设置炸弹状态 
			if (bomb.GetweaponState() == true) {
				bomb.sprite_bomb->setPosition(gunp92.spriteGun->getPosition());
				bomb.bomb_move(gunp92.spriteGun->getPosition(),Gunflip);
			};
		}
	};
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	//宝箱拾取监听器
	GameSceneMountain scene;
	auto boxes = scene.getBoxes();
	int* boxes_type = scene.getBoxesType();
	int* boxes_positionx = scene.getBoxesPositionx();
	int* boxes_positiony = scene.getBoxesPositiony();
	auto mykeyListener = EventListenerKeyboard::create();
	mykeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		if (keycode == EventKeyboard::KeyCode::KEY_L || keycode == EventKeyboard::KeyCode::KEY_CAPITAL_L) {
			float gun_positionx = gunp92.spriteGun->getPosition().x;
			float gun_positiony = gunp92.spriteGun->getPosition().y;
			int i = 0;
			for (; i < 15; ++i) {
				if (fabs(gun_positionx - boxes_positionx[i]) < 50&& fabs(gun_positiony - boxes_positiony[i]) < 70) {
					if (boxes_type[i] == 1) {
						gunp92.SetWeaponState(false);
						gun98k.SetWeaponState(true);
						gunm249.SetWeaponState(false);
						bomb.SetWeaponState(false);
						gunp92.spriteGun->setVisible(false);
						gun98k.spriteGun->setVisible(true);
						gunm249.spriteGun->setVisible(false);
						bomb.sprite_bomb->setVisible(false);
					}
					else if (boxes_type[i] == 2) {
						gunp92.SetWeaponState(false);
						gun98k.SetWeaponState(false);
						gunm249.SetWeaponState(true);
						bomb.SetWeaponState(false);
						gunp92.spriteGun->setVisible(false);
						gun98k.spriteGun->setVisible(false);
						gunm249.spriteGun->setVisible(true);
						bomb.sprite_bomb->setVisible(false);
					}
					else if (boxes_type[i] == 3) {
						gunp92.SetWeaponState(false);
						gun98k.SetWeaponState(false);
						gunm249.SetWeaponState(false);
						bomb.SetWeaponState(true);
						gunp92.spriteGun->setVisible(false);
						gun98k.spriteGun->setVisible(false);
						gunm249.spriteGun->setVisible(false);
						bomb.sprite_bomb->setVisible(false);
					}
					boxes->removeAllChildren();
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mykeyListener, this);

	return  true;
}



void GunLayer_wmale::update(float delta)
{
	auto moveBy_left1 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right1 = MoveBy::create(0.7f, Vec2(5.f, 0));
	auto moveBy_left2 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right2 = MoveBy::create(0.7f, Vec2(5.f, 0));
	auto moveBy_left3 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right3 = MoveBy::create(0.7f, Vec2(5.f, 0));
	//auto moveBy_left4 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	//auto moveBy_right4 = MoveBy::create(0.7f, Vec2(5.f, 0));
	if (keyMap[EventKeyboard::KeyCode::KEY_A])
	{
		offset.x -= 5.f;
		//枪口方向翻转
		Gunflip = GunLeft;
		gunp92.spriteGun->setFlippedX(false);
		gunp92.spriteGun->runAction(moveBy_left1);
		gun98k.spriteGun->setFlippedX(false);
		gun98k.spriteGun->runAction(moveBy_left2);
		gunm249.spriteGun->setFlippedX(false);
		gunm249.spriteGun->runAction(moveBy_left3);
		bomb.sprite_bomb->setFlippedX(false);
		//bomb.sprite_bomb->runAction(moveBy_left4);
	}
	else if (keyMap[EventKeyboard::KeyCode::KEY_D])
	{
		offset.x += 5.f;
		Gunflip = GunRight;
		gunp92.spriteGun->setFlippedX(true);
		gunp92.spriteGun->runAction(moveBy_right1);
		gun98k.spriteGun->setFlippedX(true);
		gun98k.spriteGun->runAction(moveBy_right2);
		gunm249.spriteGun->setFlippedX(true);
		gunm249.spriteGun->runAction(moveBy_right3);
		bomb.sprite_bomb->setFlippedX(true);
		//bomb.sprite_bomb->runAction(moveBy_right4);
	}
}

void GunLayer_wmale::falling_judge()
{
	_land1->setPosition(Vec2(230, 350));
	_land2->setPosition(Vec2(970, 280));
	_land3->setPosition(Vec2(700, 170));
	_land4->setPosition(Vec2(1170, 500));
	_land5->setPosition(Vec2(750, 620));
	_land6->setPosition(Vec2(550, 450));

}



//设置人物robot的枪支图层
bool GunLayer_robot::init()
{
	if (!Scene::create())
		return false;

	_land5->setPosition(Vec2(750, 620));
	this->scheduleUpdate();

	//创建枪的角色
	gunp92.spriteGun->setScale(0.25f);
	this->addChild(gunp92.spriteGun);
	gunp92.spriteGun->setPhysicsBody(body_gun1);

	gun98k.spriteGun->setScale(0.25f);
	this->addChild(gun98k.spriteGun);
	gun98k.spriteGun->setPhysicsBody(body_gun2);

	gunm249.spriteGun->setScale(0.25f);
	this->addChild(gunm249.spriteGun);
	gunm249.spriteGun->setPhysicsBody(body_gun3);


	//子弹
	this->addChild(gunp92.sprite_bullet);
	this->addChild(gunm249.sprite_bullet);
	this->addChild(gun98k.sprite_bullet);
	//刚体设置
	gunp92.sprite_bullet->setTag(2);
	body_bullet1->setGravityEnable(false);
	gunp92.sprite_bullet->setPhysicsBody(body_bullet1);

	gun98k.sprite_bullet->setTag(2);
	body_bullet2->setGravityEnable(false);
	gun98k.sprite_bullet->setPhysicsBody(body_bullet2);

	gunm249.sprite_bullet->setTag(2);
	body_bullet3->setGravityEnable(false);
	gunm249.sprite_bullet->setPhysicsBody(body_bullet3);

	//设置枪支状态为picked
	gunp92.SetWeaponState(true);
	gun98k.SetWeaponState(false);
	gunm249.SetWeaponState(false);
	bomb.SetWeaponState(false);

	//创建炸弹的角色
	this->addChild(bomb.sprite_bomb);
	//刚体设置
	bomb.sprite_bomb->setTag(2);
	body_bomb->setGravityEnable(false);
	bomb.sprite_bomb->setPhysicsBody(body_bomb);

	//设置精灵起始位置在最高障碍正中间 
	gun_position = _land5->getPosition() + Vec2(0, _land5->getContentSize().height / 2);


	//隐藏精灵
	gunp92.spriteGun->setVisible(true);
	gunp92.spriteGun->setPosition(gun_position + offset);
	gun98k.spriteGun->setVisible(false);
	gun98k.spriteGun->setPosition(gun_position + offset);
	gunm249.spriteGun->setVisible(false);
	gunm249.spriteGun->setPosition(gun_position + offset);
	bomb.sprite_bomb->setVisible(false);
	bomb.sprite_bomb->setPosition(0, 0);


	//实现通过键盘控制人物移动
	auto keyListener = EventListenerKeyboard::create();//创建一个事件监听器监听键盘事件(监视键位的按下和松开)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			//枪械向上向下
			FiniteTimeAction* gun_jump1 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			FiniteTimeAction* gun_jump2 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			FiniteTimeAction* gun_jump3 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			FiniteTimeAction * gun_jump4 = JumpBy::create(0.5, Vec2(0, 0), 120, 1);
			gunp92.spriteGun->runAction(gun_jump1);
			gun98k.spriteGun->runAction(gun_jump2);
			gunm249.spriteGun->runAction(gun_jump3);
			//bomb.sprite_bomb->runAction(gun_jump4);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			FiniteTimeAction* gun_down1 = MoveBy::create(0.5f, Vec2(0, -40.f));
			FiniteTimeAction* gun_down2 = MoveBy::create(0.5f, Vec2(0, -40.f));
			FiniteTimeAction* gun_down3 = MoveBy::create(0.5f, Vec2(0, -40.f));
			//FiniteTimeAction* gun_down4 = MoveBy::create(0.5f, Vec2(0, -40.f));
			offset.y -= 20.f;
			gunp92.spriteGun->runAction(gun_down1);
			gunm249.spriteGun->runAction(gun_down2);
			gun98k.spriteGun->runAction(gun_down3);
			//bomb.sprite_bomb->runAction(gun_down4);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_SPACE) 
		{
			//设置炸弹状态 
			if (bomb.GetweaponState() == true) {
                bomb.sprite_bomb->setPosition(gunp92.spriteGun->getPosition());
			    bomb.bomb_move(gunp92.spriteGun->getPosition(),Gunflip);
			};
			
		}
	};
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);


	//创建事件监听器鼠标事件——控制子弹射击
	auto myMouseListener = EventListenerMouse::create();
	//鼠标左键按下
	myMouseListener->onMouseDown = [=](Event* event)
	{
		auto soundbullet = AudioEngine::play2d("bullet.mp3", false);
		if (gunp92.GetweaponState()) {
			gunp92.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
			gunp92.bulletmove(Gunflip);
		}
		if (gun98k.GetweaponState()) {
			gun98k.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
			gun98k.bulletmove(Gunflip);
		}
		if (gunm249.GetweaponState()) {
			for (int i = 0; i < 3; i++) {
				gunm249.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
				gunm249.bulletmove(Gunflip);
			}
		}
	};

	//将事件监听器与场景绑定
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);

	//宝箱拾取监听器
	GameSceneMountain scene;
	auto boxes = scene.getBoxes();
	int* boxes_type = scene.getBoxesType();
	int* boxes_positionx = scene.getBoxesPositionx();
	int* boxes_positiony = scene.getBoxesPositiony();
	auto mykeyListener = EventListenerKeyboard::create();
	mykeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		if (keycode == EventKeyboard::KeyCode::KEY_ENTER) {
			float gun_positionx = gunp92.spriteGun->getPosition().x;
			float gun_positiony= gunp92.spriteGun->getPosition().y;
			int i = 0;
			for (; i < 15; ++i) {
				if (fabs(gunp92.spriteGun->getPosition().x - boxes_positionx[i]) < 50 && fabs(gunp92.spriteGun->getPosition().y - boxes_positiony[i]) < 70) {
					if (boxes_type[i] == 1) {
						gunp92.SetWeaponState(false);
						gun98k.SetWeaponState(true);
						gunm249.SetWeaponState(false);
						bomb.SetWeaponState(false);
						gunp92.spriteGun->setVisible(false);
						gun98k.spriteGun->setVisible(true);
						gunm249.spriteGun->setVisible(false);
						bomb.sprite_bomb->setVisible(false);
					}
					else if (boxes_type[i] == 2) {
						gunp92.SetWeaponState(false);
						gun98k.SetWeaponState(false);
						gunm249.SetWeaponState(true);
						bomb.SetWeaponState(false);
						gunp92.spriteGun->setVisible(false);
						gun98k.spriteGun->setVisible(false);
						gunm249.spriteGun->setVisible(true);
						bomb.sprite_bomb->setVisible(false);
					}
					else if(boxes_type[i] == 3) {
						gunp92.SetWeaponState(false);
						gun98k.SetWeaponState(false);
						gunm249.SetWeaponState(false);
						bomb.SetWeaponState(true);
						gunp92.spriteGun->setVisible(false);
						gun98k.spriteGun->setVisible(false);
						gunm249.spriteGun->setVisible(false);
						bomb.sprite_bomb->setVisible(false);
					}
					boxes->removeAllChildren();
				}
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mykeyListener, this);
	return  true;
}



void GunLayer_robot::update(float delta)
{
	auto moveBy_left1 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right1 = MoveBy::create(0.7f, Vec2(5.f, 0));
	auto moveBy_left2 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right2 = MoveBy::create(0.7f, Vec2(5.f, 0));
	auto moveBy_left3 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right3 = MoveBy::create(0.7f, Vec2(5.f, 0));
	//auto moveBy_left4 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	//auto moveBy_right4 = MoveBy::create(0.7f, Vec2(5.f, 0));
	if (keyMap[EventKeyboard::KeyCode::KEY_LEFT_ARROW])
	{
		offset.x -= 5.f;
		//枪口方向翻转
		Gunflip = GunLeft;
		gunp92.spriteGun->setFlippedX(false);
		gunp92.spriteGun->runAction(moveBy_left1);
		gun98k.spriteGun->setFlippedX(false);
		gun98k.spriteGun->runAction(moveBy_left2);
		gunm249.spriteGun->setFlippedX(false);
		gunm249.spriteGun->runAction(moveBy_left3);
		bomb.sprite_bomb->setFlippedX(false);
		//bomb.sprite_bomb->runAction(moveBy_left4);
	}
	else if (keyMap[EventKeyboard::KeyCode::KEY_RIGHT_ARROW])
	{
		offset.x += 5.f;
		Gunflip = GunRight;
		gunp92.spriteGun->setFlippedX(true);
		gunp92.spriteGun->runAction(moveBy_right1);
		gun98k.spriteGun->setFlippedX(true);
		gun98k.spriteGun->runAction(moveBy_right2);
		gunm249.spriteGun->setFlippedX(true);
		gunm249.spriteGun->runAction(moveBy_right3);
		bomb.sprite_bomb->setFlippedX(true);
		//bomb.sprite_bomb->runAction(moveBy_right4);
	}
}

void GunLayer_robot::falling_judge()
{
	_land1->setPosition(Vec2(230, 350));
	_land2->setPosition(Vec2(970, 280));
	_land3->setPosition(Vec2(700, 170));
	_land4->setPosition(Vec2(1170, 500));
	_land5->setPosition(Vec2(750, 620));
	_land6->setPosition(Vec2(550, 450));

}


