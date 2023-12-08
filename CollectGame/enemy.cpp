#include "enemy.h"
#include <iostream>
#include <math.h>

namespace Tmpl8
{
	void enemy::init(vector<vec2> points, Surface* screen)
	{
		targets = points;
		loc = points[0];
		enemyAnim.init(1, "assets/temp_Enemy.png", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
	}

	void enemy::setOrientation(Surface* screen)
	{
		if (prevOrientation != orientation)
		{
			switch (orientation)
			{
			case 1:
				enemyAnim.init(1, "assets/temp_Enemy_240.png", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
				break;
			case 2:
				enemyAnim.init(1, "assets/temp_Enemy.png", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
				break;
			case 3:
				enemyAnim.init(1, "assets/temp_Enemy_90.png", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
				break;
			case 4:
				enemyAnim.init(1, "assets/temp_Enemy_180.png", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
				break;
			}
		}
	}

	void enemy::movement(float deltaTime)
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
						move(vec2(-1,0), deltaTime);
						orientation = 1; 
						playerDetectionRay.init(vec2(cos(PI), sin(PI)), loc + 30);
					}
					else
					{
						move(vec2(1, 0), deltaTime);
						orientation = 3;
						playerDetectionRay.init(vec2(cos(PI * 2), sin(PI * 2)), loc + 30);
					}

				}
				else if (loc.y - targets[latestAchievedTarget].y != 0)
				{
					if (loc.y - targets[latestAchievedTarget].y > 0)
					{
						move(vec2(0,-1), deltaTime);
						orientation = 2;
						playerDetectionRay.init(vec2(static_cast<float>(cos(PI * 1.5)), static_cast<float>(sin(PI * 1.5))), loc + 30);
					}
					else
					{
						move(vec2(0, 1), deltaTime);
						orientation = 4;
						playerDetectionRay.init(vec2(static_cast<float>(cos(PI * 0.5)), static_cast<float>(sin(PI * 0.5))), loc + 30);
					}
				}
			}
		}
	}

	void enemy::update(Surface* screen, player& Player, std::vector<wall>& wallVec, float deltaTime)
	{
		prevOrientation = orientation;

		movement(deltaTime);
		setOrientation(screen);

		colInst.rayWallCol(loc + 30, playerDetectionRay, wallVec);

		if (colInst.AABB(Player.getLoc(), Player.getLoc() + 60, loc, vec2(playerDetectionRay.getPB().x, playerDetectionRay.getPB().y)) && Player.getSpotState() != true)
		{
			Player.setSpotState(true);
		}
		enemyAnim.update(1, static_cast<int>(loc.x), static_cast<int>(loc.y), 60, 60, screen);

		playerDetectionRay.draw(screen, 0xFFFFFF);
	}
}