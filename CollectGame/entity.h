#pragma once
#include "point.h"
#include "surface.h"
namespace Tmpl8
{
	class entity
	{
	public:
		entity();
		entity(int hp, int dmg, point LOC);
		entity(int hp, int dmg, int xloc, int yloc);

		void build(int hp, int dmg, point LOC);
		void build(int hp, int dmg, int xloc, int yloc);

		void update();
	protected:
		int HP;
		int DMG;
		point loc;
		Sprite entitySprite();
	};
}

