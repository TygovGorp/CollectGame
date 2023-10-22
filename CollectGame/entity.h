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

		void update();

		void move(int xDifference, int yDifference);

		void setHP(int hp) { HP = hp; };
		void setDMG(int dmg) { DMG = dmg; };
		void setLoc(vec2 Loc) { loc = Loc; };
		void setLoc(int x, int y) { 
			loc.x = x; 
			loc.y = y; 
		};

		int getHP() { return HP; };
		int getDMG() { return DMG; };
		vec2 getLoc() { return loc; };

	protected:
		int HP = 3;
		int DMG = 1;
		animation entityAnimation;
	};
}

