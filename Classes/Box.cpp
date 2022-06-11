#include "Box.h"

bool Box::init()
{
	if (!Layer::create())
		return false;
	return true;
}

void Box::drop(int* boxes_type,int*boxes_positionx,int* boxes_positiony,int times)
{
		//获取图片的大小
	Sprite* _land1 = Sprite::create("land3(1).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
	int width1 = static_cast<int>(_land1->getContentSize().width);
	int width2 = static_cast<int>(_land2->getContentSize().width);
	int _type =produceType();////两种枪加炸弹随机生成
	int _position_x = producePositionx(width2);////降落位置随机生成
	auto visibleSize = Director::getInstance()->getVisibleSize();
// 横坐标的不同位置决定竖直方向降落多少
	Action* drop= MoveBy::create(1.f, Vec2(0, 370 - visibleSize.height));
	if (_position_x > (230 - width2 / 2) && _position_x < (550 - width1 / 2)) {
		drop = MoveBy::create(1.f, Vec2(0, 370 - visibleSize.height));
		boxes_positiony[times] = visibleSize.height - 370;
	}
	else if (_position_x > (550 - width1 / 2) && _position_x < (750 - width1 / 2)) {
		drop = MoveBy::create(1.f, Vec2(0, 470 - visibleSize.height));
		boxes_positiony[times] = visibleSize.height - 470;
	}
	else if (_position_x > (750 - width1 / 2) && _position_x < (750 + width1 / 2)) {
        drop = MoveBy::create(1.f, Vec2(0, 640 - visibleSize.height));
		boxes_positiony[times] = visibleSize.height - 640;
	}
		
	else if (_position_x > (750 + width1 / 2) && _position_x < (1170 + width2 / 2)) {
		drop = MoveBy::create(1.f, Vec2(0, 520 - visibleSize.height));
		boxes_positiony[times] = visibleSize.height - 520;
	}
//不同种类宝箱用不同的精灵
	if (_type == 1) {
		Sprite* juji = Sprite::create("juji.png");
		juji->setScale(0.43f);
		this->addChild(juji);
		juji->setPosition(static_cast<float>(_position_x), static_cast<float>(visibleSize.height));
		juji->runAction(drop);
	}
	else if (_type == 2) {
		Sprite* jiguan = Sprite::create("jiguan.png");
		jiguan->setScale(0.43f);
		this->addChild(jiguan);
		jiguan->setPosition(static_cast<float>(_position_x), static_cast<float>(visibleSize.height));

		jiguan->runAction(drop);

	}
	else {
		Sprite* bomb = Sprite::create("bomb.png");
		this->addChild(bomb);
		bomb->setPosition(static_cast<float>(_position_x), static_cast<float>(visibleSize.height));
		bomb->runAction(drop);
	}
	//记录宝箱类型和位置
	boxes_type[times] = _type;
	boxes_positionx[times] = _position_x;
}

int Box::producePositionx(int width2)const//降落位置随机生成
{
	int _position_x = rand() % ((1170 + width2 / 2) - (230 - width2 / 2) + 1) + (230 - width2 / 2);
	return _position_x;
}

int Box::produceType()const//两种枪加炸弹随机生成
{
	srand((unsigned)time(NULL));
	int type = rand() % 3 + 1;
	return type;
}






