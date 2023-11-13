#pragma once
#include "entity.h"
#include "animation.h"
#include <vector>
namespace Tmpl8
{
	class enemy : public entity
	{
	public:
		void init(vector<vec2> points, Surface* screen);
		void update(Surface* screen);

		void setTargets(std::vector<vec2> trgts) { targets = trgts; }
	private:
		std::vector<vec2> targets;
		animation enemyAnim;
		int latestAchievedTarget = 0;
	};
}

