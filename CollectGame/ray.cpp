#include "ray.h"

namespace Tmpl8
{
	ray::ray(vec2 rel_end)
	{
		// Set end point relative to mouse cursor
		// Add arbitrary length
		relative_pB = rel_end * 3000.f;
	}
	void ray::setPoints(vec2 playerPos)
	{
		pB = playerPos + relative_pB;
	}
	void ray::calclateHit(vec2 linePointA, vec2 linePointB, vec2 playerPos)
	{
		const vec2 p1 = playerPos;
		const vec2 p2 = pB;

		// Calculates denominator of equations
		const float den = (p1.x - p2.x) * (linePointA.y - linePointB.y) - (p1.y - p2.y) * (linePointA.x - linePointB.x);

		if (den == 0)
			return;

		const float t = ((p1.x - linePointA.x) * (linePointA.y - linePointB.y) - (p1.y - linePointA.y) * (linePointA.x - linePointB.x)) / den;
		const float u = -((p1.x - p2.x) * (p1.y - linePointA.y) - (p1.y - p2.y) * (p1.x - linePointA.x)) / den;

		// If there's an intersection...
		if (t > 0 && t < 1 && u > 0 && u < 1)
		{
			// Gets intersection point
			pB.x = p1.x + t * (p2.x - p1.x);
			pB.y = p1.y + t * (p2.y - p1.y);
		}
	}
}
