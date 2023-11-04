#include "main_menu.h"
#include <iostream>

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
	void main_menu::update(int levelNum, int mainMenuStage, Surface* screen)
	{
		title.update(1, screenW -1 , screenH - 1, screen);
		if (levelNum == 0 && mainMenuStage == 1)
		{
			playAndSettings.update(1, screenW - 1, screenH - 1, screen);
		}
		else if (levelNum == 0 && mainMenuStage == 3)
		{
			difficultys.update(1, screenW - 1, screenH - 1, screen);
		}
	}
	void main_menu::Button(int& levelNum, int& mainMenuStage, int& difficulty, int mouseX, int mouseY, int key)
	{
		if (levelNum == 0 && mainMenuStage == 1)
		{
			if (mouseX < 501 && mouseX > 300 &&
				mouseY < 349 && mouseY > 290 &&
				key == 1)
			{
				mainMenuStage = 3;
			}
			else if (mouseX < 600 && mouseX > 200 &&
					mouseY < 414 && mouseY > 355 &&
					key == 1)
			{
				//settings
				std::cout << "settings" << std::endl;
			}
		}
		else if (levelNum == 0 && mainMenuStage == 3)
		{
			if (mouseX < 505 && mouseX > 296 &&
				mouseY < 349 && mouseY > 290 &&
				key == 1)
			{
				levelNum = 1;
				difficulty = 1;
			}
			else if (mouseX < 554 && mouseX > 246 &&
					mouseY < 412 && mouseY > 354 &&
					key == 1)
			{
				//medium
				std::cout << "medium" << std::endl;
			}
			else if (mouseX < 501 && mouseX > 300 &&
				mouseY < 478 && mouseY > 419 &&
				key == 1)
			{
				std::cout << "hard" << std::endl;
			}
		}
	}
}