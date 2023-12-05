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
	void ray::resetPA(vec2 playerLoc)
	{
		pA = playerLoc;
	}
	void ray::resetPB()
	{
		pB = pA + relative_pB;
	}
	void ray::calculatePB(vec2 linePointA, vec2 linePointB)
	{

		// Calculates denominator of equations
		const float den = (pA.x - pB.x) * (linePointA.y - linePointB.y) - (pA.y - pB.y) * (linePointA.x - linePointB.x);

		if (den == 0)
			return;

		const float t = ((pA.x - linePointA.x) * (linePointA.y - linePointB.y) - (pA.y - linePointA.y) * (linePointA.x - linePointB.x)) / den;
		const float u = -((pA.x - pB.x) * (pA.y - linePointA.y) - (pA.y - pB.y) * (pA.x - linePointA.x)) / den;

		// If there's an intersection...
		if (t > 0 && t < 1 && u > 0 && u < 1)
		{
			// Gets intersection point
			pB.x = pA.x + t * (pB.x - pA.x);
			pB.y = pA.y + t * (pB.y - pA.y);
		}
	}
	vec2 ray::calculatePA(vec2 linePointA, vec2 linePointB)
	{
		const float difXpApB = pA.x - pB.x;
		const float difYpApB = pA.y - pB.y;

		const float difXlAlB = linePointA.x - linePointB.x;
		const float difYlAlB = linePointA.y - linePointB.y;
		// Calculates denominator of equations
		const float den = difXpApB * difYlAlB - difYpApB * difXlAlB;

		if (den == 0)
		{
			return pB;
		}

		const float difXpAlA = pA.x - linePointA.x;
		const float difYpAlA = pA.y - linePointA.y;

		const float t = (difXpAlA * difYlAlB - difYpAlA * difXlAlB) / den;
		const float u = -(difXpApB * difYpAlA - difYpApB * difXpAlA) / den;

		// If there's an intersection...
		if (t > 0 && t < 1 && u > 0 && u < 1)
		{
			// Gets intersection point
			return vec2((pA.x + t * (pB.x - pA.x)), (pA.y + t * (pB.y - pA.y)));
		}
	}
	void ray::draw(Surface* screen, Pixel color)
	{
		screen->Line(pA.x, pA.y, pB.x, pB.y, color);
	}
}