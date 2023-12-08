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
		void setOrientation(Surface* screen);
		void movement(float deltaTime);
		std::vector<vec2> targets;
		animation enemyAnim;
		ray playerDetectionRay;
		collision colInst;
		int prevOrientation;
		int orientation = 2; //1 = left 2 = forwards 3 = right 4 = backwards
		int latestAchievedTarget = 0;
		int movementSpeed = 2;
	};
}

