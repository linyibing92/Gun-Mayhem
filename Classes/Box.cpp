#include "Box.h"

bool Box::init()
{
	if (!Layer::create())
		return false;
	 width1 = static_cast<int>(_land1->getContentSize().width);
	 width2 = static_cast<int>(_land2->getContentSize().width);
	 srand((unsigned)time(NULL));
	_type = rand() % 3 + 1;
	srand((unsigned)time(NULL));
	_position_x = rand() % ((1170+width2/2)-(230 - width2 / 2)+1)+ (230 - width2 / 2);
	return true;
}

Sprite* Box::drop()
{
	Action* drop;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (_position_x > (230 - width2 / 2) && _position_x < (550 - width1 / 2))
	     drop = MoveBy::create(1.f, Vec2(0, 350-visibleSize.height));
	else if(_position_x>(550-width1/2)&&_position_x<(750-width1/2))
	    drop = MoveBy::create(1.f, Vec2(0, 450 - visibleSize.height));
	else if (_position_x > (750 - width1 / 2) && _position_x < (750 +width1 / 2))
		drop = MoveBy::create(1.f, Vec2(0, 620 - visibleSize.height));
	else if(_position_x > (750 + width1 / 2) && _position_x < (1170 + width2 / 2))
	    drop = MoveBy::create(1.f, Vec2(0, 500 - visibleSize.height));
	if (_type == 1) {
		Sprite* juji = Sprite::create("juji.png");
		juji->setScale(0.43f);
		this->addChild(juji);
		juji->setPosition(static_cast<float>(_position_x), static_cast<float>(visibleSize.height));
		juji->runAction(drop);
		return juji;
	}
	else if (_type == 2) {
		Sprite* jiguan = Sprite::create("jiguan.png");
		jiguan->setScale(0.43f);
		this->addChild(jiguan);
		jiguan->setPosition(static_cast<float>(_position_x), static_cast<float>(visibleSize.height));
		jiguan->runAction(drop);
		return jiguan;
	}
	else {
		Sprite* bomb = Sprite::create("bomb.png");
		this->addChild(bomb);
		bomb->setPosition(static_cast<float>(_position_x), static_cast<float>(visibleSize.height));
		bomb->runAction(drop);
		return bomb;
	}



}
