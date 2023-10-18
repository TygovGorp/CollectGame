#include <fstream>
#include <string>
#include <iostream>
#include "level.h"

using namespace std;

namespace Tmpl8
{
	void level::init(int levelNum, Surface* ScreenSurface)
	{
		screen = ScreenSurface;
		fstream newfile;
		newfile.open("levels/level_" + to_string(levelNum) + ".txt", ios::in);

		if (newfile.is_open()) {

			string tp;

			bool nextWillLocation = false;
			int willx = 0;
			bool pointB = false;
			int wallx = 0;
			int counter = 1;

			while (getline(newfile, tp, ' ')) {
				if (nextWillLocation)
				{
				//	if (willx == 0)
				//	{
				//		willx = stoi(tp);
				//	}
				//	else
				//	{
				//		willInstance.setLoc(willx, stoi(tp));
				//		willx = 0;
				//		nextWillLocation = false;
				//	}
				} //still need to test this

				else
				{
					switch (counter)
					{
					case 1:
						wallVec.push_back(wall());
						wallx = stoi(tp);
						break;
					case 2:
						wallVec.back().setPointA(vec2(wallx, stoi(tp)));
						break;
					case 3:
						wallx = stoi(tp);
						break;
					case 4:
						wallVec.back().setPointB(vec2(wallx, stoi(tp)));
						counter = 0;
						break;
					default:
						break;
					}
					counter++;
				}

				tp.find("WillLocation") != std::string::npos ? nextWillLocation = true : nextWillLocation = false;
			}
			newfile.close();
		}

	}

	void level::update()
	{
		for (int i = 0; i < wallVec.size(); i++)
		{
			wallVec[i].update(screen, 0x666666);
		}
	}

	void level::reset()
	{
		wallVec.clear();
	}
}