#pragma once
#include <cocos2d.h>
#include <weapon.h>
USING_NS_CC;

class Bomb : public weapon
{
public:
	Sprite* sprite_bomb = Sprite::create("bomb.png");
	void bomb_move(Vec2 characterposition) const;
};