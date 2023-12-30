#pragma once
#include "template.h"
#include  "base.h"

namespace Tmpl8
{
	class object : public base
	{
	public:
		object();
		object(vec2 LOC);
		object(int LOCx, int LOCy);
	
		void setLoc(vec2 LOC);
		void setLoc(int LOCx, int LOCy);

		vec2 getLoc() { return loc; };
	};
}
