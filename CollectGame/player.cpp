#include "player.h"
#include <iostream>

namespace Tmpl8
{
	void player::moveWithInputs(int key)
	{
		vec2 change = { 0, 0 };
		//player movement with WASD and the arrow keys
		switch (key)
		{
			//w
		case 26:
			change.y = change.y - 10;
			break;
			//a
		case 4:
			change.x = change.x - 10;
			break;
			//s
		case 22:
			change.y = change.y + 10;
			break;
			//d
		case 7:
			change.x = change.x + 10;
			break;
			//arrow keys
			//up
		case 82:
			change.y = change.y - 10;
			break;
			//left
		case 80:
			change.x = change.x - 10;
			break;
			//down
		case 81:
			change.y = change.y + 10;
			break;
			//right
		case 79:
			change.x = change.x + 10;
			break;
		default:
			break;
		}
		secondLastChangeLoc = lastChangeLoc;
		lastChangeLoc = change;
		move(change.x, change.y);
	}

	void player::checkCollisionWall(std::vector<wall> wallVec)
	{
		for (int i = 0; i < wallVec.size() - 1; i++)
		{
			if (Col.AABB(vec2(loc.x, loc.y), vec2(loc.x + 59, loc.y + 59), wallVec[i].getPointA(), wallVec[i].getPointB()))
			{
				move(-lastChangeLoc.x, -lastChangeLoc.y);
			}
			if (Col.AABB(vec2(loc.x, loc.y), vec2(loc.x + 59, loc.y + 59), wallVec[i].getPointA(), wallVec[i].getPointB()))
			{
				move(-secondLastChangeLoc.x, -secondLastChangeLoc.y);
			}
		}
	}
	void player::checkCollisionScreenBounds(int screenHight, int screenWidth)
	{
		//working here
		if (loc.y + 60 > screenHight ||
			loc.y < 0 ||
			loc.x + 60 > screenWidth ||
			loc.x < 0
			)
		{
			move(-lastChangeLoc.x, -lastChangeLoc.y);
		}
	}
}