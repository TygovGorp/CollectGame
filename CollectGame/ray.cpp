#include "ray.h"
#include <iostream>
#include <math.h>

namespace Tmpl8
{
	ray::ray(vec2 rel_end, vec2 pointA) //in radian
	{
		// Set end point relative to point A
		// Add arbitrary length
		relative_pB = rel_end * 3000.f;
		pA = pointA;
	}
	void ray::init(vec2 rel_end, vec2 pointA) //in radian
	{
		// Set end point relative to point A
		// Add arbitrary length
		relative_pB = rel_end * 2000.f;
		pA = pointA;
	}
	void ray::update(vec2 playerLoc)
	{
		pA = playerLoc;
	}
	void ray::resetPB()
	{
		pB = pA + relative_pB;
	}
	void ray::calculatePB(vec2 linePointA, vec2 linePointB)
	{
		const vec2 p1 = pA;
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
	vec2 ray::calculatePA(vec2 linePointA, vec2 linePointB)
	{
		const vec2 p1 = pA;
		const vec2 p2 = pB;

		// Calculates denominator of equations
		const float den = (p1.x - p2.x) * (linePointA.y - linePointB.y) - (p1.y - p2.y) * (linePointA.x - linePointB.x);

		if (den == 0)
			return pA;

		const float t = ((p1.x - linePointA.x) * (linePointA.y - linePointB.y) - (p1.y - linePointA.y) * (linePointA.x - linePointB.x)) / den;
		const float u = -((p1.x - p2.x) * (p1.y - linePointA.y) - (p1.y - p2.y) * (p1.x - linePointA.x)) / den;

		// If there's an intersection...
		if (t > 0 && t < 1 && u > 0 && u < 1)
		{
			// Gets intersection point
			return vec2((p1.x + t * (p2.x - p1.x)), (p1.y + t * (p2.y - p1.y)));
		}
	}
	void ray::draw(Surface* screen, Pixel color)
	{
		screen->Line(pA.x, pA.y, pB.x, pB.y, color);
	}
}