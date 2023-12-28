#pragma once
#include "template.h"
#include "animation.h"

namespace Tmpl8
{
	class main_menu
	{
	public:
		//initializes the animation and sets screen H and W 
		void init(Surface* screen, int ScreenWidth, int ScreenHeight);
		//update menu
		void update(int levelNum, int mainMenuStage, Surface* screen);
		//checks if button is pressed and preforms the expected action with the button
		void Button(int& levelNum, int& mainMenuStage, int& difficulty, int mouseX, int mouseY, int key);
		//returns you to previous screen in the main menu if you hit backspace
		void returnToPrevScreen(int key, int& mainMenuStage);
	private:
		animation title;
		animation playAndSettings;
		animation difficultys;
		int screenH;
		int screenW;
	};
}