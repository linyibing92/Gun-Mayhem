#include "Gun.h"
#include "weapon.h"

USING_NS_CC;

void GunM249::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveToRight = MoveBy::create(1, Point(240, 0));
		sprite_bullet->runAction(moveToRight);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-240, 0));
		sprite_bullet->runAction(moveToLeft);
	}
}

void GunP92::bulletmove(int _flip) const
{

	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveToRight = MoveBy::create(1, Point(200, 0));
		sprite_bullet->runAction(moveToRight);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-200, 0));
		sprite_bullet->runAction(moveToLeft);
	}
}
void Gun98K::bulletmove(int _flip) const
{
	if (_flip == GunRight)
	{
		sprite_bullet->setFlippedX(false);
		auto moveToRight = MoveBy::create(1, Point(480, 0));
		sprite_bullet->runAction(moveToRight);
	}
	else
	{
		sprite_bullet->setFlippedX(true);
		auto moveToLeft = MoveBy::create(1, Point(-480, 0));
		sprite_bullet->runAction(moveToLeft);
	}
}

//¹¥»÷º¯Êý
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

