#pragma once
#include "template.h"

namespace Tmpl8
{
	class ray
	{
	public:
		ray() {};
		ray(vec2 rel_end);
		void setPoints(vec2 playerPos);
		void calclateHit(vec2 wallPointA, vec2 wallPointB, vec2 playerPos);

		vec2 getPB() { return pB; };
	private:
		vec2 pB;
		vec2 relative_pB;
	};
}
