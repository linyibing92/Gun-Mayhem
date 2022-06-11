#pragma once
#include"cocos2d.h"
USING_NS_CC;//using namespace cocosdµÄºê¶¨Òå

#include"ui/CocosGUI.h"
using namespace ui;

#include"MyLayer.h"
class SelectScene :public Scene
{
public:
	CREATE_FUNC(SelectScene);
	static Scene* createScene();
	virtual bool init();
private:

};
