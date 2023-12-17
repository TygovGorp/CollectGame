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

	void player::buildAnimation(Surface* surface)
	{
		playerDownAnim.init(12, "assets/player/player_down_", int(loc.x), int(loc.y), surface);
		playerForwardAnim.init(12, "assets/player/player_forward_", int(loc.x), int(loc.y), surface);
		playerLeftAnim.init(12, "assets/player/player_left_", int(loc.x), int(loc.y), surface);
		playerRightAnim.init(12, "assets/player/player_right_", int(loc.x), int(loc.y), surface);
	}

	void player::update(Surface* surface, float deltaTime)
	{
		totalTimeFromLastFrame += deltaTime;
		if (totalTimeFromLastFrame >= 0.150 && animFrame < 12)
		{
			animFrame++;
			totalTimeFromLastFrame = 0;
		}
		else if (totalTimeFromLastFrame >= 0.150 && animFrame >= 12)
		{
			animFrame = 1;
		}

		switch (facingDirection)
		{
		case 1:
			playerDownAnim.update(animFrame, int(loc.x), int(loc.y), 60, 60, surface);
			break;
		case 2:
			playerForwardAnim.update(animFrame, int(loc.x), int(loc.y), 60, 60, surface);
			break;
		case 3:
			playerLeftAnim.update(animFrame, int(loc.x), int(loc.y), 60, 60, surface);
			break;
		case 4:
			playerRightAnim.update(animFrame, int(loc.x), int(loc.y), 60, 60, surface);
			break;
		default:
			break;
		}
		move(change, deltaTime);
	}

	void player::moveWithInputs(int key)
	{
		//player movement with WASD and the arrow keys
		switch (key)
		{
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			facingDirection = 2;
			change.y = -1.0f;
			break;
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			facingDirection = 1;
			change.y = 1.0f;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			facingDirection = 3;
			change.x = -1.0f;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			facingDirection = 4;
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
		if (loc.y + 60 > screenHight) loc.y = ScreenHeight - 60;
		if (loc.y < 0) loc.y = 0;
		if (loc.x + 60 > screenHight) loc.x = ScreenHeight - 60;
		if (loc.x < 0) loc.x = 0;
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