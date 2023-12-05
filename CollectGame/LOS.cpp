#include "LOS.h"
#include <iostream>

namespace Tmpl8
{
	void LOS::init(vec2 playerLoc)
	{
		//based on https://github.com/user-simon/2D-RayCasting/
		rays.clear();

		const float ray_density = 2000;

		const float step = 1.f / ray_density;
		for (float a = 0; a < PI * 2; a += step)
		{
			const float x = cos(a);
			const float y = sin(a);
			rays.push_back(ray(vec2(x, y), playerLoc));
		}
	}

	void LOS::update_darkness(Surface* screen, vec2 playerPos, std::vector<wall>& wallVec)
	{
		////based on https://github.com/user-simon/2D-RayCasting/

		vec2 playerLoc = { playerPos.x + 30, playerPos.y + 30 };
		
		for (int i = 0; i < rays.size(); i++)
		{
			rays[i].resetPA(playerLoc);
			rays[i].resetPB();
			vec2 nearestWallCol = rays[i].getPB();

			// Cycle through every wall and set end point to intersection
			// When an intersection is found, the start point is set to that intersection, meaning the next check will check for walls
			// between the new start point and the end-point. This means the ray will always start at the nearest wall
			for (int j = 0; j < wallVec.size(); j++)
			{
				vec2 wallPointA = wallVec[j].getPointA();
				vec2 wallPointB = wallVec[j].getPointB();
			
				// Calculate ray end-point
				vec2 pA[4] = {
					rays[i].calculatePA(wallPointA, vec2( wallPointA.x, wallPointB.y) ),
					rays[i].calculatePA(vec2(wallPointA.x, wallPointB.y), wallPointB),
					rays[i].calculatePA(wallPointB, vec2(wallPointB.x, wallPointA.y)),
					rays[i].calculatePA(vec2(wallPointB.x, wallPointA.y), wallPointA)
				};

				for (int q = 0; q < 4; q++)
				{
					float a1 = (rays[i].getPA().x - pA[q].x);
					float b1 = (rays[i].getPA().y - pA[q].y);

					float a2 = (rays[i].getPA().x - nearestWallCol.x);
					float b2 = (rays[i].getPA().y - nearestWallCol.y);

					if ((a1 * a1) + (b1 * b1) < (a2 * a2) + (b2 * b2))
					{
						nearestWallCol = pA[q];
					}
				}
			}
			rays[i].setPA(nearestWallCol);
			rays[i].draw(screen, 0x000000); 
		}
	}

	void LOS::update_light(Surface* screen, vec2 playerPos)
	{
		for (int i = 0; i < rays.size(); i++)
		{
			screen->Line(playerPos.x + 30, playerPos.y + 30, rays[i].getPA().x, rays[i].getPA().y, 0xee9f27);
		}
	}
}