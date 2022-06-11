#pragma once
#include"GameScene.h"
#include"weapon.h"
#include "cocos2d.h"
#include "Character_wmale.h"
#include "bomb.h"
#include "audio/include/AudioEngine.h"
#define GunLeft 0
#define GunRight 1
#define gunp92_choice 2
#define gunm249_choice 3
#define gun98k_choice 4
USING_NS_CC;



class GunLayer_wmale;
class GunLayer_robot;



/* 创建枪类 */
class Gun :public weapon
{
public:
	Sprite* sprite_bullet = Sprite::create("bullet.png");/* 创建子弹精灵 */
	mutable int flip = GunLeft;/* 初始枪口方向为左 */
protected:
	Sprite* spriteGun;
};

/* 创建突击枪子类 */
class GunM249 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("M249.png");
	/* 移动子弹 */
	void bulletmove(int _flip) const;
	/* 攻击函数 */
	int attack(Vec2 characterposition);
	//设置攻击力
	int GetWeaponpower();
protected:

	int MyPower = 5;
};

/* 创建手枪子类 */
class GunP92 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("P92.png");
	/* 移动子弹 */
	void bulletmove(int _flip) const;
	/* 攻击函数 */
	int attack(Vec2 characterposition);
	//设置攻击力
	int GetWeaponpower();
protected:
	int MyPower = 5;
};

/* 创建狙击枪子类 */
class Gun98K : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("98K.png");
	/* 移动子弹 */
	void bulletmove(int _flip) const;
	/* 攻击函数 */
	int attack(Vec2 characterposition);
	//设置攻击力
	int GetWeaponpower();
protected:
	int MyPower = 10;
};



//创造放置枪的层——人物wmale
class GunLayer_wmale :public Layer
{
public:
	CREATE_FUNC(GunLayer_wmale);
	virtual bool init();
	//持续移动函数
	virtual void update(float delta);
	//判断是否走出边界
	void falling_judge();
	//调用攻击函数
	int bullet_attack();

	PhysicsBody* body_gun1 = PhysicsBody::createBox(Size(0.2f, 0.2f), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	PhysicsBody* body_gun2 = PhysicsBody::createBox(Size(0.2f, 0.2f), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	PhysicsBody* body_gun3 = PhysicsBody::createBox(Size(0.2f, 0.2f), PhysicsMaterial(50.0f, 0.0f, 0.0f));

	PhysicsBody* body_bullet1 = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));
	PhysicsBody* body_bullet2 = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));
	PhysicsBody* body_bullet3 = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));
	PhysicsBody* body_bomb = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));

private:
	Bomb bomb;
	Gun98K gun98k;
	GunP92 gunp92;
	GunM249 gunm249;
	Sprite* _land1 = Sprite::create("land3(2).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	Sprite* _land3 = Sprite::create("land3(1).png");
	Sprite* _land4 = Sprite::create("land3(2).png");
	Sprite* _land5 = Sprite::create("land3(1).png");
	Sprite* _land6 = Sprite::create("land3(1).png");
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//存放按键的状态是不是按压中
	Vec2 offset = Vec2::ZERO;
	Vec2 gun_position;
	int Gunflip = GunLeft;/* 设置枪口的方向 */
};

//创造放置枪的层——人物robot
class GunLayer_robot :public Layer
{
public:
	CREATE_FUNC(GunLayer_robot);
	virtual bool init();
	//持续移动函数
	virtual void update(float delta);
	//判断是否走出边界
	void falling_judge();
	//调用攻击函数
	int bullet_attack();

	//捡起武器
	PhysicsBody* body_gun1 = PhysicsBody::createBox(Size(0.2f, 0.2f), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	PhysicsBody* body_gun2 = PhysicsBody::createBox(Size(0.2f, 0.2f), PhysicsMaterial(50.0f, 0.0f, 0.0f));
	PhysicsBody* body_gun3 = PhysicsBody::createBox(Size(0.2f, 0.2f), PhysicsMaterial(50.0f, 0.0f, 0.0f));

	PhysicsBody* body_bullet1 = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));
	PhysicsBody* body_bullet2 = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));
	PhysicsBody* body_bullet3 = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));
	PhysicsBody* body_bomb = PhysicsBody::createBox(Size(1.0f, 1.0f), PhysicsMaterial(1.0f, 0.0f, 0.0f));

private:
	Bomb bomb;
	Gun98K gun98k;
	GunP92 gunp92;
	GunM249 gunm249;
	Sprite* _land1 = Sprite::create("land3(2).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	Sprite* _land3 = Sprite::create("land3(1).png");
	Sprite* _land4 = Sprite::create("land3(2).png");
	Sprite* _land5 = Sprite::create("land3(1).png");
	Sprite* _land6 = Sprite::create("land3(1).png");
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//存放按键的状态是不是按压中
	Vec2 offset = Vec2::ZERO;
	Vec2 gun_position;
	int Gunflip = GunLeft;/* 设置枪口的方向 */
};