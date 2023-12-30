#include "trap.h"

namespace Tmpl8
{
	void trap::init(Surface* screen)
	{
		trapAnim.init(2, "assets/trap_", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
	}

	void trap::update(Surface* screen, bool trapHitState)
	{
		animFrame = trapHitState ? 2 : 1;
		trapAnim.update(animFrame, static_cast<int>(pointB.x - loc.x), static_cast<int>(pointB.y - loc.y), screen);
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