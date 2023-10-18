#pragma once
#include "object.h"
#include "animation.h"
#include "collision.h"

namespace Tmpl8
{
	class will : public object
	{
	public:
		void init(Surface* screen);

		void update();

		void Interaction();

		bool getState() { return pickedUp; };
	private:
		bool pickedUp = false;
		int frameNum = 1;
		animation willAnim;
	};
}

