#pragma once
#include "animation.h"
#include "surface.h"

namespace Tmpl8
{
	class storyManager
	{
	public:
		void init(int& subLevelStage, int levelNum, int difficulty, Surface* screen);
		void update(Surface* screen);
		void nextStage(int key, int& subLevelStage, int levelNum);
	private:
		animation storyAnim;
	};
}

