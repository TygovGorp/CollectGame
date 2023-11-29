#pragma once
#include "template.h"
#include "surface.h"
#include <vector>

namespace Tmpl8
{
	class ray
	{
	public:
		ray() {};
		ray(vec2 rel_end, vec2 pointA);
		void init(vec2 rel_end, vec2 pointA);
		void update(vec2 playerLoc);
		
		void calculatePB(vec2 linePointA, vec2 linePointB);
		vec2 calculatePA(vec2 linePointA, vec2 linePointB);
		
		void draw(Surface* screen, Pixel color);

		void resetPB();
		void setPB(vec2 pointB) { pB = pointB; };
		void setPA(vec2 pointA) { pA = pointA; };
		vec2 getPB() { return pB; };
		vec2 getPA() { return pA; };
	private:
		vec2 pA;
		vec2 pB;
		vec2 relative_pB;
	};
}