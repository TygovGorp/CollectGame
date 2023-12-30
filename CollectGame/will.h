#pragma once
#include "object.h"
#include "animation.h"
#include "collision.h"

namespace Tmpl8
{
	class will : public object
	{
	public:
		//initializes willAnim
		void init(Surface* screen);

		//update willAnim
		void update(Surface* screen);

		//sets pickedUp to True
		void Interaction();

		//returns pickedUp
		bool getState() { return pickedUp; };
		//sets pickedUp to false
		void resetState() { pickedUp = false; };
	private:
		bool pickedUp = false;
		int frameNum = 1;
		animation willAnim;
	};
}

