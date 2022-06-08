#pragma once
#include"cocos2d.h"
USING_NS_CC;

class CharacterRobot :public Layer
{
public:
	CREATE_FUNC(CharacterRobot);
	virtual bool init();
	//新加机器人移动函数
	ActionInterval* robotmove(EventKeyboard::KeyCode keycode);
	//机器人持续移动函数
	virtual void update(float delta);
	//判断机器人是否走出边界
	void falling_judge();
	//传递机器人坐标
	Vec2 getchacaterRobotposition();
	PhysicsBody* body = PhysicsBody::createBox(Size(1.10f, 0.7f), PhysicsMaterial(50.0f, 0.0f, 0.0f));
private:
	Sprite* _land1 = Sprite::create("land3(2).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	Sprite* _land3 = Sprite::create("land3(1).png");
	Sprite* _land4 = Sprite::create("land3(2).png");
	Sprite* _land5 = Sprite::create("land3(1).png");
	Sprite* _land6 = Sprite::create("land3(1).png");
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//存放按键的状态是不是按压中
	Sprite* character_robot = Sprite::create("character_robot_idle.png");
	Vec2 offset = Vec2::ZERO;
	Vec2 robot_position;
	ActionInterval* robot_right;
	ActionInterval* robot_left;
	Spawn* robot_up;
	Spawn* robot_down;
};
