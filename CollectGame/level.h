#pragma once
#include <vector>
#include "wall.h"
#include "trap.h"

namespace Tmpl8
{
	class level
	{
	public:
		void init(int levelNum, Surface* ScreenSurface);
		void update(Surface* surface);

		vec2 getWillLoc();
		vec2 getPlayerStartLoc();
		std::vector<wall> getWallVec();
		std::vector<trap> getTrapVec();

		void reset();
	private:
		Surface* screen;
		std::vector<wall> wallVec;
		std::vector<trap> trapVec;
		vec2 willLoc;
		vec2 playerStartLoc;
	};
}

