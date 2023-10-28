#include "ray.h"
#include <iostream>

namespace Tmpl8
{
	ray::ray(float in_sc, float in_b)
	{
		sc = in_sc;
		b = in_b;
	}
	void ray::calclateHit(vec2 linePointA, vec2 linePointB)
	{
		float sc1 = sc;
		float b1 = b;
		float sc2 = (linePointA.y - linePointB.y) / (linePointA.x - linePointB.x);
		float b2 = 0;
		if (sc * linePointB.x < linePointB.y) {
			b = linePointB.y - static_cast<int>(sc * linePointB.x);
		}
		else {
			b = static_cast<int>(sc * linePointB.x) - linePointB.y;
		}

		if (sc1 != sc2) {
			// Lines are not parallel, so they intersect
			float x = (b2 - b1) / (sc1 - sc2);
			float y = sc1 * x + b1;

			std::cout <<  x << ", " << y << std::endl;

			if (x >= std::min(linePointA.x, linePointB.x) &&
				x <= std::max(linePointA.x, linePointB.x) &&
				y >= std::min(linePointA.y, linePointB.y) &&
				y <= std::max(linePointA.y, linePointB.y)) {
				std::cout << "Intersection at (" << x << ", " << y << ")" << std::endl;
			}
			else {
				std::cout << "No intersection within the line segments." << std::endl;
			}

		}
		else {
			if (b1 == b2) {
				// Lines are the same, and they intersect at all points along the line.
				std::cout << "Lines are the same, and they intersect at all points." << std::endl;
			}
			else {
				// Lines are parallel and do not intersect.
				std::cout << "Lines are parallel and do not intersect." << std::endl;
			}
		}
	}
}
