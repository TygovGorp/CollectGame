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
		void init(std::vector<wall> wallVec, vec2 playerLoc);
		void update(Surface* screen, vec2 playerLoc, std::vector<wall> wallVec);

	private:
		std::vector<ray> rays;
	};
}

