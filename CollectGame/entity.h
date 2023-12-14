#pragma once
#include "surface.h"
#include "template.h"
#include "animation.h"
#include "base.h"
#include <vector>

namespace Tmpl8
{
	using namespace std;
	class entity : public base
	{
	public:
		entity();
		entity(int hp, int dmg, vec2 LOC);
		entity(int hp, int dmg, int xloc, int yloc);

		void buildAnimation(Surface* surface, int numofframes, char* filename);
		void build(int hp, int dmg, vec2 LOC);
		void build(int hp, int dmg, int xloc, int yloc);

		void update(Surface* surface);

		void move(vec2 change, float deltaTime);

		void setHP(int hp) { HP = hp; };
		void setDMG(int dmg) { DMG = dmg; };
		void setLoc(vec2 Loc) { loc = Loc; };
		void setLoc(int x, int y) { 
			loc.x = static_cast<float>(x); 
			loc.y = static_cast<float>(y);
		};

		int getHP() { return HP; };
		int getDMG() { return DMG; };
		vec2 getLoc() { return loc; };

	protected:
		int speed = 50;
		int HP = 3;
		int DMG = 1;
		int animFrame = 1;
		float totalTimeFromLastFrame;
		animation entityAnimation;
	};
}

