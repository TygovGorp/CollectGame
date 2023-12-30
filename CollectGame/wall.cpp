#include "wall.h"

namespace Tmpl8
{
	void wall::setLocPoints(vec2 pointA, vec2 pointB)
	{
		locPointA = pointA;
		locPointB = pointB;
	}

	void wall::update(Surface* screen, Pixel color)
	{
		screen->Bar(static_cast<int>(locPointA.x), static_cast<int>(locPointA.y), static_cast<int>(locPointB.x), static_cast<int>(locPointB.y), color);
	}

	void wall::setPointA(vec2 A)
	{ 
		locPointA = A; 
	}

	void wall::setPointB(vec2 B)
	{
		locPointB = B;
	}
}