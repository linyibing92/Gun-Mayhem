#pragma once
#include"cocos2d.h"
USING_NS_CC;

#include"ui/CocosGUI.h"
using namespace ui;
#include"Gun.h"
#include"MyLayer.h"
class MyLoadingBar:public Layer
{
public :
	CREATE_FUNC(MyLoadingBar);
	virtual bool init();
	void setHP_robot(int harm);//��������1robot��Ѫ��
	void setHP_wmale(int harm);//��������2wmale��Ѫ��
	float getHP_robot();
	float getHP_wmale();
	virtual void update(float delta);
private:
	LoadingBar* _myLoadingBar_1 = LoadingBar::create();
	LoadingBar* _myLoadingBar_2 = LoadingBar::create();
	float HP_robot = 120;//����1Ѫ��
	float HP_wmale = 120;//����2Ѫ��
};



