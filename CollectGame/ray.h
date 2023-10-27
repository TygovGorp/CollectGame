#pragma once
#include "template.h"

namespace Tmpl8
{
	class ray
	{
	public:
		ray() {};
		ray(vec2 mousePos);
		void setPoints(vec2 A, vec2 B);
		void calclateHit(vec2 wallPointA, vec2 wallPointB, vec2 mousePos);
	private:
		vec2 pA;
		vec2 pB;
	};
}
