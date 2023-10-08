#include "entity.h"
namespace Tmpl8
{
	entity::entity()
	{
		HP = 10;
		DMG = 5;
		loc.x = 0;
		loc.y = 0;
	}
	entity::entity(int hp, int dmg, point LOC)
	{
		HP = hp;
		DMG = dmg;
		loc = LOC;
	}
	entity::entity(int hp, int dmg, int xloc, int yloc)
	{
		HP = hp;
		DMG = dmg;
		loc.x = xloc;
		loc.y = yloc;
	}

	void entity::build(int hp, int dmg, point LOC)
	{
		HP = hp;
		DMG = dmg;
		loc = LOC;
	}
	void entity::build(int hp, int dmg, int xloc, int yloc)
	{
		HP = hp;
		DMG = dmg;
		loc.x = xloc;
		loc.y = yloc;
	}
}