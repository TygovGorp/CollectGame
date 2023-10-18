#pragma once
#include <vector>
#include "wall.h"

namespace Tmpl8
{
	class level
	{
	public:
		void init(int levelNum, Surface* ScreenSurface);
		void update();
		vec2 getWillLoc();
		void reset();
	private:
		Surface* screen;
		std::vector<wall> wallVec;
		vec2 willLoc;
	};
}

