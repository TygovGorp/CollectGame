#include <fstream>
#include <string>
#include "level.h"

using namespace std;

namespace Tmpl8
{
	void level::init(char* filename, int levelNum)
	{
		fstream newfile;
		newfile.open("Levels/Level_" + to_string(levelNum) + ".txt", ios::in);

		if (newfile.is_open()) {

			string tp;

			bool nextWillLocation = false;
			int willx = 0;
			bool secondWallLoop = false;
			int wallx = 0;

			while (getline(newfile, tp, ' ')) {
				if (nextWillLocation)
				{
					if (willx == 0)
					{
						willx = stoi(tp);

					}
					else
					{
						willInstance.setLoc(willx, stoi(tp));
						willx = 0;
						nextWillLocation = false;
					}
				}
				else
				{
					if (wallx == 0)
					{
						wallx = stoi(tp);
					}
					else
					{
						
						if (secondWallLoop)
						{
							wallVec.back().setPointB(vec2(wallx, stoi(tp)));
						}
						else
						{
							wallVec.push_back(wall());
							wallVec.back().setPointA(vec2(wallx, stoi(tp)));
						}
						
						wallx = 0;
						secondWallLoop = true;
					}
				}
				if (tp.find("WillLocation") != std::string::npos)
				{
					nextWillLocation = true;
				}
			}
			newfile.close();
		}

	}

	void level::update()
	{

	}

	void level::reset()
	{
		wallVec.clear();
	}
}