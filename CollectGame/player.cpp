#include "player.h"
#include <iostream>
#include <SDL_scancode.h>

namespace Tmpl8
{
	void player::init(int numOfTraps)
	{
		for (int i = 0; i < numOfTraps; i++)
		{
			hittingATrap.push_back(false);
		}
	}

	void player::update(Surface* surface, float deltaTime)
	{
		totalTimeFromLastFrame += deltaTime;
		if (totalTimeFromLastFrame >= 0.250 && animFrame < 4)
		{
			animFrame++;
			totalTimeFromLastFrame = 0;
		}
		else if (animFrame >= 4)
		{
			animFrame = 1;
		}
		entityAnimation.update(animFrame, int(loc.x), int(loc.y), 60, 60, surface);
		move(change, deltaTime);
	}

	void player::moveWithInputs(int key)
	{
		//player movement with WASD and the arrow keys
		switch (key)
		{
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			change.y = -1.0f;
			break;
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			change.y = 1.0f;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			change.x = -1.0f;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			change.x = 1.0f;
			break;
		}
		lastChangeLoc = change;
	}

	void player::resetInputs(int key)
	{
		switch (key)
		{
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			change.y = 0.0f;
			break;
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			change.y = 0.0f;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			change.x = 0.0f;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			change.x = 0.0f;
			break;
		}
	}

	void player::checkCollisionWall(std::vector<wall> wallVec, float deltaTime)
	{
		for (int i = 0; i < wallVec.size() - 1; i++)
		{
			if (Col.AABB(vec2(loc.x, loc.y), vec2(loc.x + 59, loc.y + 59), wallVec[i].getPointA(), wallVec[i].getPointB()))
			{
				move(-change, deltaTime);
			}
			if (Col.AABB(vec2(loc.x, loc.y), vec2(loc.x + 59, loc.y + 59), wallVec[i].getPointA(), wallVec[i].getPointB()))
			{
				move(-lastChangeLoc, deltaTime);
			}
		}
	}
	void player::checkCollisionScreenBounds(int screenHight, int screenWidth, float deltaTime)
	{
		if (loc.y + 60 > screenHight ||
			loc.y < 0 ||
			loc.x + 60 > screenWidth ||
			loc.x < 0
			)
		{
			move(-lastChangeLoc, deltaTime);
		}
		if (loc.y + 60 > screenHight ||
			loc.y < 0 ||
			loc.x + 60 > screenWidth ||
			loc.x < 0
			)
		{
			move(-secondLastChangeLoc, deltaTime);
		}
	}

	void player::setHitStateTrap(bool YN, int trapNum)
	{
		hittingATrap[trapNum] = YN;
	}

	bool player::getHitStateTrap(int trapNum)
	{
		return hittingATrap[trapNum];
	}
}