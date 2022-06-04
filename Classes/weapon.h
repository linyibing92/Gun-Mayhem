#pragma once

#include "cocos2d.h"
USING_NS_CC;

class weapon
{
public:

	/*设置武器状态*/
	void SetWeaponState(bool Is_picked);

	/* 获取武器状态 */
	bool GetweaponState();

	/* 武器攻击与玩家交互 */
	void Weaponpower(int power);/* 设置攻击力 */
	int GetWeaponpower();/* 获取攻击力 */
	Vec2 getWeaponPosition();

	/* 实现不同武器的攻击方式 */

	//virtual int attack()=0;

protected:

	bool _Is_picked = false; /* 武器的状态 */
	int MyPower = 0; /* 武器攻击力 */
};




