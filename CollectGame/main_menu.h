#pragma once
#include "template.h"
#include "animation.h"

namespace Tmpl8
{
	class main_menu
	{
	public:
		void init(Surface* screen, int ScreenWidth, int ScreenHeight);
		void update(float levelNum);
	private:
		animation title;
		animation playAndSettings;
		animation difficultys;
		int screenH;
		int screenW;
	};
}