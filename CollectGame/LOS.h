#pragma once
#include <vector>
#include "ray.h"
#include "wall.h"
#include "player.h"
#include "collision.h"

namespace Tmpl8
{
	//based on https://github.com/user-simon/2D-RayCasting/
	class LOS
	{
	public:
		void init();
		void update(Surface* screen, vec2 playerPos, std::vector<wall> wallVec);

	private:
		collision colInst;
		std::vector<ray> rays;
	};
}

