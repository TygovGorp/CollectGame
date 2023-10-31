#pragma once
#include "template.h"
#include "wall.h"

namespace Tmpl8
{
	class ray
	{
		//based on https://github.com/user-simon/2D-RayCasting/
	public:
		ray() {};
		ray(vec2 rayPointA, vec2 rayPointB);
		void reset();
		void calculateHit(vec2 wallPointA, vec2 wallPointB);

		vec2 getPA() { return pA; };
		void setPA(vec2 pointA) { pA = pointA; };
		vec2 getPB() { return pB; };
		void setPB(vec2 pointB) { pB = pointB; };
	private:
		vec2 m_relative_end;
		vec2 pA;
		vec2 pB;
	};
}
