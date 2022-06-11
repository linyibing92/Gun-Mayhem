#pragma once
#include"cocos2d.h"
USING_NS_CC;

class CharacterWmale :public Layer
{
public:
	CREATE_FUNC(CharacterWmale);
	virtual bool init();
	//新加机器人移动函数
	ActionInterval* wmalemove(EventKeyboard::KeyCode keycode);
	//机器人持续移动函数
	virtual void update(float delta);
	//判断机器人是否走出边界
	void falling_judge();

		//传递机器人坐标
	Vec2 getchacaterWmaleposition();
	PhysicsBody* body = PhysicsBody::createBox(Size(10.0f, 9.0f), PhysicsMaterial(50.0f, 0.0f, 0.0f));

private:
	Sprite* _land1 = Sprite::create("land3(2).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	Sprite* _land3 = Sprite::create("land3(1).png");
	Sprite* _land4 = Sprite::create("land3(2).png");
	Sprite* _land5 = Sprite::create("land3(1).png");
	Sprite* _land6 = Sprite::create("land3(1).png");
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//存放按键的状态是不是按压中
	Sprite* character_wmale = Sprite::create("character_wmale_idle.png");
	Vec2 offset = Vec2::ZERO;
	Vec2 wmale_position;
	ActionInterval* wmale_right;
	ActionInterval* wmale_left;
	Spawn* wmale_up;
	Spawn* wmale_down;
};