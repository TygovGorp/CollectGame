#include "LOS.h"
#include <iostream>
#include <thread>

namespace Tmpl8
{
	void LOS::init(vec2 playerLoc)
	{
		//based on https://github.com/user-simon/2D-RayCasting/

		rays.clear();

		//sets the concentration of rays
		const float ray_density = 2000;

		//sets the angle of the rays using the unit circle
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
		//based on https://github.com/user-simon/2D-RayCasting/

		//set variable to the center of the payer
		vec2 playerLoc = { playerPos.x + 30, playerPos.y + 30 };

		//checks if the player has moved since last frame so it only preforms splitDarknessCalculation when it is necessary (when the player moved)
		if (prevPlayerLoc.x != playerLoc.x || prevPlayerLoc.y != playerLoc.y)
		{
			int oneForthOfRaysSize = rays.size() / 4;

			//creates new threads and sets them to preform the function: splitDarknessCalculation
			std::thread darknessThread_1(&LOS::splitDarknessCalculation, this, screen, playerLoc, wallVec, 0, oneForthOfRaysSize);
			std::thread darknessThread_2(&LOS::splitDarknessCalculation, this, screen, playerLoc, wallVec, oneForthOfRaysSize, oneForthOfRaysSize * 2);
			std::thread darknessThread_3(&LOS::splitDarknessCalculation, this, screen, playerLoc, wallVec, oneForthOfRaysSize * 2, oneForthOfRaysSize * 3);
			std::thread darknessThread_4(&LOS::splitDarknessCalculation, this, screen, playerLoc, wallVec, oneForthOfRaysSize * 3, rays.size());

			//waits for the threads to finish their function
			darknessThread_1.join();
			darknessThread_2.join();
			darknessThread_3.join();
			darknessThread_4.join();
		}
		else
		{
			//draws all the darkness parts of the rays in black
			for (int i = 0; i < rays.size(); i++)
			{
				rays[i].draw(screen, 0x000000);
			}
		}
		prevPlayerLoc = playerLoc;
	}

	void LOS::update_light(Surface* screen, vec2 playerPos)
	{
		//draws the light part of the rays (from the player to the first intersection with a wall) in a warm orange
		for (int i = 0; i < rays.size(); i++)
		{
			screen->Line(playerPos.x + 30, playerPos.y + 30, rays[i].getPA().x, rays[i].getPA().y, 0xee9f27);
		}
	}

	void LOS::splitDarknessCalculation(Surface* screen, vec2 playerLoc, std::vector<wall>& wallVec, int start, int end)
	{
		for (int i = start; i < end; i++)
		{

			rays[i].resetPA(playerLoc);
			rays[i].resetPB();
			vec2 nearestWallCol = rays[i].getPB();


			//cycle through every wall and set end point to intersection
			//when an intersection is found, the start point is set to that intersection, meaning the next check will check for walls
			//between the new start point and the end-point. This means the ray will always start at the nearest wall
			for (int j = 0; j < wallVec.size(); j++)
			{
				vec2 wallPointA = wallVec[j].getPointA();
				vec2 wallPointB = wallVec[j].getPointB();

				//holds all the sides of the wall
				vec2 pA[4] = {
					rays[i].calculatePA(wallPointA, vec2(wallPointA.x, wallPointB.y)),
					rays[i].calculatePA(vec2(wallPointA.x, wallPointB.y), wallPointB),
					rays[i].calculatePA(wallPointB, vec2(wallPointB.x, wallPointA.y)),
					rays[i].calculatePA(vec2(wallPointB.x, wallPointA.y), wallPointA)
				};


				//calculates if there has been a intersection and if there is a intersection point set nearestWallCol to it
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
			//sets pointA to the value the nearestWallCol
			rays[i].setPA(nearestWallCol);
			//draws current ray in black
			rays[i].draw(screen, 0x000000);
		}
	}
}