#include "screenFragment.h"
namespace Tmpl8
{
	void screenFragment::addID(int ID)
	{
		IDofContainedWalls.push_back(ID);
	}

	std::vector<int> screenFragment::returnContainedWalls()
	{
		return IDofContainedWalls;
	}

	void screenFragment::reset()
	{
		IDofContainedWalls.clear();
	}
}