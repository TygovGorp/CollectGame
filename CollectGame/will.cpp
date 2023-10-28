#include "will.h"

namespace Tmpl8
{
	void will::init()
	{
		willAnim.init(frameNum, "assets/temp_will.png", loc.x, loc.y);
	}

	void will::update(Surface* surface)
	{
		if (!pickedUp)
		{
			willAnim.update(frameNum, 60, 60, surface);
		}
	}

	void will::Interaction()
	{
		pickedUp = true;
	}
}