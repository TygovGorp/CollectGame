#include "will.h"

namespace Tmpl8
{
	void will::init(Surface* screen)
	{
		willAnim.init(frameNum, "assets/temp_will.png", loc.x, loc.y, screen);
	}

	void will::update()
	{
		if (!pickedUp)
		{
			willAnim.update(frameNum);
		}
	}

	void will::Interaction()
	{
		pickedUp = true;
	}
}