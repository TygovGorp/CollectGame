#include "collision.h"

namespace Tmpl8
{
	bool collision::AABB(const vec2 recA1, const vec2 recB1)
	{
		int wA = recB1.x - recA1.x;
		int hA = recB1.y - recA1.y;

		int wB = recA1.x - recB1.x;
		int hB = recA1.y - recB1.y;

		if (
			recA1.x + wA >= recB1.x &&
			recB1.x + wB >= recA1.x &&
			recA1.y + hA >= recB1.y &&
			recB1.y + hB >= recA1.y
			)
		{
			return true;
		}
		return false;

	}
}
