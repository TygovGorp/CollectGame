#pragma once
#include <vector>
#include "ray.h"
#include "wall.h"
#include "player.h"
#include "collision.h"
#include "screenFragment.h"

namespace Tmpl8
{
	//based on https://github.com/user-simon/2D-RayCasting/
	class LOS
	{
	public:
		void init(vec2 playerLoc);
		void update_darkness(Surface* screen, vec2 playerPos, std::vector<wall>& wallVec);
		void update_light(Surface* screen, vec2 playerPos);

	private:
		vec2 prevPlayerLoc;
		collision colInst;
		std::vector<ray> rays;
	};
}

