#include "trap.h"

namespace Tmpl8
{
	trap::trap()
	{
		
	}

	void trap::init()
	{
		trapAnim.init(1, "assets/temp_Trap.png", loc.x, loc.y);
	}

	void trap::update(Surface* screen)
	{
		trapAnim.update(1, pointB.x - loc.x, pointB.y - loc.y, screen);
	}

	void trap::setPointB(vec2 pB)
	{
		pointB = pB;
	}
	
	vec2 trap::getPointB()
	{
		return pointB;
	}

	int trap::getDMG()
	{
		return DMG;
	}
}