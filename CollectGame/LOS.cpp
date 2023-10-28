#include "LOS.h"
#include <cmath>

namespace Tmpl8
{
	void LOS::init()
	{
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
				const vec2 lineAstart = wallPointA;
				const vec2 lineAend = { wallPointA.x, wallPointB.y };

				const vec2 lineBstart = lineAend;
				const vec2 lineBend = wallPointB;

				const vec2 lineCstart = wallPointB;
				const vec2 lineCend = { wallPointB.x, wallPointA.y };

				const vec2 lineDstart = lineCend;
				const vec2 lineDend = wallPointA;

				for (int n = 0; n < 4; n++)
				{
					switch (n)
					{
					case 0:
						rays[i].calclateHit(lineAstart, lineAend, playerLoc);
						break;
					case 1:
						rays[i].calclateHit(lineBstart, lineBend, playerLoc);
						break;
					case 2:
						rays[i].calclateHit(lineCstart, lineCend, playerLoc);
						break;
					case 3:
						rays[i].calclateHit(lineDstart, lineDend, playerLoc);
						break;
					default:
						break;
					}
				}
			}
			screen->Line(playerLoc.x, playerLoc.y, rays[i].getPB().x, rays[i].getPB().y, 0xee9f27); //0xee9f27
		}
		
	}
}