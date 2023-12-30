#pragma once
#include "animation.h"
#include "surface.h"

namespace Tmpl8
{
	class storyManager
	{
	public:
		//initializes the image which contains the right text
		void init(int& subLevelStage, int levelNum, int difficulty, Surface* screen);
		//updates the image
		void update(Surface* screen);
		//checks if the player pressed "left mouse button" and if they did proceed to the actual level
		void nextStage(int key, int& subLevelStage, int levelNum);
	private:
		animation storyAnim;
	};
}

