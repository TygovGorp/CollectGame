#include "main_menu.h"
#include <iostream>
#include <SDL_scancode.h>

namespace Tmpl8
{
	void main_menu::init(Surface* screen, int ScreenWidth, int ScreenHeight)
	{
		screenH = ScreenHeight;
		screenW = ScreenWidth;
		title.init(1, "assets/Title_Screen.png", 1, 1, screen);
		playAndSettings.init(1, "assets/Title_Screen_Play.png", 1, 1, screen);
		difficultys.init(1, "assets/Title_Screen_Difficultys.png", 1, 1, screen);
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
		//goes to difficulty screen
		if (levelNum == 0 && mainMenuStage == 1)
		{
			if (mouseX < 501 && mouseX > 300 &&
				mouseY < 349 && mouseY > 290 &&
				key == 1)
			{
				mainMenuStage = 3;
			}
		}
		else if (levelNum == 0 && mainMenuStage == 3)
		{
			//goes to easy
			if (mouseX < 505 && mouseX > 296 &&
				mouseY < 349 && mouseY > 290 &&
				key == 1)
			{
				//easy
				mainMenuStage = 0;
				levelNum = 1;
				difficulty = 1;
			}
			//goes to medium
			else if (mouseX < 554 && mouseX > 246 &&
					mouseY < 412 && mouseY > 354 &&
					key == 1)
			{
				//medium
				mainMenuStage = 0;
				levelNum = 1;
				difficulty = 2;
			}
			//goes to hard
			else if (mouseX < 501 && mouseX > 300 &&
				mouseY < 478 && mouseY > 419 &&
				key == 1)
			{
				//hard
				mainMenuStage = 0;
				levelNum = 1;
				difficulty = 3;
			}
		}
	}

	void main_menu::returnToPrevScreen(int key, int& mainMenuStage)
	{
		if (key == SDL_SCANCODE_BACKSPACE && mainMenuStage == 3) mainMenuStage = 1;
	}
}