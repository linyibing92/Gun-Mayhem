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
private:
	LoadingBar* _myLoadingBar_1 = LoadingBar::create();
	LoadingBar* _myLoadingBar_2 = LoadingBar::create();
};



