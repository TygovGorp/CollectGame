#include "enemy.h"
#include <iostream>
#include <math.h>

namespace Tmpl8
{
	void enemy::init(vector<vec2> points, Surface* screen)
	{
		targets = points;
		loc = points[0];
		enemyAnim[0].init(3, "assets/enemy/enemy_left_", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
		enemyAnim[1].init(4, "assets/enemy/enemy_up_", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
		enemyAnim[2].init(3, "assets//enemy/enemy_right_", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
		enemyAnim[3].init(4, "assets/enemy/enemy_down_", static_cast<int>(loc.x), static_cast<int>(loc.y), screen);
	}

	void enemy::movement(float deltaTime)
	{
		
		
		//	if location == next target
		//		latestAchievedTarget++
		//if targets != 0
		if (targets.size() != 1)
		{
			//set next target to 0 if latestAchievedTarget is equal to number of targets
			if (targets.size() == latestAchievedTarget) latestAchievedTarget = 0;

			//set latestAchievedTarget to latestAchievedTarget + 1 if location is equal to latestAchievedTarget
			if ((loc.x == targets[latestAchievedTarget].x &&
				loc.y == targets[latestAchievedTarget].y) || std::hypot(loc.x - targets[latestAchievedTarget].x, loc.y - targets[latestAchievedTarget].y) < speed * deltaTime * 1.9f)
			{
				loc = targets[latestAchievedTarget];
				latestAchievedTarget++;
			}
			
			//move in direction of next target
			else
			{
				if (loc.x - targets[latestAchievedTarget].x != 0)
				{
					if (loc.x - targets[latestAchievedTarget].x > 0)
					{
						move(vec2(-1,0), deltaTime);
						orientation = 0; 
						playerDetectionRay.init(vec2(cos(PI), sin(PI)), loc + 30);
					}

					else
					{
						move(vec2(1, 0), deltaTime);
						orientation = 2;
						playerDetectionRay.init(vec2(cos(PI * 2), sin(PI * 2)), loc + 30);
					}

				}

				else if (loc.y - targets[latestAchievedTarget].y != 0)
				{
					if (loc.y - targets[latestAchievedTarget].y > 0)
					{
						move(vec2(0,-1), deltaTime);
						orientation = 1;
						playerDetectionRay.init(vec2(static_cast<float>(cos(PI * 1.5)), static_cast<float>(sin(PI * 1.5))), loc + 30);
					}

					else
					{
						move(vec2(0, 1), deltaTime);
						orientation = 3;
						playerDetectionRay.init(vec2(static_cast<float>(cos(PI * 0.5)), static_cast<float>(sin(PI * 0.5))), loc + 30);
					}
				}
			}
		}
	}

	void enemy::update(Surface* screen, player& Player, std::vector<wall>& wallVec, float deltaTime)
	{

		movement(deltaTime);

		totalTimeFromLastFrame += deltaTime;

		//update animation depending on the orientation
		if (orientation == 0 || orientation == 2)
		{
			if (totalTimeFromLastFrame >= 0.150 && animFrame < 3)
			{
				animFrame++;
				totalTimeFromLastFrame = 0;
			}
			else if ((animFrame >= 3))
			{
				totalTimeFromLastFrame = 0;
				animFrame = 1;
			}
			enemyAnim[orientation].update(animFrame, static_cast<int>(loc.x), static_cast<int>(loc.y), 60, 60, screen);
		}
		else
		{
			if (totalTimeFromLastFrame >= 0.150 && animFrame < 4)
			{
				animFrame++;
				totalTimeFromLastFrame = 0;
			}
			else if ((animFrame >= 4))
			{
				totalTimeFromLastFrame = 0;
				animFrame = 1;
			}
			enemyAnim[orientation].update(animFrame, static_cast<int>(loc.x), static_cast<int>(loc.y), 60, 60, screen);
		}
		

		colInst.rayWallCol(loc + 30, playerDetectionRay, wallVec);

		if (colInst.AABB(Player.getLoc(), Player.getLoc() + 60, loc, vec2(playerDetectionRay.getPB().x, playerDetectionRay.getPB().y)) && Player.getSpotState() != true)
		{
			Player.setSpotState(true);
		}

		playerDetectionRay.draw(screen, 0xFFFFFF);
	}
}