#include <bomb.h>

//ÉèÖÃÕ¨µ¯Å×ÎïÏß
void Bomb::bomb_move(Vec2 characterposition) const
{
	ccBezierConfig bezier;
	bezier.controlPoint_1 = Point(characterposition.x, characterposition.y);
	bezier.controlPoint_2 = Point(150+ characterposition.x, 200+ characterposition.y);
	bezier.endPosition = Point(250+ characterposition.x, characterposition.y);
	BezierTo* BezierTo = BezierTo::create(0.8f, bezier);
	sprite_bomb->runAction(BezierTo);
}
