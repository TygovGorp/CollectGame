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
		void update(Surface* screen, bool trapHitState);

		void setPointB(vec2 pB);
		vec2 getPointB();

		int getDMG();
	private:
		int animFrame = 1;
		int DMG = 1;
		vec2 pointB;
		animation trapAnim;
	};
}

