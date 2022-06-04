#pragma once
#include"weapon.h"
#include "cocos2d.h"
USING_NS_CC;
#define GunLeft 0
#define GunRight 1

/* 创建枪类 */
class Gun :public weapon
{
public:
	Sprite* sprite_bullet = Sprite::create("bullet.png");/* 创建子弹精灵 */
	mutable int flip = GunLeft;/* 初始枪口方向为左 */
	/* 攻击函数 */
	//int attack(Vec2 characterposition);
protected:
	Sprite* spriteGun;
};

/* 创建突击枪子类 */
class GunM249 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("M249.png");
	/* 移动子弹 */
	void bulletmove() const
	{
		auto moveTo = MoveBy::create(1, Point(240, 0));
		sprite_bullet->runAction(moveTo);
	}
};

/* 创建手枪子类 */
class GunP92 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("P92.png");
	/* 移动子弹 */
	void bulletmove() const
	{
		auto moveTo = MoveBy::create(1, Point(240, 0));
		sprite_bullet->runAction(moveTo);
	}
};

/* 创建狙击枪子类 */
class Gun98K : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("98K.png");
	/* 移动子弹 */
	void bulletmove() const
	{
		auto moveTo = MoveBy::create(1, Point(240, 0));
		sprite_bullet->runAction(moveTo);
	}
};


/* 创建了放置精灵的场景 */
class SpriteScene : public Scene
{
public:
	CREATE_FUNC(SpriteScene);

	virtual bool init();
};


