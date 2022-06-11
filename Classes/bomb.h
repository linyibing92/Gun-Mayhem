#pragma once
#include <cocos2d.h>
#include "weapon.h"
#include "audio/include/AudioEngine.h"
USING_NS_CC;

class Bomb : public weapon
{
public:
	Sprite* sprite_bomb = Sprite::create("bomb.png");
	//炸弹运动轨迹
	void bomb_move(Vec2 characterposition,int _flip) const;
	//设置攻击力
	int GetWeaponpower()const;
protected:
	int MyPower = 20;
	
};