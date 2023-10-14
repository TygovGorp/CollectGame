#pragma once
#include <vector>
#include "wall.h"
#include "will.h"

namespace Tmpl8
{
	class level
	{
	public:
		void init(int levelNum);
		void update(Surface* screen);
		void reset();
	private:
		std::vector<wall> wallVec;
		will willInstance;
	};
}

