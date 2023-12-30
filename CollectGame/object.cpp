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
		loc.x = static_cast<float>(LOCx);
		loc.y = static_cast<float>(LOCy);
	}

	void object::setLoc(vec2 LOC)
	{
		loc = LOC;
	}
	void object::setLoc(int LOCx, int LOCy)
	{
		loc.x = static_cast<float>(LOCx);
		loc.y = static_cast<float>(LOCy);
	}
}