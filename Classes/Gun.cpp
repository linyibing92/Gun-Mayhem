#include "Gun.h"
#include "weapon.h"

USING_NS_CC;

void GunM249::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveTo = MoveBy::create(1, Point(240, 0));

		auto bulletHide = Hide::create();//ִ���궯�������ؾ���
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveTo, bulletHide, NULL);
		//�����ظ���������ɻ���ǹ�Ķ�����
		auto repeat = Repeat::create(seq, 3);
		sprite_bullet->runAction(repeat);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-240, 0));
		auto bulletHide = Hide::create();//ִ���궯�������ؾ���
		auto bulletShow = Show::create();
		auto seq = Sequence::create(bulletShow,moveToLeft, bulletHide, NULL);
		//�����ظ���������ɻ���ǹ�Ķ�����
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

//��������
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

