#pragma once
#include "template.h"
#include "surface.h"

namespace Tmpl8
{
	class wall
	{
	public:
		//set pointA and pointB of the wall
		void setLocPoints(vec2 pointA, vec2 pointB);

		//update the wall
		void update(Surface* screen, Pixel color);

		vec2 getPointA() { return locPointA; };
		vec2 getPointB() { return locPointB; };

		void setPointA(vec2 A);
		void setPointB(vec2 B);
	private:
		vec2 locPointA;
		vec2 locPointB;
	};
}

