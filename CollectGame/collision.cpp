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

		int Aw = static_cast<int>(recA2.x - recA1.x);
		int Ah = static_cast<int>(recA2.y - recA1.y);

		int Bw = static_cast<int>(recB2.x - recB1.x);
		int Bh = static_cast<int>(recB2.y - recB1.y);

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
	bool collision::lineSquareCol(ray Ray, vec2 squareA, vec2 squareB)
	{
		//based on https://www.jeffreythompson.org/collision-detection/line-rect.php
		//get width and height
		int h = squareB.y - squareA.y;
		int w = squareB.x - squareA.x;

		bool top = false;
		bool bottom = false;
		bool left = false;
		bool right = false;

		//checks if the ray collides with the top line of the square
		vec2 topHitCord = Ray.calculatePA(squareA, vec2(squareB.x, squareB.y - h));
		if (topHitCord.x != Ray.getPB().x && topHitCord.y != Ray.getPB().y) top = true;

		//checks if the ray collides with the bottom line of the square
		vec2 bottomHitCord = Ray.calculatePA(vec2(squareA.x, squareA.y + h), squareB);
		if (bottomHitCord.x != Ray.getPB().x && bottomHitCord.y != Ray.getPB().y) bottom = true;

		//checks if the ray collides with the left line of the square
		vec2 leftHitCord = Ray.calculatePA(squareA, vec2(squareB.x- w, squareB.y));
		if (leftHitCord.x != Ray.getPB().x && leftHitCord.y != Ray.getPB().y) left = true;

		//checks if the ray collides with the right line of the square
		vec2 rightHitCord = Ray.calculatePA(vec2(squareA.x + w, squareA.y), squareB);
		if (rightHitCord.x != Ray.getPB().x && rightHitCord.y != Ray.getPB().y) right = true;

		//returns true if any of the sides of the square is hit
		return left || right || top || bottom ? true : false;
	}
}
