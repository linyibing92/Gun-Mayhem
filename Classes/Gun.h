#pragma once
#include"weapon.h"
#include "cocos2d.h"
USING_NS_CC;
#define GunLeft 0
#define GunRight 1

/* ����ǹ�� */
class Gun :public weapon
{
public:
	Sprite* sprite_bullet = Sprite::create("bullet.png");/* �����ӵ����� */
	mutable int flip = GunLeft;/* ��ʼǹ�ڷ���Ϊ�� */
	/* �������� */
	//int attack(Vec2 characterposition);
protected:
	Sprite* spriteGun;
};

/* ����ͻ��ǹ���� */
class GunM249 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("M249.png");
	/* �ƶ��ӵ� */
	void bulletmove() const
	{
		auto moveTo = MoveBy::create(1, Point(240, 0));
		sprite_bullet->runAction(moveTo);
	}
};

/* ������ǹ���� */
class GunP92 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("P92.png");
	/* �ƶ��ӵ� */
	void bulletmove() const
	{
		auto moveTo = MoveBy::create(1, Point(240, 0));
		sprite_bullet->runAction(moveTo);
	}
};

/* �����ѻ�ǹ���� */
class Gun98K : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("98K.png");
	/* �ƶ��ӵ� */
	void bulletmove() const
	{
		auto moveTo = MoveBy::create(1, Point(240, 0));
		sprite_bullet->runAction(moveTo);
	}
};


/* �����˷��þ���ĳ��� */
class SpriteScene : public Scene
{
public:
	CREATE_FUNC(SpriteScene);

	virtual bool init();
};


