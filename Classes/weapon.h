#pragma once

#include "cocos2d.h"
USING_NS_CC;

class weapon
{
public:

	/*��������״̬*/
	void SetWeaponState(bool Is_picked);

	/* ��ȡ����״̬ */
	bool GetweaponState();

	/* ������������ҽ��� */
	void Weaponpower(int power);/* ���ù����� */
	int GetWeaponpower();/* ��ȡ������ */
	Vec2 getWeaponPosition();

	/* ʵ�ֲ�ͬ�����Ĺ�����ʽ */
	virtual int attack();
protected:

	bool _Is_picked = false; /* ������״̬ */
	int MyPower = 0; /* ���������� */
};




