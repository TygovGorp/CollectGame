#include <fstream>
#include <string>
#include <iostream>
#include "level.h"

using namespace std;

namespace Tmpl8
{
	void level::init(int levelNum, int difficulty, Surface* ScreenSurface)
	{
		wallVec.clear();
		trapVec.clear();
		enemyVec.clear();

		willLoc = { 0,0 };
		playerStartLoc = { 0,0 };

		screen = ScreenSurface;
		fstream newfile;
		newfile.open("levels/level_" + to_string(difficulty) + "_" + to_string(levelNum) + ".txt", ios::in);

		if (newfile.is_open()) {

			string tp;

			bool nextWillLocation = false;

			bool nextPlayerLocation = false;

			bool nextTrapLocation = false;
			int trapx = 0;

			bool nextEnemyLocation = false;
			vector<vec2> enemyTargets;
			bool nextIsATarget = false;
			int currentTargetNum = 0;

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
					nextPlayerLocation = true;
					counter = 1;
				}
				if (nextPlayerLocation)
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
						nextPlayerLocation = false;
						counter = 0;
						break;
					default:
						break;
					}
					counter++;
				}

				if (tp.find("TrapLocation") != std::string::npos)
				{
					nextTrapLocation = true;
					counter = 1;
				}
				if (nextTrapLocation)
				{
					switch (counter)
					{
					case 1:
						trapVec.push_back(trap());
						break;
					case 2:
						trapx = stoi(tp);
						break;
					case 3:
						trapVec.back().setLoc(trapx, stoi(tp));
						break;
					case 4:
						trapx = stoi(tp);
						break;
					case 5:
						trapVec.back().setPointB(vec2(trapx, stoi(tp)));
						trapVec.back().init(screen);
						nextTrapLocation = false;
						counter = 0;
					default:
						break;
					}
					counter++;
				}

				if (tp.find("EnemyLocation") != std::string::npos)
				{
					nextEnemyLocation = true;
					counter = 1;
				}
				if (nextEnemyLocation)
				{
					if (tp.find("target") != std::string::npos)
					{
						nextIsATarget = true;
						counter = 1;
					}

					if (!nextIsATarget && !(tp.find("EnemyLocation") != std::string::npos))
					{
						enemyVec.push_back(enemy());
						enemyVec.back().init(enemyTargets, screen);
						nextEnemyLocation = false;
						currentTargetNum = 0;
					}

					if (nextIsATarget)
					{
						switch (counter)
						{
						case 1:
							enemyTargets.push_back(vec2());
							break;
						case 2:
							enemyTargets[currentTargetNum].x = stoi(tp);
							break;
						case 3:
							enemyTargets[currentTargetNum].y = stoi(tp);
							nextIsATarget = false;
							currentTargetNum++;
							counter = 0;
							break;
						default:
							break;
						}
						counter++;
					}
				}

				if (!nextWillLocation && !nextPlayerLocation && !nextTrapLocation && !nextEnemyLocation)
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

	void level::update(Surface* screen, player Player)
	{
		for (int i = 0; i < wallVec.size(); i++)
		{
			wallVec[i].update(screen, 0x666666); //0x000000 
		}
		for (int i = 0; i < trapVec.size(); i++)
		{
			trapVec[i].update(screen);
		}
		for (int i = 0; i < enemyVec.size(); i++)
		{
			enemyVec[i].update(screen, Player);
		}
	}

	std::vector<wall> level::getWallVec()
	{
		return wallVec;
	}

	std::vector<trap> level::getTrapVec()
	{
		return trapVec;
	}

	std::vector<enemy> level::getEnemyVec()
	{
		return enemyVec;
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