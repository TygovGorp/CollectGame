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
		screen->Box(locPointA.x, locPointA.y, locPointB.x, locPointB.y, color);
	}
}