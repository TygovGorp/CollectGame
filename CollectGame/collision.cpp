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

	void collision::rayWallCol(vec2 pointA, ray& R, std::vector<wall> wallVec)
	{
		// Set ray end-point to default
		R.resetPB();

		// Cycle through every wall and set end point to intersection
		// When an intersection is found, the end-point is set to that intersection, meaning the next check will check for walls
		// between mouse and the new end-point. This means the ray will always go to the nearest wall
		for (int j = 0; j < wallVec.size(); j++)
		{
			vec2 wallPointA = wallVec[j].getPointA();
			vec2 wallPointB = wallVec[j].getPointB();

			// Calculate ray end-point
			const vec2 cornerA = wallPointA;
			const vec2 cornerB = { wallPointA.x, wallPointB.y };
			const vec2 cornerC = wallPointB;
			const vec2 cornerD = { wallPointB.x, wallPointA.y };

			//calculate hit on walls
			R.calculatePB(cornerA, cornerB);
			R.calculatePB(cornerB, cornerC);
			R.calculatePB(cornerC, cornerD);
			R.calculatePB(cornerD, cornerA);

		}
	}
}
