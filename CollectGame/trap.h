#pragma once
#include "object.h"
#include "animation.h"

namespace Tmpl8
{
	class trap : public object
	{
	public:
		trap();
		void init(Surface* screen);
		void update();

		void setPointB(vec2 pB);
	private:
		vec2 pointB;
		animation trapAnim;
	};
}

