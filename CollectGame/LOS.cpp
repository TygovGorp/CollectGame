#include "LOS.h"

namespace Tmpl8
{
	void LOS::init()
	{
		rays.clear();

		const float ray_density = 1000;

		const float step = 1.f / ray_density;
		for (float a = 0; a < PI * 2; a += step)
		{
			const float x = cos(a);
			const float y = sin(a);
			rays.push_back(ray(vec2(x, y)));
		}
	}

	void LOS::update(Surface* screen, vec2 playerPos, std::vector<wall> wallVec)
	{
		vec2 playerLoc = { playerPos.x + 30, playerPos.y + 30 };
		for (int i = 0; i < rays.size(); i++)
		{
			// Set ray end-point to default
			rays[i].setPoints(playerLoc);

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
				rays[i].calclateHit(cornerA, cornerB, playerLoc);
				rays[i].calclateHit(cornerB, cornerC, playerLoc);
				rays[i].calclateHit(cornerC, cornerD, playerLoc);
				rays[i].calclateHit(cornerD, cornerA, playerLoc);

			}
			screen->Line(playerLoc.x, playerLoc.y, rays[i].getPB().x, rays[i].getPB().y, 0xee9f27); //0xee9f27
		}
	}
}