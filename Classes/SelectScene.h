#pragma once
#include"cocos2d.h"
USING_NS_CC;//using namespace cocosd�ĺ궨��

#include"ui/CocosGUI.h"
using namespace ui;

class SelectScene :public Scene
{
public:
	CREATE_FUNC(SelectScene);
	static Scene* createScene();
	virtual bool init();
};
