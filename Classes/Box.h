#pragma once
#include<cstdlib>
#include<time.h>
#include<vector>
#include"GameScene.h"


class Box:public Layer
{
public:
	CREATE_FUNC(Box);
	 virtual bool init();

	 void drop(int* boxes_type, int* boxes_positionx, int* boxes_positiony,int times);

	 int producePositionx(int width2)const;//降落位置随机生成
	 int produceType()const;//两种枪加炸弹随机生成

private:
};
