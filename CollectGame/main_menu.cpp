#include "main_menu.h"
namespace Tmpl8
{
	void main_menu::init(Surface* screen, int ScreenWidth, int ScreenHeight)
	{
		screenH = ScreenHeight;
		screenW = ScreenWidth;
		title.init(1, "assets/temp_Title_Screen.png", 1, 1, screen);
		playAndSettings.init(1, "assets/temp_Title_Screen_PlaySettings.png", 1, 1, screen);
		difficultys.init(1, "assets/temp_Title_Screen_Difficultys.png", 1, 1, screen);
	}
	void main_menu::update(float levelNum)
	{
		title.update(1, screenW, screenH);
		if (levelNum == 0.1)
		{
			playAndSettings.update(1, screenW, screenH);
		}
		if (levelNum == 0.2)
		{
			difficultys.update(1, screenW, screenH);
		}
	}
}