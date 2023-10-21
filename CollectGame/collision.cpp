#include "collision.h"
#include <iostream>

namespace Tmpl8
{
	bool collision::AABB(const vec2 recA1, const vec2 recB1)
	{
		//written using https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/ as a reference

		int Aw = 60;
		int Ah = 60;

		int Bw = 60;
		int Bh = 60;

		if (
			recA1.x <  recB1.x + Bw &&
			recA1.x + Aw > recB1.x &&
			recA1.y <  recB1.y + Bh &&
			recA1.y + Ah > recB1.y
			) {
			return true; // Rectangles overlap
		}

		return false; // Rectangles do not overlap

	}

	bool collision::AABB(const vec2 recA1, const vec2 recA2, const vec2 recB1, const vec2 recB2) {
		//written using https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/ as a reference

		int Aw = recA2.x - recA1.x;
		int Ah = recA2.y - recA1.y;

		int Bw = recB2.x - recB1.x;
		int Bh = recB2.y - recB1.y;

		if (
			recA1.x <  recB1.x + Bw &&
			recA1.x + Aw > recB1.x &&
			recA1.y <  recB1.y + Bh &&
			recA1.y + Ah > recB1.y
			) {
			return true; // Rectangles overlap
		}

		return false; // Rectangles do not overlap

	}


}
