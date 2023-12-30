#pragma once
#include <vector>
#include "ray.h"
#include "wall.h"
#include "player.h"

namespace Tmpl8
{
	//implementation inspired by https://github.com/user-simon/2D-RayCasting/
	class LOS
	{
	public:
		//prepares the rays for use
		void init(vec2 playerLoc);

		//updates the darkness part of rays
		void update_darkness(Surface* screen, vec2 playerPos, std::vector<wall>& wallVec);
		//updates the light part of rays
		void update_light(Surface* screen, vec2 playerPos);

	private:
		//calculates the collision point between the rays in range of start and end and walls
		void splitDarknessCalculation(Surface* screen, vec2 playerLoc, std::vector<wall>& wallVec, int start, int end);

		vec2 prevPlayerLoc;
		collision colInst;
		std::vector<ray> rays;
	};
}

