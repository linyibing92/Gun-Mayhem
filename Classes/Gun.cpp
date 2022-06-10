#include "Gun.h"
#include "weapon.h"

#include "Character_wmale.h"
#include "bomb.h"



USING_NS_CC;

//�ӵ��ƶ�����
void GunM249::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveTo = MoveBy::create(1, Point(240, 0));

		auto bulletHide = Hide::create();//执行完动作后隐藏精灵
		auto bulletShow = Show::create();

		auto seq = Sequence::create(bulletShow, moveTo, bulletHide, NULL);


		//设置重复动作，完成机关枪的多次射击
		auto repeat = Repeat::create(seq, 3);
		sprite_bullet->runAction(repeat);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-240, 0));
		auto bulletHide = Hide::create();//执行完动作后隐藏精灵
		auto bulletShow = Show::create();

		auto seq = Sequence::create(bulletShow, moveToLeft, bulletHide, NULL);

		//设置重复动作，完成机关枪的多次射击
		auto repeat = Repeat::create(seq, 3);
		sprite_bullet->runAction(repeat);
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


		auto seq = Sequence::create(bulletShow,moveToRight, bulletHide, NULL);

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


//��ȡ����״̬����
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




//������
int GunLayer_robot::bullet_attack()
{
	int harm = 0;
	if (gunp92.GetweaponState())
		harm = gunp92.GetWeaponpower();
	else if (gunm249.GetweaponState())
		harm = gunm249.GetWeaponpower();
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
	gunp92.spriteGun->setScale(0.2f);
	this->addChild(gunp92.spriteGun);

	gunp92.spriteGun->setPhysicsBody(body_gun);


	//子弹
	this->addChild(gunp92.sprite_bullet);
	//��������
	gunp92.sprite_bullet->setTag(1);
	body_bullet->setGravityEnable(false);
	gunp92.sprite_bullet->setPhysicsBody(body_bullet);


	//设置枪支状态为picked
	gunp92.SetWeaponState(true);

	//创建炸弹的角色
	this->addChild(bomb.sprite_bomb);
	//��������
	bomb.sprite_bomb->setTag(1);
	body_bomb->setGravityEnable(false);
	bomb.sprite_bomb->setPhysicsBody(body_bomb);

	//设置精灵起始位置在最高障碍正中间 
	gun_position = _land5->getPosition() + Vec2(0, _land5->getContentSize().height / 2);


	//隐藏精灵
	gunp92.spriteGun->setVisible(true);
	gunp92.spriteGun->setPosition(gun_position + offset);

	//实现通过键盘控制人物移动
	auto keyListener = EventListenerKeyboard::create();//创建一个事件监听器监听键盘事件(监视键位的按下和松开)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_W)
		{
			//枪械向上向下
			FiniteTimeAction* gun_jump = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			gunp92.spriteGun->runAction(gun_jump);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_S)
		{
			FiniteTimeAction* gun_down = MoveBy::create(0.5f, Vec2(0, -20.f));
			offset.y -= 20.f;
			gunp92.spriteGun->runAction(gun_down);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_J) //将按键J作为人物wmale的子弹射击方式
		{
			gunp92.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
			gunp92.bulletmove(Gunflip);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_K) //按键K作为人物wmale炸弹的投放
		{
			//����ը��״̬ 
			bomb.SetWeaponState(true);
			bomb.sprite_bomb->setPosition(gunp92.spriteGun->getPosition());
			bomb.bomb_move(gunp92.spriteGun->getPosition());
		}
	};
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return  true;
}



void GunLayer_wmale::update(float delta)
{
	auto moveBy_left = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right = MoveBy::create(0.7f, Vec2(5.f, 0));
	if (keyMap[EventKeyboard::KeyCode::KEY_A])
	{
		offset.x -= 5.f;
		//枪口方向翻转
		Gunflip = GunLeft;
		gunp92.spriteGun->setFlippedX(false);
		gunp92.spriteGun->runAction(moveBy_left);
	}
	else if (keyMap[EventKeyboard::KeyCode::KEY_D])
	{
		offset.x += 5.f;
		Gunflip = GunRight;
		gunp92.spriteGun->setFlippedX(true);
		gunp92.spriteGun->runAction(moveBy_right);
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
	gunp92.spriteGun->setScale(0.2f);
	this->addChild(gunp92.spriteGun);
	gunp92.spriteGun->setPhysicsBody(body_gun);


	//子弹
	this->addChild(gunp92.sprite_bullet);
	//��������
	gunp92.sprite_bullet->setTag(2);
	body_bullet->setGravityEnable(false);
	gunp92.sprite_bullet->setPhysicsBody(body_bullet);

	//设置枪支状态为picked
	gunp92.SetWeaponState(true);

	//创建炸弹的角色
	this->addChild(bomb.sprite_bomb);
	bomb.sprite_bomb->setTag(2);
	body_bomb->setGravityEnable(false);
	bomb.sprite_bomb->setPhysicsBody(body_bomb);

	//设置精灵起始位置在最高障碍正中间 
	gun_position = _land5->getPosition() + Vec2(_land5->getContentSize().width / 5, _land5->getContentSize().height / 2 );


	//隐藏精灵
	gunp92.spriteGun->setVisible(true);
	gunp92.spriteGun->setPosition(gun_position + offset);

	//实现通过键盘控制人物移动
	auto keyListener = EventListenerKeyboard::create();//创建一个事件监听器监听键盘事件(监视键位的按下和松开)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			//枪械向上向下
			FiniteTimeAction* gun_jump = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			gunp92.spriteGun->runAction(gun_jump);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			FiniteTimeAction* gun_down = MoveBy::create(0.5f, Vec2(0, -20.f));
			offset.y -= 20.f;
			gunp92.spriteGun->runAction(gun_down);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_SPACE) 
		{
			//����ը��״̬ 
			bomb.SetWeaponState(true);
			bomb.sprite_bomb->setPosition(gunp92.spriteGun->getPosition());
			bomb.bomb_move(gunp92.spriteGun->getPosition());
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
		gunp92.sprite_bullet->setPosition(gunp92.spriteGun->getPosition());
		gunp92.bulletmove(Gunflip);
	};

	//将事件监听器与场景绑定
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
	return  true;
}



void GunLayer_robot::update(float delta)
{
	auto moveBy_left = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right = MoveBy::create(0.7f, Vec2(5.f, 0));
	if (keyMap[EventKeyboard::KeyCode::KEY_LEFT_ARROW])
	{
		offset.x -= 5.f;
		//枪口方向翻转
		Gunflip = GunLeft;
		gunp92.spriteGun->setFlippedX(false);
		gunp92.spriteGun->runAction(moveBy_left);
	}
	else if (keyMap[EventKeyboard::KeyCode::KEY_RIGHT_ARROW])
	{
		offset.x += 5.f;
		Gunflip = GunRight;
		gunp92.spriteGun->setFlippedX(true);
		gunp92.spriteGun->runAction(moveBy_right);
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



