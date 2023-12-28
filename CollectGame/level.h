#pragma once
#include <vector>
#include "wall.h"
#include "trap.h"
#include "enemy.h"
#include "collision.h"

namespace Tmpl8
{
	class level
	{
	public:
		//reads level_levelNum.txt file for level info and initializes it
		void init(int levelNum, int difficulty, Surface* ScreenSurface);
		//updates the walls, traps and enemy's
		void update(Surface* screen, player& Player, float deltaTime);

		vec2 getWillLoc();
		vec2 getPlayerStartLoc();
		std::vector<wall> getWallVec();
		std::vector<trap> getTrapVec();
		std::vector<enemy> getEnemyVec();

		void reset();
	private:
		collision collInst;
		Surface* screen;
		std::vector<wall> wallVec;
		std::vector<trap> trapVec;
		std::vector<enemy> enemyVec;
		vec2 willLoc;
		vec2 playerStartLoc;
	};
}

