#pragma once
#include <vector>
#include "ray.h"
#include "wall.h"
#include "player.h"

namespace Tmpl8
{
	class LOS
	{
	public:
		void init();
		void update(Surface* screen, vec2 playerPos, std::vector<wall> wallVec);

	private:
		std::vector<ray> rays;
	};
}

