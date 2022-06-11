#pragma once
#include"cocos2d.h"
USING_NS_CC;

class CharacterRobot :public Layer
{
public:
	CREATE_FUNC(CharacterRobot);
	virtual bool init();
	//�¼ӻ������ƶ�����
	ActionInterval* robotmove(EventKeyboard::KeyCode keycode);
	//�����˳����ƶ�����
	virtual void update(float delta);
	//�жϻ������Ƿ��߳��߽�
	void falling_judge();
	PhysicsBody* body = PhysicsBody::createBox(Size(10.0f, 9.0f), PhysicsMaterial(50.0f, 0.0f, 0.0f));
private:
	Sprite* _land1 = Sprite::create("land3(2).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	Sprite* _land3 = Sprite::create("land3(1).png");
	Sprite* _land4 = Sprite::create("land3(2).png");
	Sprite* _land5 = Sprite::create("land3(1).png");
	Sprite* _land6 = Sprite::create("land3(1).png");
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;//��Ű�����״̬�ǲ��ǰ�ѹ��
	Sprite* character_robot = Sprite::create("character_robot_idle.png");
	Vec2 offset = Vec2::ZERO;
	Vec2 robot_position;
	ActionInterval* robot_right;
	ActionInterval* robot_left;
	Spawn* robot_up;
	Spawn* robot_down;
};
