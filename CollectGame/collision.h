#pragma once
#include "template.h"
#include "ray.h"
#include "wall.h"
#include <vector>

namespace Tmpl8
{
	class collision
	{
	public:
		//AABB collision https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/
		bool AABB(const vec2 recA1, const vec2 recB1);
		bool AABB(const vec2 recA1, const vec2 recA2, const vec2 recB1, const vec2 recB2);

		//collision between line and a wall (square)
		void rayWallCol(vec2 pointA, ray& R, std::vector<wall> wallVec);

		//collision between line and square
		bool lineSquareCol(ray Ray, vec2 squareA, vec2 squareB);
	};
}

