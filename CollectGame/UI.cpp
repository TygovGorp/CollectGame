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
		
		updateHpCounter(hp, surface);
	}

	//prepares the levelTxtAnimation for use
	void UI::initLevelTxt(Surface* surface)
	{
		levelTxtAnimation.init(1, "assets/Level_txt.png", static_cast<int>(levelTxtLoc.x), static_cast<int>(levelTxtLoc.y), surface);
	}

	//prepares the levelCounterAnimation for use (it gets the level number and based on that loads the number into the levelCounterAnimation)
	void UI::initLevelCounter(Surface* surface, int levelNum)
	{
		currentLevelNum = levelNum;

		//the following code is written with the help of ChatGPT 3.5 (converts a string into a char type variable)

		std::string filename = "assets/" + std::to_string(levelNum) + "_txt.png";

		// Create a character array and copy the content of the std::string into it
		char filenameBuffer[256]; // Adjust the size as needed
		std::strcpy(filenameBuffer, filename.c_str());

		//until here

		levelCounterAnimation.init(1, filenameBuffer, static_cast<int>(levelCounterLoc.x), static_cast<int>(levelCounterLoc.y), surface);
	}

	//updates the levelCounterAnimation and changes the number if nessesary
	void UI::updateLevelCounter(Surface* surface, int levelNum)
	{
		levelTxtAnimation.update(1, static_cast<int>(levelTxtLoc.x), static_cast<int>(levelTxtLoc.y), 120, 30, surface);

		if (currentLevelNum != levelNum)
		{
			initLevelCounter(surface, levelNum);
		}
		
		levelCounterAnimation.update(1, static_cast<int>(levelCounterLoc.x), static_cast<int>(levelCounterLoc.y), 30, 30, surface);
	}

	//prepares the heartAnimVec (holds all the animations for the hearts) for use
	void UI::initHpCounter(Surface* surface, int hp)
	{
		for (int i = 0; i < hp; i++)
		{
			heartAnimVec.push_back(new animation);
			heartAnimVec.back()->init(1, "assets/temp_Heart.png", static_cast<int>(heartLoc.x - 40 * i), static_cast<int>(heartLoc.y), surface);
		}
	}
	
	//updates all the animations contained in heartAnimVec
	void UI::updateHpCounter(int hp, Surface* surface)
	{
		for (int i = 0; i < hp; i++)
		{
			heartAnimVec[i]->update(1, 30, 30, surface);
		}
	}
}
