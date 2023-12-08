#pragma once
#include <vector>

namespace Tmpl8
{
	class screenFragment
	{
	public:
		void addID(int ID);
		std::vector<int> returnContainedWalls();
		void reset();
	private:
		std::vector<int> IDofContainedWalls;
	};
}
