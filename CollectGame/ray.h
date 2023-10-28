#pragma once
#include "template.h"

namespace Tmpl8
{
	class ray
	{
	public:
		ray() {};
		ray(float in_sc, float in_b);
		void calclateHit(vec2 wallPointA, vec2 wallPointB);

		vec2 getPB() { return pB; };
	private:
		float sc = 0;
		float b = 0;
		vec2 pB;
	};
}
