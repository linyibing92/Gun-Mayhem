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
	 void drop(int* boxes_type, int* boxes_position, int times);
	 int producePositionx(int width2)const;//����λ���������
	 int produceType()const;//����ǹ��ը���������

private:
};
