#include "will.h"

namespace Tmpl8
{
	void will::init(Surface* screen)
	{
		willAnim.init(frameNum, "assets/temp_will.png", loc.x, loc.y, screen);
	}

	void will::update(Surface* screen)
	{
		if (!pickedUp)
		{
			willAnim.update(frameNum, 60, 60, screen);
		}
	}

	void will::Interaction()
	{
		pickedUp = true;
	}
}