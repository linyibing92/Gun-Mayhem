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
	void setHP_robot(int harm);//设置人物1robot的血量
	void setHP_wmale(int harm);//设置人物2wmale的血量
private:
	LoadingBar* _myLoadingBar_1 = LoadingBar::create();
	LoadingBar* _myLoadingBar_2 = LoadingBar::create();
	int HP_robot = 100;//人物1血量
	int HP_wmale = 100;//人物2血量
};



