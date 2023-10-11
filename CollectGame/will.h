#pragma once
#include "object.h"
#include "animation.h"

namespace Tmpl8
{
	class will : public object
	{
	public:
		will();

		void init(Surface* screen);

		void update();

		void onInteract();
	private:
		int frameNum = 1;
		animation willAnim;
	};
}

