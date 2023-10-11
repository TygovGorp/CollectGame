#include "object.h"

namespace Tmpl8
{
	object::object()
	{
		loc = { 1, 1 };
		collisionBox[0] = { 1, 1 };
		collisionBox[1] = { 1, 1 };
	}
	object::object(vec2 LOC, vec2 pointA, vec2 pointB)
	{
		loc = LOC;
		collisionBox[0] = pointA;
		collisionBox[1] = pointB;
	}
	object::object(int LOCx, int LOCy, int Ax, int Ay, int Bx, int By)
	{
		loc.x = LOCx;
		loc.y = LOCy;
		collisionBox[0].x = Ax;
		collisionBox[0].y = Ay;
		collisionBox[1].x = Bx;
		collisionBox[1].y = By;
	}

	void object::setLoc(vec2 LOC)
	{
		loc = LOC;
	}
	void object::setLoc(int LOCx, int LOCy)
	{
		loc.x = LOCx;
		loc.y = LOCy;
	}

	void object::setCollisionBox(vec2 A, vec2 B)
	{
		collisionBox[0] = A;
		collisionBox[1] = B;
	}
	void object::setCollisionBox(int Ax, int Ay, int Bx, int By)
	{
		collisionBox[0].x = Ax;
		collisionBox[0].y = Ay;
		collisionBox[1].x = Bx;
		collisionBox[1].y = By;
	}
}