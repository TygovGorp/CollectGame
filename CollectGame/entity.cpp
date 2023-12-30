#include "entity.h"
namespace Tmpl8
{
	entity::entity()
	{
		totalTimeFromLastFrame = 0.0f;
		HP = 3;
		DMG = 1;
		loc.x = 0;
		loc.y = 0;
	}
	entity::entity(int hp, int dmg, vec2 LOC)
	{
		totalTimeFromLastFrame = 0.0f;
		HP = hp;
		DMG = dmg;
		loc = LOC;
	}
	entity::entity(int hp, int dmg, int xloc, int yloc)
	{
		totalTimeFromLastFrame = 0.0f;
		HP = hp;
		DMG = dmg;
		loc.x = static_cast<float>(xloc);
		loc.y = static_cast<float>(yloc);
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
		loc.x = static_cast<float>(xloc);
		loc.y = static_cast<float>(yloc);

	}

	void entity::update(Surface* surface)
	{
		entityAnimation.update(1, int(loc.x), int(loc.y), 60,60, surface);
	}

	void entity::move(vec2 change, float deltaTime)
	{
		loc += change * static_cast<float>(speed) * deltaTime;
	}
}