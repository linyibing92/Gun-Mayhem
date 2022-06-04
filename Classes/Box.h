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
	int _position_x;
	int _type;
	int width1;
	int width2;
	Sprite* _box;
	Sprite* _land1 = Sprite::create("land3(1).png");
	Sprite* _land2 = Sprite::create("land3(2).png");
};