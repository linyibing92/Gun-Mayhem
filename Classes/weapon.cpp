#include "weapon.h"

void weapon::SetWeaponState(bool Is_picked)
{
	_Is_picked = Is_picked;
}

bool weapon::GetweaponState()const
{
	return _Is_picked;
}


int weapon::GetWeaponpower()const
{
	return 0;
}

Vec2 weapon::getWeaponPosition()const
{

	return Vec2();
}

int weapon::attack()
{
	return 0;
}

