#pragma once

#include "cocos2d.h"
USING_NS_CC;

class weapon
{
public:

	/*��������״̬*/
	void SetWeaponState(bool Is_picked);

	/* ��ȡ����״̬ */
	bool GetweaponState()const;

	/* ������������ҽ��� */
	virtual int GetWeaponpower()const;/* ��ȡ������ */
	Vec2 getWeaponPosition()const;

	/* ʵ�ֲ�ͬ�����Ĺ�����ʽ */
	virtual int attack();
protected:
	bool _Is_picked = false; /* ������״̬ */
};




