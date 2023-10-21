#include <fstream>
#include <string>
#include <iostream>
#include "level.h"

using namespace std;

namespace Tmpl8
{
	void level::init(int levelNum, Surface* ScreenSurface)
	{
		wallVec.clear();
		willLoc = { 0,0 };
		playerStartLoc = { 0,0 };

		screen = ScreenSurface;
		fstream newfile;
		newfile.open("levels/level_" + to_string(levelNum) + ".txt", ios::in);

		if (newfile.is_open()) {

			string tp;

			bool nextWillLocation = false;
			bool nextPlayerLocations = false;
			bool pointB = false;
			int wallx = 0;
			int counter = 1;

			while (getline(newfile, tp, ' ')) {

				if (tp.find("WillLocation") != std::string::npos)
				{
					nextWillLocation = true;
					counter = 1;
				}
				if (nextWillLocation)
				{

					switch (counter)
					{
					case 1:
						break;
					case 2:
						willLoc.x = stoi(tp);
						break;
					case 3:
						willLoc.y = stoi(tp);
						nextWillLocation = false;
						counter = 0;
						break;
					default:
						break;
					}
					counter++;
				}

				if (tp.find("PlayerLocation") != std::string::npos)
				{
					nextPlayerLocations = true;
					counter = 1;
				}
				if (nextPlayerLocations)
				{
					switch (counter)
					{
					case 1:
						break;
					case 2:
						playerStartLoc.x = stoi(tp);
						break;
					case 3:
						playerStartLoc.y = stoi(tp);
						nextPlayerLocations = false;
						counter = 0;
						break;
					default:
						break;
					}
					counter++;
				}

				if (!nextWillLocation && !nextPlayerLocations)
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

	std::vector<wall> level::getWallVec()
	{
		return wallVec;
	}

	vec2 level::getWillLoc()
	{
		return willLoc;
	}

	vec2 level::getPlayerStartLoc()
	{
		return playerStartLoc;
	}

	void level::reset()
	{
		wallVec.clear();
	}
}