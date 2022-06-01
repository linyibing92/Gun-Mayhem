#include "weapon.h"

void weapon::SetWeaponState(bool Is_picked)
{
	_Is_picked = Is_picked;
}

bool weapon::GetweaponState()
{
	return _Is_picked;
}

void weapon::Weaponpower(int power)
{
	MyPower = power;
}

int weapon::GetWeaponpower()
{
	return MyPower;
}
