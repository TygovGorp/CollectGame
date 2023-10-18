#pragma once
#include "template.h"
#include  "base.h"

namespace Tmpl8
{
	class object : public base
	{
	public:
		object();
		object(vec2 LOC, vec2 pointA, vec2 pointB);
		object(int LOCx, int LOCy, int Ax, int Ay, int Bx, int By);
	
		void setLoc(vec2 LOC);
		void setLoc(int LOCx, int LOCy);

		void setCollisionBox(vec2 A, vec2 B);
		void setCollisionBox(int Ax, int Ay, int Bx, int By);

		vec2 getLoc() { return loc; };
		vec2 getCollisionBox(int pointNumber) { return collisionBox[pointNumber]; };

	protected:
		vec2 collisionBox[2];
	};
}
