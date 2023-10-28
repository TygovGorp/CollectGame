#pragma once
#include <vector>
#include "ray.h"
#include "wall.h"
#include "player.h"

namespace Tmpl8
{
	//loosely based on https://github.com/user-simon/2D-RayCasting
	class LOS
	{
	public:
		void init(std::vector<wall> wallVec, player Player);
		void update(Surface* screen, vec2 playerPos, std::vector<wall> wallVec);

	private:
		std::vector<ray> rays;
	};
}

