#include "trap.h"

namespace Tmpl8
{
	trap::trap()
	{
		
	}

	void trap::init(Surface* screen)
	{
		trapAnim.init(2, "assets/trap_", loc.x, loc.y, screen);
	}

	void trap::update(Surface* screen, bool trapHitState)
	{
		animFrame = trapHitState ? 2 : 1;
		trapAnim.update(animFrame, pointB.x - loc.x, pointB.y - loc.y, screen);
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