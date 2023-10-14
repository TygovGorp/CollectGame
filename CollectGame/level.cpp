#include <fstream>
#include <string>
#include <iostream>
#include "level.h"

using namespace std;

namespace Tmpl8
{
	void level::init(int levelNum)
	{
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
				std::cout << tp << std::endl;
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

	void level::update(Surface* screen)
	{
		for (int i = 0; i <= wallVec.size() - 1; i++)
		{
			screen->Box(wallVec[i].getPointA().x, wallVec[i].getPointA().y, wallVec[i].getPointB().x, wallVec[i].getPointB().y, 0xfafafa);
		}
	}

	void level::reset()
	{
		wallVec.clear();
	}
}