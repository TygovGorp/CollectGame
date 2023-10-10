#include "base.h"

namespace Tmpl8
{
	base::base()
	{
		loc.x = 1;
		loc.y = 1;
	}
	base::base(int x, int y)
	{
		loc.x = x;
		loc.y = y;
	}

	void base::init(int x, int y)
	{
		loc.x = x;
		loc.y = y;
	}
}