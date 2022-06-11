#include "bomb.h"

//����ը��������
void Bomb::bomb_move(Vec2 characterposition,int _flip) const
{
	if (_flip == 1) {
		ccBezierConfig bezier;//���������߶���
		bezier.controlPoint_1 = Point(characterposition.x, characterposition.y);
		bezier.controlPoint_2 = Point(150 + characterposition.x, 200 + characterposition.y);
		bezier.endPosition = Point(250 + characterposition.x, characterposition.y);
		BezierTo* BezierTo = BezierTo::create(0.8f, bezier);

		auto bombHide = Hide::create();//�������ʧ�ͳ���
		auto bombShow = Show::create();
		auto seq = Sequence::create(bombShow, BezierTo, bombHide, NULL);
		sprite_bomb->runAction(seq);
		auto soundbomb = AudioEngine::play2d("bomb.mp3", false);
	}
	else {
		ccBezierConfig bezier;//���������߶���
		bezier.controlPoint_1 = Point(characterposition.x, characterposition.y);
		bezier.controlPoint_2 = Point(-150 + characterposition.x, 200 + characterposition.y);
		bezier.endPosition = Point(-250 + characterposition.x, characterposition.y);
		BezierTo* BezierTo = BezierTo::create(0.8f, bezier);

		auto bombHide = Hide::create();//�������ʧ�ͳ���
		auto bombShow = Show::create();
		auto seq = Sequence::create(bombShow, BezierTo, bombHide, NULL);
		sprite_bomb->runAction(seq);
		auto soundbomb = AudioEngine::play2d("bomb.mp3", false);
	}
}

int Bomb::GetWeaponpower()const
{
	return Bomb::MyPower;
}