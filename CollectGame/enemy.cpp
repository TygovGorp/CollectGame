#include "enemy.h"
#include <iostream>
#include <math.h>

namespace Tmpl8
{
	void enemy::init(vector<vec2> points, Surface* screen)
	{
		targets = points;
		loc = points[0];
		enemyAnim.init(1, "assets/temp_Enemy.png", loc.x, loc.y, screen);
	}

	void enemy::setOrientation(Surface* screen)
	{
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
	}

	void enemy::movement()
	{
		//if targets != 0
		//	move in direction of next target
		//	if location == next target
		//		latestAchievedTarget++

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
						playerDetectionRay.init(vec2(cos(PI), sin(PI)));
					}
					else
					{
						move(movementSpeed, 0);
						orientation = 3;
						playerDetectionRay.init(vec2(cos(PI * 2), sin(PI * 2)));
					}

				}
				else if (loc.y - targets[latestAchievedTarget].y != 0)
				{
					if (loc.y - targets[latestAchievedTarget].y > 0)
					{
						move(0, -movementSpeed);
						orientation = 2;
						playerDetectionRay.init(vec2(cos(PI * 1.5), sin(PI * 1.5)));
					}
					else
					{
						move(0, movementSpeed);
						orientation = 4;
						playerDetectionRay.init(vec2(cos(PI * 0.5), sin(PI * 0.5)));
					}
				}
			}
		}
	}

	void enemy::update(Surface* screen, player Player, std::vector<wall>& wallVec)
	{
		prevOrientation = orientation;

		movement();
		setOrientation(screen);

		//playerDetectionRay.setPoints(loc + 30);

		colInst.rayWallCol(loc + 30, playerDetectionRay, wallVec);

		if (colInst.AABB(Player.getLoc(), Player.getLoc() + 60, loc, vec2(playerDetectionRay.getPB().x, playerDetectionRay.getPB().y)))
		{
			std::cout << "spotted" << std::endl;
		}
		enemyAnim.update(1, loc.x, loc.y, 60, 60, screen);
		screen->Line(loc.x + 30, loc.y + 30, playerDetectionRay.getPB().x, playerDetectionRay.getPB().y, 0xFFFFFF);
	}
}