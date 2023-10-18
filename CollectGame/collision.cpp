#include "collision.h"
#include <iostream>

namespace Tmpl8
{
	bool collision::AABB(const vec2 recA1, const vec2 recB1)
	{
		vec2 recA2 = { recA1.x + 60, recA1.y + 60 };
		vec2 recB2 = { recB1.x + 60, recB1.y + 60 };

		int leftA = std::min(recA1.x, recA2.x);
		int rightA = std::max(recA1.x, recA2.x);
		int topA = std::min(recA1.y, recA2.y);
		int bottomA = std::max(recA1.y, recA2.y);

		int leftB = std::min(recB1.x, recB2.x);
		int rightB = std::max(recB1.x, recB2.x);
		int topB = std::min(recB1.y, recB2.y);
		int bottomB = std::max(recB1.y, recB2.y);

		if (rightA >= leftB && rightB >= leftA && bottomA >= topB && bottomB >= topA) {
			return true; // Rectangles overlap
		}

		return false; // Rectangles do not overlap

	}

	bool collision::AABB(const vec2 recA1, const vec2 recA2, const vec2 recB1, const vec2 recB2) {
		int leftA = std::min(recA1.x, recA2.x);
		int rightA = std::max(recA1.x, recA2.x);
		int topA = std::min(recA1.y, recA2.y);
		int bottomA = std::max(recA1.y, recA2.y);

		int leftB = std::min(recB1.x, recB2.x);
		int rightB = std::max(recB1.x, recB2.x);
		int topB = std::min(recB1.y, recB2.y);
		int bottomB = std::max(recB1.y, recB2.y);

		if (rightA >= leftB && rightB >= leftA && bottomA >= topB && bottomB >= topA) {
			return true; // Rectangles overlap
		}

		return false; // Rectangles do not overlap
	}


}
