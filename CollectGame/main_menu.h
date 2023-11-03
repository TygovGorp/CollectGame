#pragma once
#include "template.h"
#include "animation.h"

namespace Tmpl8
{
	class main_menu
	{
	public:
		void init(Surface* screen, int ScreenWidth, int ScreenHeight);
		void update(int levelNum, int mainMenuStage);
		void Button(int& levelNum, int& mainMenuStage, vec2 mouseLoc, int key);
	private:
		animation title;
		animation playAndSettings;
		animation difficultys;
		int screenH;
		int screenW;
	};
}