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
			change = { 0 , -10 };
			break;
			//a
		case 4:
			change = { -10 , 0 };
			break;
			//s
		case 22:
			change = { 0 , 10 };
			break;
			//d
		case 7:
			change = { 10 , 0 };
			break;
			//arrow keys
			//up
		case 82:
			change = { 0 , -10 };
			break;
			//left
		case 80:
			change = { -10 , 0 };
			break;
			//down
		case 81:
			change = { 0 , 10 };
			break;
			//right
		case 79:
			change = { 10 , 0 };
			break;
		default:
			break;
		}

		lastChangeLoc = change;
		move(change.x, change.y);
	}

	void player::checkCollisionWall(std::vector<wall> wallVec)
	{
		for (int i = 0; i < wallVec.size() - 1; i++)
		{
			if (Col.AABB(vec2(loc.x + 1, loc.y + 1), vec2(loc.x + 59, loc.y + 59), wallVec[i].getPointA(), wallVec[i].getPointB()))
			{
				move(-lastChangeLoc.x, -lastChangeLoc.y);
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