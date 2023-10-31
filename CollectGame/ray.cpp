#include "ray.h"
#include <iostream>
#include "wall.h"

namespace Tmpl8
{
	ray::ray(vec2 rayPointA, vec2 rayPointB)
	{
		m_relative_end = rayPointA * 3000.f;
	}

	// Reset end-point of ray
	void ray::reset()
	{
		// Set end-point to (default length) distance away from mouse in set direction
		pB = pA + m_relative_end;
	}

	void ray::calculateHit(vec2 wallPointA, vec2 wallPointB)
	{
		float x1 = pA.x;
		float x2 = pB.x;
		float x3 = wallPointA.x;
		float x4 = wallPointA.x;
		float y1 = pA.y;
		float y2 = pB.y;
		float y3 = wallPointB.y;
		float y4 = wallPointB.x;


		// Calculates denominator of equations
		const float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

		if (den == 0)
			return;

		const float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
		const float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

		// If there's an intersection...
		if (t > 0 && t < 1 && u > 0 && u < 1)
		{
			// Gets intersection point
			pB.x = x1 + t * (x2 - x1);
			pB.y = y1 + t * (y2 - y1);
		}
	}
}
