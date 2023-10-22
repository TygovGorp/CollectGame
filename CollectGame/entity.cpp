#include "entity.h"
namespace Tmpl8
{
	entity::entity()
	{
		HP = 3;
		DMG = 1;
		loc.x = 0;
		loc.y = 0;
	}
	entity::entity(int hp, int dmg, vec2 LOC)
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

	void entity::buildAnimation(Surface* surface, int numofframes, char* filename)
	{
		entityAnimation.init(numofframes, filename, int(loc.x), int(loc.y), surface);
	}
	void entity::build(int hp, int dmg, vec2 LOC)
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

	void entity::update()
	{
		entityAnimation.update(1, int(loc.x), int(loc.y), 60,60);
	}

	void entity::move(int xDifference, int yDifference)
	{
		loc.x += xDifference;
		loc.y += yDifference;
	}
}