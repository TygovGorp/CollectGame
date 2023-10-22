#include "UI.h"
#include<iostream>
#include <string>

using namespace std;

namespace Tmpl8
{
	void UI::init(Surface* surface, int levelNum, int hp)
	{
		initLevelTxt(surface);
		initLevelCounter(surface, levelNum);

		initHpCounter(surface, hp);
	}
	void UI::update(Surface* surface, int levelNum, int hp)
	{
		updateLevelCounter(surface, levelNum);
		
		updateHpCounter(hp);
	}

	void UI::initLevelTxt(Surface* surface)
	{
		levelTxtAnimation.init(1, "assets/temp_Level_txt.png", levelTxtLoc.x, levelTxtLoc.y, surface);
	}
	void UI::initLevelCounter(Surface* surface, int levelNum)
	{
		currentLevelNum = levelNum;

		//written with the help of ChatGPT
		std::string filename = "assets/temp_" + std::to_string(levelNum) + "_txt.png";

		// Create a character array and copy the content of the std::string into it
		char filenameBuffer[256]; // Adjust the size as needed
		std::strcpy(filenameBuffer, filename.c_str());
		//until here

		cout << filenameBuffer << endl;

		levelCounterAnimation.init(1, filenameBuffer, levelCounterLoc.x, levelCounterLoc.y, surface);
	}

	void UI::updateLevelCounter(Surface* surface, int levelNum)
	{
		levelTxtAnimation.update(1, levelTxtLoc.x, levelTxtLoc.y, 120, 30);

		if (currentLevelNum != levelNum)
		{
			initLevelCounter(surface, levelNum);
		}
		
		levelCounterAnimation.update(1, levelCounterLoc.x, levelCounterLoc.y, 30, 30);
	}

	void UI::initHpCounter(Surface* surface, int hp)
	{
		for (int i = 0; i < hp; i++)
		{
			heartAnimVec.push_back(new animation);
			heartAnimVec.back()->init(1, "assets/temp_Heart.png", heartLoc.x - 40 * i, heartLoc.y, surface);
		}
	}
	void UI::updateHpCounter(int hp)
	{
		for (int i = 0; i < hp; i++)
		{
			heartAnimVec[i]->update(1, 30, 30);
		}
	}
}
