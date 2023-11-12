#include "enemy.h"

namespace Tmpl8
{
	void enemy::init(vector<vec2> points)
	{
		targets = points;
		loc = points[0];
	}
	void enemy::update(Surface* screen)
	{
		//if targets != 0
		//	move in direction of next target
		//	if location == next target
		//		latestAchievedTarget++

		if (targets.size() != 0)
		{
			int xDif = 0;
			loc.x - targets[latestAchievedTarget].x >= 0 ? xDif = loc.x - targets[latestAchievedTarget].x : xDif = -(loc.x - targets[latestAchievedTarget].x);

			int yDif = 0;
			loc.y - targets[latestAchievedTarget].y >= 0 ? yDif = loc.y - targets[latestAchievedTarget].y : yDif = -(loc.y - targets[latestAchievedTarget].y);
			move(xDif, yDif);

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
	}
}