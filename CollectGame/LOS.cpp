#include "LOS.h"

namespace Tmpl8
{
	void LOS::init(std::vector<wall> wallVec, player Player)
	{
		rays.clear();

		for (float i = 0; i < wallVec.size(); i++)
		{
			//y = sc * x + b
			const float sc = (Player.getLoc().y - wallVec[i].getPointA().y) / (Player.getLoc().x - wallVec[i].getPointA().x);
			float b = 0;
			sc* wallVec[i].getPointA().x < wallVec[i].getPointA().y ? b = wallVec[i].getPointA().y - sc * wallVec[i].getPointA().x : b = sc * wallVec[i].getPointA().x - wallVec[i].getPointA().y;

			rays.push_back(ray(sc, b));
		}
	}

	void LOS::update(Surface* screen, vec2 playerPos, std::vector<wall> wallVec)
	{
		vec2 playerLoc = { playerPos.x + 30, playerPos.y + 30 };
		for (int i = 0; i < rays.size(); i++)
		{
			// Cycle through every wall and set end point to intersection
			// When an intersection is found, the end-point is set to that intersection, meaning the next check will check for walls
			// between mouse and the new end-point. This means the ray will always go to the nearest wall
			for (int j = 0; j < wallVec.size(); j++)
			{
				vec2 wallPointA = wallVec[j].getPointA();
				vec2 wallPointB = wallVec[j].getPointB();
				
				// Calculate ray end-point
				const vec2 cornerA = wallPointA;
				const vec2 cornerB = { wallPointA.x, wallPointB.y };
				const vec2 cornerC = wallPointB;
				const vec2 cornerD = { wallPointB.x, wallPointA.y };

				//calculate hit on walls
				rays[i].calclateHit(cornerA, cornerB);
				rays[i].calclateHit(cornerB, cornerC);
				rays[i].calclateHit(cornerC, cornerD);
				rays[i].calclateHit(cornerD, cornerA);

			}
			screen->Line(playerLoc.x, playerLoc.y, rays[i].getPB().x, rays[i].getPB().y, 0xee9f27);
		}
		
	}
}