#include "trap.h"

namespace Tmpl8
{
	trap::trap()
	{
		
	}

	void trap::init(Surface* screen)
	{
		trapAnim.init(1, "assets/temp_Trap.png", loc.x, loc.y, screen);
	}

	void trap::update()
	{
		trapAnim.update(1, pointB.x - loc.x, pointB.y - loc.y);
	}

	void trap::setPointB(vec2 pB)
	{
		pointB = pB;
	}
}