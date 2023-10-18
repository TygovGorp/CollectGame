#pragma once
#include <vector>
#include "wall.h"
#include "will.h"

namespace Tmpl8
{
	class level
	{
	public:
		void init(int levelNum, Surface* ScreenSurface);
		void update();
		void reset();
	private:
		Surface* screen;
		std::vector<wall> wallVec;
		will willInstance;
	};
}

