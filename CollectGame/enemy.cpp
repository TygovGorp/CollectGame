#include "enemy.h"

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

		if (targets.size() != 1)
		{
			move(loc.x - targets[latestAchievedTarget].x, loc.y - targets[latestAchievedTarget].y);

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
		}
		enemyAnim.update(1, loc.x, loc.y, 60, 60, screen);
	}
}