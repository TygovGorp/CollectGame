#pragma once
#include "template.h"

namespace Tmpl8
{
	class collision
	{
	public:
		bool AABB(const vec2 recA1, const vec2 recB1);
		bool AABB(const vec2 recA1, const vec2 recA2, const vec2 recB1, const vec2 recB2);
	};
}
