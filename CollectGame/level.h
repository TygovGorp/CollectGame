#pragma once
#include <vector>
#include "wall.h"
#include "will.h"

namespace Tmpl8
{
	class level
	{
	public:
		void init(char* filename, int levelNum);
		void update();
		void reset();
	private:
		std::vector<wall> wallVec;
		will willInstance;
	};
}

