#include "LOS.h"
#include <iostream>

namespace Tmpl8
{
	void LOS::init(vec2 playerLoc)
	{
		//based on https://github.com/user-simon/2D-RayCasting/
		rays.clear();

		const float ray_density = 1000;

		const float step = 1.f / ray_density;
		for (float a = 0; a < PI * 2; a += step)
		{
			const float x = cos(a);
			const float y = sin(a);
			rays.push_back(ray(vec2(x, y), playerLoc));
		}
	}

	void LOS::update(Surface* screen, vec2 playerPos, std::vector<wall> wallVec)
	{
		////based on https://github.com/user-simon/2D-RayCasting/

		vec2 playerLoc = { playerPos.x + 30, playerPos.y + 30 };
		//for (int i = 0; i < rays.size(); i++)
		//{
		//	colInst.rayWallCol(playerLoc, rays[i], wallVec);
		//	vector<vec2> allPointsOnRay = rays[i].getAllPointOnRay(playerLoc);
		//	for (int j = 0; j < allPointsOnRay.size(); j++)
		//	{
		//		screen->Plot(allPointsOnRay[j].x, allPointsOnRay[j].y, 0xee9f27);//0xee9f27
		//	}
		//	//rays[i].draw(playerLoc, screen, 0xee9f27);//0xee9f27
		//}

		

		for (int i = 0; i < rays.size(); i++)
		{
			rays[i].update(playerLoc);
			rays[i].resetPB();
			vec2 nearestWallCol = rays[i].getPB();


			// Cycle through every wall and set end point to intersection
			// When an intersection is found, the end-point is set to that intersection, meaning the next check will check for walls
			// between mouse and the new end-point. This means the ray will always go to the nearest wall
			//for (int j = 0; j < wallVec.size(); j++)
			//{
			//	vec2 wallPointA = wallVec[j].getPointA();
			//	vec2 wallPointB = wallVec[j].getPointB();
			//
			//	// Calculate ray end-point
			//	const vec2 cornerA = wallPointA;
			//	const vec2 cornerB = { wallPointA.x, wallPointB.y };
			//	const vec2 cornerC = wallPointB;
			//	const vec2 cornerD = { wallPointB.x, wallPointA.y };
			//
			//	vec2 pA1 = rays[i].calculatePA(cornerA, cornerB);
			//	vec2 pA2 = rays[i].calculatePA(cornerB, cornerC);
			//	vec2 pA3 = rays[i].calculatePA(cornerC, cornerD);
			//	vec2 pA4 = rays[i].calculatePA(cornerD, cornerA);
			//
			//	//calculate hit on walls
			//	if (sqrt(pow((rays[i].getPA().x - pA1.x), 2) + pow((rays[i].getPA().y - pA1.y), 2)) < sqrt(pow((rays[i].getPA().x - nearestWallCol.x), 2) + pow((rays[i].getPA().y - nearestWallCol.y), 2)))
			//	{
			//		nearestWallCol = pA1;
			//	}
			//	if (sqrt(pow((rays[i].getPA().x - pA2.x), 2) + pow((rays[i].getPA().y - pA2.y), 2)) < sqrt(pow((rays[i].getPA().x - nearestWallCol.x), 2) + pow((rays[i].getPA().y - nearestWallCol.y), 2)))
			//	{
			//		nearestWallCol = pA2;
			//	}
			//	if (sqrt(pow((rays[i].getPA().x - pA3.x), 3) + pow((rays[i].getPA().y - pA3.y), 3)) < sqrt(pow((rays[i].getPA().x - nearestWallCol.x), 3) + pow((rays[i].getPA().y - nearestWallCol.y), 3)))
			//	{
			//		nearestWallCol = pA3;
			//	}
			//	if (sqrt(pow((rays[i].getPA().x - pA4.x), 2) + pow((rays[i].getPA().y - pA4.y), 2)) < sqrt(pow((rays[i].getPA().x - nearestWallCol.x), 2) + pow((rays[i].getPA().y - nearestWallCol.y), 2)))
			//	{
			//		nearestWallCol = pA4;
			//	}
			//}
			rays[i].draw(screen, 0xee9f27); //0xee9f27
		}
	}
}