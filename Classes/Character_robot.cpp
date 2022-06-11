#include "Character_robot.h"

bool CharacterRobot::init()
{
	if (!Layer::create())
		return false;

	_land5->setPosition(Vec2(750, 620));

	this->scheduleUpdate();//回调更新函数
	//创建机器人角色
	character_robot->setScale(1.15f);
	this->addChild(character_robot, 7);

	//设置刚体形状、参数
	character_robot->setTag(1);
   character_robot->setPhysicsBody(body);


	//设置精灵起始位置在最高障碍偏左 
	robot_position = _land5->getPosition() + Vec2(0, _land5->getContentSize().height / 2) + Vec2(0, character_robot->getContentSize().height * 2);
	//隐藏精灵
	character_robot->setVisible(true);
	character_robot->setPosition(robot_position + offset);
	//实现通过键盘控制人物移动
	auto keyListener = EventListenerKeyboard::create();//创建一个事件监听器监听键盘事件(监视键位的按下和松开)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_UP_ARROW)
		{
			//机器人动画(向上\向下)——不区分长按短按
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_robot_Jump.plist", "character_robot_jump.png");
			auto cache_up = SpriteFrameCache::getInstance();
			Vector<SpriteFrame*> robotmove_images_up;
			robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_idle.png"));
			robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_jump.png"));
			robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_jump.png"));
			robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_idle.png"));
			robotmove_images_up.pushBack(cache_up->getSpriteFrameByName("character_robot_idle.png"));
			Animation* robotmove_up_animation = Animation::createWithSpriteFrames(robotmove_images_up, 0.5f / 5);
			FiniteTimeAction* robot_jump = JumpBy::create(0.5, Vec2(0, 0), 150, 1);
			robot_up = Spawn::create(robot_jump, Animate::create(robotmove_up_animation), nullptr);
			character_robot->runAction(robot_up);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
		{
			FiniteTimeAction* move_down = MoveBy::create(0.5f, Vec2(0, -40.f));
			offset.y -= 20.f;
			character_robot->runAction(move_down);
		}
	};
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return true;
}

ActionInterval* CharacterRobot::robotmove(EventKeyboard::KeyCode keycode)
{
	ActionInterval* robotmove_animation;
	if (keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		//机器人动画(向左)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_robot_walk1.plist", "character_robot_walk1.png");
		auto cache_left = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> robotmove_images_left;
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_idle.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk01.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk11.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk21.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk31.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk41.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk51.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk61.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_walk71.png"));
		robotmove_images_left.pushBack(cache_left->getSpriteFrameByName("character_robot_idle.png"));
		Animation* robotmove_left_animation = Animation::createWithSpriteFrames(robotmove_images_left, 0.7f / 10);
		ActionInterval* robotmove_left_animation1 = Animate::create(robotmove_left_animation);
		return robotmove_left_animation1;
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		//机器人动画(向右)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_robot_walk.plist", "character_robot_walk.png");
		auto cache_right = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> robotmove_images_right;
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_idle.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk0.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk1.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk2.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk3.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk4.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk5.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk6.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_walk7.png"));
		robotmove_images_right.pushBack(cache_right->getSpriteFrameByName("character_robot_idle.png"));
		Animation* robotmove_right_animation = Animation::createWithSpriteFrames(robotmove_images_right, 0.7f / 10);
		ActionInterval* robotmove_right_animation1 = Animate::create(robotmove_right_animation);
		return robotmove_right_animation1;
	}
	return robotmove_animation;
}

void CharacterRobot::update(float delta)
{
	auto moveBy_left = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right = MoveBy::create(0.7f, Vec2(5.f, 0));
	robot_left = Spawn::create(moveBy_left, robotmove(EventKeyboard::KeyCode::KEY_LEFT_ARROW), nullptr);
	robot_right = Spawn::create(moveBy_right, robotmove(EventKeyboard::KeyCode::KEY_RIGHT_ARROW), nullptr);
	if (keyMap[EventKeyboard::KeyCode::KEY_LEFT_ARROW])
	{
		offset.x -= 5.f;
		character_robot->runAction(robot_left);
	}
	else if (keyMap[EventKeyboard::KeyCode::KEY_RIGHT_ARROW])
	{
		offset.x += 5.f;
		character_robot->runAction(robot_right);
	}

}

void CharacterRobot::falling_judge()
{
	_land1->setPosition(Vec2(230, 350));
	_land2->setPosition(Vec2(970, 280));
	_land3->setPosition(Vec2(700, 170));
	_land4->setPosition(Vec2(1170, 500));
	_land5->setPosition(Vec2(750, 620));
	_land6->setPosition(Vec2(550, 450));
}

//Vec2 CharacterRobot::getchacaterRobotposition()
//{
//	Vec2 chacaterRobotposition = character_robot->getPosition();
//	return chacaterRobotposition;
//}