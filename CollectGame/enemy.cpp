#include "enemy.h"
#include <iostream>

namespace Tmpl8
{
	void enemy::init(vector<vec2> points, Surface* screen)
	{
		targets = points;
		loc = points[0];
		enemyAnim.init(1, "assets/temp_Enemy.png", loc.x, loc.y, screen);
	}
	void enemy::update(Surface* screen)
	{
		//if targets != 0
		//	move in direction of next target
		//	if location == next target
		//		latestAchievedTarget++

		prevOrientation = orientation;

		if (targets.size() != 1)
		{
			if (targets.size() == latestAchievedTarget)
			{
				latestAchievedTarget = 0;
			}
			if (loc.x == targets[latestAchievedTarget].x &&
				loc.y == targets[latestAchievedTarget].y)
			{
				if (latestAchievedTarget != targets.size())
				{
					latestAchievedTarget++;
				}
				else
				{
					latestAchievedTarget = 0;
				}
			}
			else
			{
				if (loc.x - targets[latestAchievedTarget].x != 0)
				{
					if (loc.x - targets[latestAchievedTarget].x > 0)
					{
						move(-movementSpeed, 0);
						orientation = 1;
					}
					else
					{
						move(movementSpeed, 0);
						orientation = 3;
					}

				}
				else if (loc.y - targets[latestAchievedTarget].y != 0)
				{
					if (loc.y - targets[latestAchievedTarget].y > 0)
					{
						move(0, -movementSpeed);
						orientation = 2;
					}
					else
					{
						move(0, movementSpeed);
						orientation = 4;
					}

				}
			}
		}
		if (prevOrientation != orientation)
		{
			switch (orientation)
			{
			case 1:
				enemyAnim.init(1, "assets/temp_Enemy_240.png", loc.x, loc.y, screen);
				break;
			case 2:
				enemyAnim.init(1, "assets/temp_Enemy.png", loc.x, loc.y, screen);
				break;
			case 3:
				enemyAnim.init(1, "assets/temp_Enemy_90.png", loc.x, loc.y, screen);
				break;
			case 4:
				enemyAnim.init(1, "assets/temp_Enemy_180.png", loc.x, loc.y, screen);
				break;
			}
		}
		enemyAnim.update(1, loc.x, loc.y, 60, 60, screen);
	}
}