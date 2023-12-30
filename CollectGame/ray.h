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

		// Set end point relative to point A and add arbitrary length
		ray(vec2 rel_end, vec2 pointA);
		void init(vec2 rel_end, vec2 pointA);

		void resetPA(vec2 playerLoc);
		
		//calculates the intersection point between ray and line. sets pB to this point
		void calculatePB(vec2 linePointA, vec2 linePointB);
		//calculates the intersection point between ray and line. returns this point
		vec2 calculatePA(vec2 linePointA, vec2 linePointB);
		
		//draws the line
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
		std::vector<vec2> collidedScreenFragments;
	};
}