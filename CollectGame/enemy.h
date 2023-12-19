#pragma once
#include "entity.h"
#include "animation.h"
#include "ray.h"
#include "collision.h"
#include "player.h"
#include <vector>
namespace Tmpl8
{
	class enemy : public entity
	{
	public:
		void init(vector<vec2> points, Surface* screen);
		void update(Surface* screen, player& Player, std::vector<wall>& wallVec, float deltaTime);

		void setTargets(std::vector<vec2> trgts) { targets = trgts; }
	private:
		void movement(float deltaTime);
		std::vector<vec2> targets;
		
		ray playerDetectionRay;
		collision colInst;
		int orientation = 2; //0 = left 1 = forwards 2 = right 3 = backwards
		int latestAchievedTarget = 0;
		int movementSpeed = 2;
		animation enemyAnim[4];//0 = left 1 = forwards 2 = right 3 = backwards
	};
}

