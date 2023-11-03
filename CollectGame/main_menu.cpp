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
	void main_menu::update(int levelNum, int mainMenuStage)
	{
		title.update(1, screenW -1 , screenH - 1);
		if (levelNum == 0 && mainMenuStage == 1)
		{
			playAndSettings.update(1, screenW - 1, screenH - 1);
		}
		else if (levelNum == 0 && mainMenuStage == 3)
		{
			difficultys.update(1, screenW - 1, screenH - 1);
		}
	}
	void main_menu::Button(int& levelNum, int& mainMenuStage, vec2 mouseLoc, int key)
	{
		if (levelNum == 0 && mainMenuStage == 1)
		{
			if (mouseLoc.x < 501 && mouseLoc.x > 300 &&
				mouseLoc.y < 349 && mouseLoc.y > 290 &&
				key == 1)
			{
				mainMenuStage = 3;
			}
			else if (mouseLoc.x < 600 && mouseLoc.x > 200 &&
				mouseLoc.y < 414 && mouseLoc.y > 355 &&
				key == 1)
			{
				levelNum = 1;
			}
		}
	}
}