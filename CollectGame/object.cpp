#include "object.h"

namespace Tmpl8
{
	object::object()
	{
		loc = { 1, 1 };
	}
	object::object(vec2 LOC)
	{
		loc = LOC;
	}
	object::object(int LOCx, int LOCy)
	{
		loc.x = LOCx;
		loc.y = LOCy;
	}

	void object::setLoc(vec2 LOC)
	{
		loc = LOC;
	}
	void object::setLoc(int LOCx, int LOCy)
	{
		loc.x = LOCx;
		loc.y = LOCy;
	}
}