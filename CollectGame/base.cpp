#include "base.h"

namespace Tmpl8
{
	base::base()
	{
		loc.x = 1;
		loc.y = 1;
	}
	base::base(vec2 LOC)
	{
		loc = LOC;
	}
	base::base(int x, int y)
	{
		loc.x = static_cast<float>(x);
		loc.y = static_cast<float>(y);
	}

	void base::init(int x, int y)
	{
		loc.x = static_cast<float>(x);
		loc.y = static_cast<float>(y);
	}
}