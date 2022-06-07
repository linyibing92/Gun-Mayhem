#include "Gun.h"
#include "weapon.h"

USING_NS_CC;

void GunM249::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveTo = MoveBy::create(1, Point(240, 0));

		auto bulletHide = Hide::create();//执行完动作后隐藏精灵
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveTo, bulletHide, NULL);
		//设置重复动作，完成机关枪的多次射击
		auto repeat = Repeat::create(seq, 3);
		sprite_bullet->runAction(repeat);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-240, 0));
		auto bulletHide = Hide::create();//执行完动作后隐藏精灵
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveToLeft, bulletHide, NULL);
		//设置重复动作，完成机关枪的多次射击
		auto repeat = Repeat::create(seq, 3);
		sprite_bullet->runAction(repeat);
	}
	
}

void GunP92::bulletmove(int _flip) const
{

	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveToRight = MoveBy::create(1, Point(200, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveToRight, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-200, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveToLeft, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
}
void Gun98K::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveToRight = MoveBy::create(0.5, Point(480, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveToRight, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(0.5, Point(-480, 0));
		auto bulletHide = Hide::create();
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveToLeft, bulletHide, NULL);
		sprite_bullet->runAction(seq);
	}
}

//攻击函数
int Gun::attack(Vec2 characterposition)
{
	int harm = 0 ;
	auto bulletposition = sprite_bullet->getPosition();
	if ((abs(bulletposition.x - characterposition.x) < 3))
	{
		harm = Gun::GetWeaponpower();
	}

	return harm;
}

