#include "LOS.h"

namespace Tmpl8
{
	void LOS::init(std::vector<wall> wallVec, vec2 playerLoc)
	{
		rays.clear();

		for (int i = 0; i < wallVec.size() - 1; i++)
		{
			vec2 midPlayer(playerLoc.x + 30, playerLoc.y + 30);
			rays.push_back(ray(midPlayer, wallVec[i].getPointA()));
			rays.push_back(ray(midPlayer, vec2(wallVec[i].getPointA().x, wallVec[i].getPointB().y)));
			rays.push_back(ray(midPlayer, wallVec[i].getPointB()));
			rays.push_back(ray(midPlayer, vec2(wallVec[i].getPointB().x, wallVec[i].getPointA().y)));
		}
	}
	void LOS::update(Surface* screen, vec2 playerLoc, std::vector<wall> wallVec)
	{
		//https://www.cuemath.com/geometry/intersection-of-two-lines/
		for (int i = 0; i < rays.size() - 1; i++)
		{
			for (int j = 0; j < wallVec.size() - 1; j++)
			{
				rays[i].calculateHit(wallVec[j].getPointA(), vec2(wallVec[j].getPointB().x, wallVec[j].getPointA().y));
				rays[i].calculateHit(vec2(wallVec[j].getPointB().x, wallVec[j].getPointA().y), wallVec[j].getPointB());
				rays[i].calculateHit(wallVec[j].getPointB(), vec2(wallVec[j].getPointA().x, wallVec[j].getPointB().y));
				rays[i].calculateHit(vec2(wallVec[j].getPointA().x, wallVec[j].getPointB().y), wallVec[j].getPointA());
			}
			screen->Line(rays[i].getPA().x, rays[i].getPA().y, rays[i].getPB().x, rays[i].getPB().y, 0xee9f27);
		}
	}
}