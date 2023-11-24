#include "LOS.h"
#include <iostream>

namespace Tmpl8
{
	void LOS::init()
	{
		//based on https://github.com/user-simon/2D-RayCasting/
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
		//based on https://github.com/user-simon/2D-RayCasting/

		vec2 playerLoc = { playerPos.x + 30, playerPos.y + 30 };

		for (int i = 0; i < rays.size(); i++)
		{
			colInst.rayWallCol(playerLoc, rays[i], wallVec);
			rays[i].draw(playerLoc, screen, 0xee9f27);//0xee9f27
		}
	}
}