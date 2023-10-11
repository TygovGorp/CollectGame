#include "will.h"

namespace Tmpl8
{
	will::will()
	{
		
	}

	void will::init(Surface* screen)
	{
		willAnim.init(frameNum, "assets/temp_will.png", loc.x, loc.y, screen);
	}

	void will::update()
	{
		willAnim.update(frameNum);
	}

	void will::onInteract()
	{

	}
}