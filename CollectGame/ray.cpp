#include "ray.h"
#include <iostream>
#include "wall.h"
#include <math.h>

namespace Tmpl8
{
	ray::ray(vec2 playerLoc, vec2 wallCord)
	{
		//sc = dY/dX
		const float dY = (wallCord.y - playerLoc.y) < 0 ? -(wallCord.y - playerLoc.y) : (wallCord.y - playerLoc.y);
		const float dX = (wallCord.x - playerLoc.x) < 0 ? -(wallCord.x - playerLoc.x) : (wallCord.x - playerLoc.x);
		const float sc = dY / dX;
		const float a = atan(sc);
		relative_end = vec2(cos(a), sin(a)) * 3000.f;
	}

	// Reset end-point of ray
	void ray::reset(vec2 playerLoc)
	{
		// Set end-point to (default length) distance away from mouse in set direction
		pB = playerLoc + relative_end;
	}

	void ray::calculateHit(vec2 wallPointA, vec2 wallPointB)
	{
		const vec2 p1 = pA;
		const vec2 p2 = pB;
		const vec2 p3 = wallPointA;
		const vec2 p4 = wallPointB;


		// Calculates denominator of equations
		const float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
		//std::cout << den << std::endl;

		if (den == 0)
			return;

		const float t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
		const float u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;

		// If there's an intersection...
		if (t > 0 && t < 1 && u > 0 && u < 1)
		{
			// Gets intersection point
			pB.x = p1.x + t * (p2.x - p1.x);
			pB.y = p1.y + t * (p2.y - p1.y);
		}
	}
}
