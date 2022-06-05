#pragma once
#include"weapon.h"
#include "cocos2d.h"
#define GunLeft 0
#define GunRight 1
USING_NS_CC;

/* ����ǹ�� */
class Gun :public weapon 
{
public:
	Sprite* sprite_bullet = Sprite::create("bullet.png");/* �����ӵ����� */
	mutable int flip = GunLeft;/* ��ʼǹ�ڷ���Ϊ�� */
	/* �������� */
	int attack(Vec2 characterposition);
protected:
	Sprite* spriteGun;
};

/* ����ͻ��ǹ���� */
class GunM249 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("M249.png");
	/* �ƶ��ӵ� */
	void bulletmove(int _flip) const;
	
protected:
	int Mypower = 5;
};

/* ������ǹ���� */
class GunP92 : public Gun
{
public:
	Sprite* spriteGun = Sprite::create("P92.png");
	/* �ƶ��ӵ� */
	void bulletmove(int _flip) const;
	
protected:
	int Mypower = 5;
};

/* �����ѻ�ǹ���� */
class Gun98K : public Gun
{
public:
	mutable Sprite* spriteGun = Sprite::create("98K.png");
	/* �ƶ��ӵ� */
	void bulletmove(int _flip) const;
protected:
	int Mypower = 10;
};



