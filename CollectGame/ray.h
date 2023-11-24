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
		ray(vec2 rel_end);
		void init(vec2 rel_end);
		void setPoints(vec2 playerPos);
		void calclateHit(vec2 wallPointA, vec2 wallPointB, vec2 playerPos);
		void draw(vec2 pointA, Surface* screen, Pixel color);

		std::vector<vec2> getAllPointOnRay(vec2 pointA);

		vec2 getPB() { return pB; };
	private:
		vec2 pB;
		vec2 relative_pB;
	};
}