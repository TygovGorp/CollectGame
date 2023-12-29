#include "storyManager.h"
#include <string>
#include <iostream>
namespace Tmpl8
{
	void storyManager::init(int& subLevelStage, int levelNum, int difficulty, Surface* screen)
	{
		char* filename = "story/";

		if (subLevelStage == 0)
		{
			//adds the right numbers into to filename so that it can find the right file

			std::string filename_str(filename); // convert char* to std::string
			filename_str = filename_str + std::to_string(levelNum) + ".png";

			char* filename_cstr = new char[filename_str.length() + 1];
			std::strcpy(filename_cstr, filename_str.c_str());

			//initializes the animation
			storyAnim.init(1, filename_cstr, 1, 1, screen);

			delete[] filename_cstr;
		}	
	}
	void storyManager::update(Surface* screen)
	{
		storyAnim.update(1, 799, 559, screen);
	}

	void storyManager::nextStage(int key, int& subLevelStage, int levelNum)
	{ 
		if (key == 1 && subLevelStage == 0 && levelNum != 0) subLevelStage++;
	};
}