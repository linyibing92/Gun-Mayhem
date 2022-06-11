#include <bomb.h>


//设置炸弹抛物线
void Bomb::bomb_move(Vec2 characterposition,int _flip) const
{
	if (_flip == 1) {
		ccBezierConfig bezier;//贝塞尔曲线动作
		bezier.controlPoint_1 = Point(characterposition.x, characterposition.y);
		bezier.controlPoint_2 = Point(150 + characterposition.x, 200 + characterposition.y);
		bezier.endPosition = Point(250 + characterposition.x, characterposition.y);
		BezierTo* BezierTo = BezierTo::create(0.8f, bezier);

		auto bombHide = Hide::create();//精灵的消失和出现
		auto bombShow = Show::create();
		auto seq = Sequence::create(bombShow, BezierTo, bombHide, NULL);
		sprite_bomb->runAction(seq);
	}
	else {
		ccBezierConfig bezier;//贝塞尔曲线动作
		bezier.controlPoint_1 = Point(characterposition.x, characterposition.y);
		bezier.controlPoint_2 = Point(-150 + characterposition.x, 200 + characterposition.y);
		bezier.endPosition = Point(-250 + characterposition.x, characterposition.y);
		BezierTo* BezierTo = BezierTo::create(0.8f, bezier);

		auto bombHide = Hide::create();//精灵的消失和出现
		auto bombShow = Show::create();
		auto seq = Sequence::create(bombShow, BezierTo, bombHide, NULL);
		sprite_bomb->runAction(seq);
	}
}

int Bomb::GetWeaponpower()
{
	return Bomb::MyPower;
}