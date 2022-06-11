#pragma once
#include <cocos2d.h>
#include "weapon.h"
#include "audio/include/AudioEngine.h"
USING_NS_CC;

class Bomb : public weapon
{
public:
	Sprite* sprite_bomb = Sprite::create("bomb.png");
	//ը���˶��켣
	void bomb_move(Vec2 characterposition,int _flip) const;
	//���ù�����
	int GetWeaponpower()const;
protected:
	int MyPower = 20;
	
};