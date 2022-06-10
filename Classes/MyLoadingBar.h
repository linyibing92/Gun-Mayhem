#pragma once
#include"cocos2d.h"
USING_NS_CC;

#include"ui/CocosGUI.h"
using namespace ui;
#include"Gun.h"

class MyLoadingBar:public Layer
{
public :
	CREATE_FUNC(MyLoadingBar);
	virtual bool init();
	void setHP_robot(int harm);//��������1robot��Ѫ��
	void setHP_wmale(int harm);//��������2wmale��Ѫ��
	virtual void update(float delta);
private:
	LoadingBar* _myLoadingBar_1 = LoadingBar::create();
	LoadingBar* _myLoadingBar_2 = LoadingBar::create();
	int HP_robot = 100;//����1Ѫ��
	int HP_wmale = 100;//����2Ѫ��
};



