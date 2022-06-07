#include "Character_wmale.h"

bool CharacterWmale::init()
{
	if (!Layer::create())
		return false;
	_land5->setPosition(Vec2(750, 620));
	this->scheduleUpdate();
	//���������˽�ɫ
	character_wmale->setScale(1.15f);
	this->addChild(character_wmale, 7);
	//���þ�����ʼλ��������ϰ����м� 
	wmale_position = _land5->getPosition() + Vec2(0, _land5->getContentSize().height / 2) + Vec2(0, character_wmale->getContentSize().height / 2);
	//���ؾ���
	character_wmale->setVisible(true);
	character_wmale->setPosition(wmale_position + offset);
	//ʵ��ͨ�����̿��������ƶ�
	auto keyListener = EventListenerKeyboard::create();//����һ���¼����������������¼�(���Ӽ�λ�İ��º��ɿ�)
	keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = true;
		if (keycode == EventKeyboard::KeyCode::KEY_W)
		{
			//�����˶���(����\����)���������ֳ����̰�
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_wmale_Jump.plist", "character_wmale_jump.png");
			auto cache_up = SpriteFrameCache::getInstance();
			Vector<SpriteFrame*> wmalemove_images_up;
			wmalemove_images_up.pushBack(cache_up->getSpriteFrameByName("character_wmale_idle.png"));
			wmalemove_images_up.pushBack(cache_up->getSpriteFrameByName("character_wmale_jump.png"));
			wmalemove_images_up.pushBack(cache_up->getSpriteFrameByName("character_wmale_jump.png"));
			wmalemove_images_up.pushBack(cache_up->getSpriteFrameByName("character_wmale_idle.png"));
			wmalemove_images_up.pushBack(cache_up->getSpriteFrameByName("character_wmale_idle.png"));
			Animation* wmalemove_up_animation = Animation::createWithSpriteFrames(wmalemove_images_up, 0.5f / 5);
			FiniteTimeAction* wmale_jump = JumpBy::create(0.5, Vec2(0, 0), 70, 1);
			wmale_up = Spawn::create(wmale_jump, Animate::create(wmalemove_up_animation), nullptr);
			character_wmale->runAction(wmale_up);
		}
		else if (keycode == EventKeyboard::KeyCode::KEY_S)
		{
			FiniteTimeAction* move_down = MoveBy::create(0.5f, Vec2(0, -20.f));
			offset.y -= 20.f;
			character_wmale->runAction(move_down);
		}
	};
	keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event* event)
	{
		keyMap[keycode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return  true;
}

ActionInterval* CharacterWmale::wmalemove(EventKeyboard::KeyCode keycode)
{
	if (keycode == EventKeyboard::KeyCode::KEY_A)
	{
		//�˶���(����)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_wmale_walk1.plist", "character_wmale_walk1.png");
		auto cache_left = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> wmalemove_images_left;
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_idle.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk01.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk11.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk21.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk31.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk41.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk51.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk61.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_walk71.png"));
		wmalemove_images_left.pushBack(cache_left->getSpriteFrameByName("character_wmale_idle.png"));
		Animation* wmalemove_left_animation = Animation::createWithSpriteFrames(wmalemove_images_left, 0.7f / 10);
		ActionInterval* wmalemove_left_animation1 = Animate::create(wmalemove_left_animation);
		return wmalemove_left_animation1;
	}
	else if (keycode == EventKeyboard::KeyCode::KEY_D)
	{
		//�˶���(����)
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("character_wmale_walk.plist", "character_wmale_walk.png");
		auto cache_right = SpriteFrameCache::getInstance();
		Vector<SpriteFrame*> wmalemove_images_right;
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_idle.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk0.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk1(5).png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk2.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk3.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk4.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk5.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk6.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_walk7.png"));
		wmalemove_images_right.pushBack(cache_right->getSpriteFrameByName("character_wmale_idle.png"));
		Animation* wmalemove_right_animation = Animation::createWithSpriteFrames(wmalemove_images_right, 0.7f / 10);
		ActionInterval* wmalemove_right_animation1 = Animate::create(wmalemove_right_animation);
		return wmalemove_right_animation1;
	}
}

void CharacterWmale::update(float delta)
{
	auto moveBy_left = MoveBy::create(0.7f, Vec2(-5.f, 0));
	auto moveBy_right = MoveBy::create(0.7f, Vec2(5.f, 0));
	wmale_left = Spawn::create(moveBy_left, wmalemove(EventKeyboard::KeyCode::KEY_A), nullptr);
	wmale_right = Spawn::create(moveBy_right, wmalemove(EventKeyboard::KeyCode::KEY_D), nullptr);
	if (keyMap[EventKeyboard::KeyCode::KEY_A])
	{
		offset.x -= 5.f;
		character_wmale->runAction(wmale_left);
	}
	else if (keyMap[EventKeyboard::KeyCode::KEY_D])
	{
		offset.x += 5.f;
		character_wmale->runAction(wmale_right);
	}
}

void CharacterWmale::falling_judge()
{
	_land1->setPosition(Vec2(230, 350));
	_land2->setPosition(Vec2(970, 280));
	_land3->setPosition(Vec2(700, 170));
	_land4->setPosition(Vec2(1170, 500));
	_land5->setPosition(Vec2(750, 620));
	_land6->setPosition(Vec2(550, 450));

}
