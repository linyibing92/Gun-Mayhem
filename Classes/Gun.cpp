#include "Gun.h"
USING_NS_CC;

//�ӵ��ƶ�����
void GunM249::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveTo = MoveBy::create(0.5, Point(240, 0));

		auto bulletHide = Hide::create();//ִ���궯�������ؾ���
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveTo, bulletHide, NULL);
		//�����ظ���������ɻ���ǹ�Ķ�����
		sprite_bullet->runAction(seq);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(0.5, Point(-240, 0));
		auto bulletHide = Hide::create();//ִ���궯�������ؾ���
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow, moveToLeft, bulletHide, NULL);
		//�����ظ���������ɻ���ǹ�Ķ�����
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

//��ȡ����������������
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



//��������
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




//��������wmale��ǹ֧ͼ��
bool GunLayer_wmale::init()
{
	if (!Scene::create())
		return false;

	_land5->setPosition(Vec2(750, 620));
	this->scheduleUpdate();

	//����ǹ�Ľ�ɫ
	gunp92.spriteGun->setScale(0.25f);
	gun98k.spriteGun->setScale(0.25f);
	gunm249.spriteGun->setScale(0.25f);
	this->addChild(gunp92.spriteGun); 
	this->addChild(gun98k.spriteGun);
	this->addChild(gunm249.spriteGun);

	gunp92.spriteGun->setPhysicsBody(body_gun1);
	gun98k.spriteGun->setPhysicsBody(body_gun2);
	gunm249.spriteGun->setPhysicsBody(body_gun3);

	//�ӵ�
	this->addChild(gunp92.sprite_bullet);
	this->addChild(gun98k.sprite_bullet);
	this->addChild(gunm249.sprite_bullet);
	//��������
	gunp92.sprite_bullet->setTag(1);
	body_bullet1->setGravityEnable(false);
	gunp92.sprite_bullet->setPhysicsBody(body_bullet1);

	gun98k.sprite_bullet->setTag(1);
	body_bullet2->setGravityEnable(false);
	gun98k.sprite_bullet->setPhysicsBody(body_bullet2);

	gunm249.sprite_bullet->setTag(1);
	body_bullet3->setGravityEnable(false);
	gunm249.sprite_bullet->setPhysicsBody(body_bullet3);

	//����ǹ֧״̬Ϊpicked
	gunp92.SetWeaponState(true);
	gun98k.SetWeaponState(false);
	gunm249.SetWeaponState(false);
	bomb.SetWeaponState(false);

	//����ը���Ľ�ɫ
	this->addChild(bomb.sprite_bomb);
	//��������
	bomb.sprite_bomb->setTag(1);
	body_bomb->setGravityEnable(false);
	bomb.sprite_bomb->setPhysicsBody(body_bomb);

	//���þ�����ʼλ��������ϰ����м� 
	gun_position = _land5->getPosition() + Vec2(_land5->getContentSize().width / 5, _land5->getContentSize().height / 2);


	//���ؾ���
	gunp92.spriteGun->setVisible(true);
	gunp92.spriteGun->setPosition(gun_position + offset);
	gun98k.spriteGun->setVisible(false);
	gun98k.spriteGun->setPosition(gun_position + offset);
	gunm249.spriteGun->setVisible(false);
	gunm249.spriteGun->setPosition(gun_position + offset);
	bomb.sprite_bomb->setVisible(false);
	bomb.sprite_bomb->setPosition(0, 0);

	//ʵ��ͨ�����̿��������ƶ�
	auto keyListener = EventListenerKeyboard::create();//����һ���¼����������������¼�(���Ӽ�λ�İ��º��ɿ�)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_W||keycode == EventKeyboard::KeyCode::KEY_CAPITAL_W)
		{
			//ǹе��������
			FiniteTimeAction* gun_jump1 = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			FiniteTimeAction* gun_jump2 = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			FiniteTimeAction* gun_jump3 = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			FiniteTimeAction* gun_jump4 = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			gunp92.spriteGun->runAction(gun_jump1);
			gun98k.spriteGun->runAction(gun_jump2);
			gunm249.spriteGun->runAction(gun_jump3);
			
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_S|| keycode == EventKeyboard::KeyCode::KEY_CAPITAL_S)
		{
			FiniteTimeAction* gun_down1 = MoveBy::create(0.5f, Vec2(0, -20.f));
			FiniteTimeAction* gun_down2 = MoveBy::create(0.5f, Vec2(0, -20.f));
			FiniteTimeAction* gun_down3 = MoveBy::create(0.5f, Vec2(0, -20.f));
			FiniteTimeAction* gun_down4 = MoveBy::create(0.5f, Vec2(0, -20.f));
			offset.y -= 20.f;
			gunp92.spriteGun->runAction(gun_down1);
			gun98k.spriteGun->runAction(gun_down2);
			gunm249.spriteGun->runAction(gun_down3);
			
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_J || keycode == EventKeyboard::KeyCode::KEY_CAPITAL_J) //������J��Ϊ����wmale���ӵ������ʽ
		{
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
					auto place = Place::create(gunp92.spriteGun->getPosition());
					gunm249.sprite_bullet->runAction(place);
					gunm249.bulletmove(Gunflip);
				}
			}
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_K||keycode == EventKeyboard::KeyCode::KEY_CAPITAL_K) //����K��Ϊ����wmaleը����Ͷ��
		{
			//����ը��״̬ 
			if (bomb.GetweaponState() == true) {
				bomb.sprite_bomb->setPosition(gunp92.spriteGun->getPosition());
				bomb.bomb_move(gunp92.spriteGun->getPosition());
			};
		}
	};
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	//����ʰȡ������
	GameSceneMountain scene;
	auto boxes = scene.getBoxes();
	int* boxes_type = scene.getBoxesType();
	int* boxes_positionx = scene.getBoxesPositionx();
	auto mykeyListener = EventListenerKeyboard::create();
	mykeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		if (keycode == EventKeyboard::KeyCode::KEY_L || keycode == EventKeyboard::KeyCode::KEY_CAPITAL_L) {
			float gun_positionx = gunp92.spriteGun->getPosition().x;
			int i = 0;
			for (; i < 15; ++i) {
				if (fabs(gun_positionx - boxes_positionx[i]) < 40) {
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
						bomb.sprite_bomb->setVisible(true);
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
	auto moveBy_left4 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right4 = MoveBy::create(0.7f, Vec2(5.f, 0));
	if (keyMap[EventKeyboard::KeyCode::KEY_A])
	{
		offset.x -= 5.f;
		//ǹ�ڷ���ת
		Gunflip = GunLeft;
		gunp92.spriteGun->setFlippedX(false);
		gunp92.spriteGun->runAction(moveBy_left1);
		gun98k.spriteGun->setFlippedX(false);
		gun98k.spriteGun->runAction(moveBy_left2);
		gunm249.spriteGun->setFlippedX(false);
		gunm249.spriteGun->runAction(moveBy_left3);
		
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



//��������robot��ǹ֧ͼ��
bool GunLayer_robot::init()
{
	if (!Scene::create())
		return false;

	_land5->setPosition(Vec2(750, 620));
	this->scheduleUpdate();

	//����ǹ�Ľ�ɫ
	gunp92.spriteGun->setScale(0.25f);
	this->addChild(gunp92.spriteGun);
	gunp92.spriteGun->setPhysicsBody(body_gun1);

	gun98k.spriteGun->setScale(0.25f);
	this->addChild(gun98k.spriteGun);
	gun98k.spriteGun->setPhysicsBody(body_gun2);

	gunm249.spriteGun->setScale(0.25f);
	this->addChild(gunm249.spriteGun);
	gunm249.spriteGun->setPhysicsBody(body_gun3);


	//�ӵ�
	this->addChild(gunp92.sprite_bullet);
	this->addChild(gunm249.sprite_bullet);
	this->addChild(gun98k.sprite_bullet);
	//��������
	gunp92.sprite_bullet->setTag(2);
	body_bullet1->setGravityEnable(false);
	gunp92.sprite_bullet->setPhysicsBody(body_bullet1);

	gun98k.sprite_bullet->setTag(2);
	body_bullet2->setGravityEnable(false);
	gun98k.sprite_bullet->setPhysicsBody(body_bullet2);

	gunm249.sprite_bullet->setTag(2);
	body_bullet3->setGravityEnable(false);
	gunm249.sprite_bullet->setPhysicsBody(body_bullet3);

	//����ǹ֧״̬Ϊpicked
	gunp92.SetWeaponState(true);
	gun98k.SetWeaponState(false);
	gunm249.SetWeaponState(false);
	bomb.SetWeaponState(false);

	//����ը���Ľ�ɫ
	this->addChild(bomb.sprite_bomb);
	//��������
	bomb.sprite_bomb->setTag(2);
	body_bomb->setGravityEnable(false);
	bomb.sprite_bomb->setPhysicsBody(body_bomb);

	//���þ�����ʼλ��������ϰ����м� 
	gun_position = _land5->getPosition() + Vec2(0, _land5->getContentSize().height / 2);


	//���ؾ���
	gunp92.spriteGun->setVisible(true);
	gunp92.spriteGun->setPosition(gun_position + offset);
	gun98k.spriteGun->setVisible(false);
	gun98k.spriteGun->setPosition(gun_position + offset);
	gunm249.spriteGun->setVisible(false);
	gunm249.spriteGun->setPosition(gun_position + offset);
	bomb.sprite_bomb->setVisible(false);
	bomb.sprite_bomb->setPosition(0,0);

	//ʵ��ͨ�����̿��������ƶ�
	auto keyListener = EventListenerKeyboard::create();//����һ���¼����������������¼�(���Ӽ�λ�İ��º��ɿ�)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			//ǹе��������
			FiniteTimeAction* gun_jump1 = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			FiniteTimeAction* gun_jump2 = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			FiniteTimeAction* gun_jump3 = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
		
			gunp92.spriteGun->runAction(gun_jump1);
			gun98k.spriteGun->runAction(gun_jump2);
			gunm249.spriteGun->runAction(gun_jump3);
			
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			FiniteTimeAction* gun_down1 = MoveBy::create(0.5f, Vec2(0, -20.f));
			FiniteTimeAction* gun_down2 = MoveBy::create(0.5f, Vec2(0, -20.f));
			FiniteTimeAction* gun_down3 = MoveBy::create(0.5f, Vec2(0, -20.f));
			
			offset.y -= 20.f;
			gunp92.spriteGun->runAction(gun_down1);
			gunm249.spriteGun->runAction(gun_down2);
			gun98k.spriteGun->runAction(gun_down3);
			
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_SPACE) 
		{
			//����ը��״̬ 
			if (bomb.GetweaponState() == true) {
                bomb.sprite_bomb->setPosition(gunp92.spriteGun->getPosition());
			    bomb.bomb_move(gunp92.spriteGun->getPosition());
			};
			
		}
	};
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);


	//�����¼�����������¼����������ӵ����
	auto myMouseListener = EventListenerMouse::create();
	//����������
	myMouseListener->onMouseDown = [=](Event* event)
	{
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
				auto place = Place::create(gunp92.spriteGun->getPosition());
				gunm249.sprite_bullet->runAction(place);
				gunm249.bulletmove(Gunflip);
			}
		}
	};

	//���¼��������볡����
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);

	//����ʰȡ������
	GameSceneMountain scene;
	auto boxes = scene.getBoxes();
	int* boxes_type = scene.getBoxesType();
	int* boxes_positionx = scene.getBoxesPositionx();
	auto mykeyListener = EventListenerKeyboard::create();
	mykeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		if (keycode == EventKeyboard::KeyCode::KEY_ENTER) {
			float gun_positionx = gunp92.spriteGun->getPosition().x;
			int i = 0;
			for (; i < 15; ++i) {
				if (fabs(gun_positionx - boxes_positionx[i]) < 40) {
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
						bomb.sprite_bomb->setVisible(true);
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
	auto moveBy_left4 = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right4 = MoveBy::create(0.7f, Vec2(5.f, 0));
	if (keyMap[EventKeyboard::KeyCode::KEY_LEFT_ARROW])
	{
		offset.x -= 5.f;
		//ǹ�ڷ���ת
		Gunflip = GunLeft;
		gunp92.spriteGun->setFlippedX(false);
		gunp92.spriteGun->runAction(moveBy_left1);
		gun98k.spriteGun->setFlippedX(false);
		gun98k.spriteGun->runAction(moveBy_left2);
		gunm249.spriteGun->setFlippedX(false);
		gunm249.spriteGun->runAction(moveBy_left3);
		
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




