#pragma once

#include "cocos2d.h"
USING_NS_CC;

class weapon
{
public:

	/*设置武器状态*/
	void SetWeaponState(bool Is_picked);

	/* 获取武器状态 */
	bool GetweaponState()const;

	/* 武器攻击与玩家交互 */
	virtual int GetWeaponpower()const;/* 获取攻击力 */
	Vec2 getWeaponPosition()const;

	/* 实现不同武器的攻击方式 */
	virtual int attack();
protected:
	bool _Is_picked = false; /* 武器的状态 */
};




