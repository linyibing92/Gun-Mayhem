#include "weapon.h"

void weapon::SetWeaponState(bool Is_picked)
{
	_Is_picked = Is_picked;
}

bool weapon::GetweaponState()
{
	return _Is_picked;
}


int weapon::GetWeaponpower()
{
	return 0;
}

Vec2 weapon::getWeaponPosition()
{

	return Vec2();
}

int weapon::attack()
{
	return 0;
}

