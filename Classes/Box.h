#pragma once
#include<cstdlib>
#include<time.h>
#include"GameScene.h"


class Box:public Layer
{
public:
	CREATE_FUNC(Box);
	 virtual bool init();
	 Sprite* drop();
private:
	Sprite* _box;
	Sprite* _land1 = Sprite::create("land3(1).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
};

int producePositionx(int width2);
int produceType();