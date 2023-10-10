#pragma once
#include "template.h"
#include "surface.h"

namespace Tmpl8
{
	class wall
	{
	public:
		void setLocPoints(vec2 pointA, vec2 pointB);
		void update(Surface* screen, Pixel color);

		vec2 getPointA() { return locPointA; };
		vec2 getPointB() { return locPointB; };
	private:
		vec2 locPointA;
		vec2 locPointB;
	};
}
