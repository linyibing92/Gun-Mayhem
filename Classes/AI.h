#pragma once
#include"cocos2d.h"
USING_NS_CC;

class CharacterAI :public Layer
{
public:
	CREATE_FUNC(CharacterAI);
	virtual bool init();
	//判断机器人是否走出边界
	void falling_judge();
	PhysicsBody* body = PhysicsBody::createBox(Size(10.0f, 9.0f), PhysicsMaterial(50.0f, 0.0f, 0.0f));

private:
	Sprite* _land1 = Sprite::create("land3(2).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	Sprite* _land3 = Sprite::create("land3(1).png");
	Sprite* _land4 = Sprite::create("land3(2).png");
	Sprite* _land5 = Sprite::create("land3(1).png");
	Sprite* _land6 = Sprite::create("land3(1).png");
	Sprite* character_AI = Sprite::create("character_robot_idle.png");
	Vec2 offset = Vec2::ZERO;
	Vec2 AI_position;
	ActionInterval* wmale_right;
	ActionInterval* wmale_left;
	Spawn* wmale_up;
	Spawn* wmale_down;
};
