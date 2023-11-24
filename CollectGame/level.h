#pragma once
#include <vector>
#include "wall.h"
#include "trap.h"
#include "enemy.h"

namespace Tmpl8
{
	class level
	{
	public:
		void init(int levelNum, int difficulty, Surface* ScreenSurface);
		void update(Surface* screen, player& Player);

		vec2 getWillLoc();
		vec2 getPlayerStartLoc();
		std::vector<wall> getWallVec();
		std::vector<trap> getTrapVec();
		std::vector<enemy> getEnemyVec();

		void reset();
	private:
		Surface* screen;
		std::vector<wall> wallVec;
		std::vector<trap> trapVec;
		std::vector<enemy> enemyVec;
		vec2 willLoc;
		vec2 playerStartLoc;
	};
}

