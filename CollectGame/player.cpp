#include "player.h"
#include <iostream>
#include <SDL_scancode.h>

namespace Tmpl8
{
	void player::init(int numOfTraps)
	{
		for (int i = 0; i < numOfTraps; i++) hittingATrap.push_back(false);
	}

	void player::buildAnimation(Surface* surface)
	{
		playerAnim[0].init(1, "assets/player/player_idle.png", int(loc.x), int(loc.y), surface);
		playerAnim[1].init(12, "assets/player/player_down_", int(loc.x), int(loc.y), surface);
		playerAnim[2].init(12, "assets/player/player_forward_", int(loc.x), int(loc.y), surface);
		playerAnim[3].init(12, "assets/player/player_left_", int(loc.x), int(loc.y), surface);
		playerAnim[4].init(12, "assets/player/player_right_", int(loc.x), int(loc.y), surface);
	}

	void player::update(Surface* surface, float deltaTime)
	{
		//set change and orientation
		lastChangeLoc = change;

		//y-axis
		if (keyPressed[0] == true || keyPressed[1] == true) 
		{
			if (keyPressed[0] == true)//down
			{
				facingDirection = 1;
				change.y = 1.0f;
			}
			if (keyPressed[1] == true) //up
			{
				facingDirection = 2;
				change.y = -1.0f;
			}
		}
		else { change.y = 0; }
		//x-axis
		if (keyPressed[2] == true || keyPressed[3] == true)
		{
			if (keyPressed[2] == true) //left
			{
				facingDirection = 3;
				change.x = -1.0f;
			}
			if (keyPressed[3] == true) //right
			{
				facingDirection = 4;
				change.x = 1.0f;
			}
		}
		else { change.x = 0; }

		//if no buttons are pressed set direction to idle
		if (keyPressed[0] == false && keyPressed[1] == false && keyPressed[2] == false && keyPressed[3] == false) facingDirection = 0;

		//update animation
		totalTimeFromLastFrame += deltaTime;
		if (totalTimeFromLastFrame >= 0.150 && animFrame < 12)
		{
			animFrame++;
			totalTimeFromLastFrame = 0;
		}
		else if ((totalTimeFromLastFrame >= 0.150 && animFrame >= 12))
		{
			totalTimeFromLastFrame = 0;
			animFrame = 1;
		}
		if(facingDirection == 0) animFrame = 1;
		
		playerAnim[facingDirection].update(animFrame, int(loc.x), int(loc.y), 60, 60, surface);


		//move player
		move(change, deltaTime);
	}

	void player::moveWithInputs(int key)
	{
		//player movement with WASD and the arrow keys
		switch (key)
		{
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			keyPressed[0] = true;
			break;
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			keyPressed[1] = true;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			keyPressed[2] = true;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			keyPressed[3] = true;
			break;
		default:			
			break;
		}

	}

	void player::resetInputs(int key)
	{
		//reset inputs
		switch (key)
		{
		case SDL_SCANCODE_S:
		case SDL_SCANCODE_DOWN:
			keyPressed[0] = false;
			break;
		case SDL_SCANCODE_W:
		case SDL_SCANCODE_UP:
			keyPressed[1] = false;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			keyPressed[2] = false;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			keyPressed[3] = false;
			break;
		}
	}

	void player::checkCollisionWall(std::vector<wall> wallVec, float deltaTime)
	{
		//checks if the player collides with a wall and respond accordingly
		for (int i = 0; i < wallVec.size() - 1; i++)
		{
			if (Col.AABB(vec2(loc.x + 7, loc.y), vec2(loc.x + 52, loc.y + 59), wallVec[i].getPointA(), wallVec[i].getPointB()))
			{
				move(-change, deltaTime);
			}
			if (Col.AABB(vec2(loc.x + 7, loc.y), vec2(loc.x + 52, loc.y + 59), wallVec[i].getPointA(), wallVec[i].getPointB()))
			{
				move(-lastChangeLoc, deltaTime);
			}
		}
	}
	void player::checkCollisionScreenBounds(int screenHight, int screenWidth, float deltaTime)
	{
		//checks if the player collides with a screen border and respond accordingly
		if (loc.y + 60 > screenHight) loc.y = ScreenHeight - 60;
		if (loc.y < 0) loc.y = 0;
		if (loc.x + 52 > screenWidth) loc.x = screenWidth - 52;
		if (loc.x + 7 < 0) loc.x = 0 - 7;
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