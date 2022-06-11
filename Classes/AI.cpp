#include "AI.h"

bool CharacterAI::init()
{
	if (!Layer::create())
		return false;

	_land5->setPosition(Vec2(750, 620));

	//创建机器人角色
	character_AI->setScale(1.15f);
	this->addChild(character_AI, 7);


	//设置精灵起始位置在最高障碍偏左 
	AI_position = _land5->getPosition() + Vec2(-_land5->getContentSize().width / 2, _land5->getContentSize().height / 2) + Vec2(0, character_AI->getContentSize().height / 2);

	//隐藏精灵
	character_AI->setVisible(true);
	character_AI->setPosition(AI_position + offset);

	//设置刚体形状、参数
	character_AI->setTag(1);
	character_AI->setPhysicsBody(body);

	auto moveBy_left = MoveBy::create(5.0f, Vec2(_land5->getContentSize().width, _land5->getContentSize().height / 2));
	auto moveBy_right = MoveBy::create(5.0f, Vec2(-_land5->getContentSize().width, _land5->getContentSize().height / 2));
	auto swq = Sequence::create(moveBy_left, moveBy_right, NULL);
	auto repeat = RepeatForever::create(swq);
	character_AI->runAction(repeat);

	return true;
}

void CharacterAI::falling_judge()
{
	_land1->setPosition(Vec2(230, 350));
	_land2->setPosition(Vec2(970, 280));
	_land3->setPosition(Vec2(700, 170));
	_land4->setPosition(Vec2(1170, 500));
	_land5->setPosition(Vec2(750, 620));
	_land6->setPosition(Vec2(550, 450));

}