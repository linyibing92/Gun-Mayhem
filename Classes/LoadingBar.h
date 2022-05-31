#pragma once
#include"cocos2d.h"
USING_NS_CC;

#include"ui/CocosGUI.h"
using namespace ui;

class MyLoadingBar
{
public:
	LoadingBar* getLoadingBar();
private:
	LoadingBar* _bar;
};